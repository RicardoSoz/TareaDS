// Andrea Espinosa Azuela  + Ricardo Solis Zugarazo
// Viernes 23 de Octubre del 2020
// En este c�digo implementaremos los met�dos b�sicos de los arboles binarios y un diccionario basado en el ABB
// Referencias: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html ,http://c.conclase.net/edd/?cap=007c
#include "ABB.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <queue> 

using namespace std;

ABB::ABB() {
	root = NULL;
}

ABB::~ABB() {
}

NodoArbol* ABB::getRoot() {
	return root;
}

void ABB::setRoot(NodoArbol* _root) {
	root = _root;
}

void ABB::Inserta(std::string num) {
	NodoArbol* nuevo = new NodoArbol(num);
	NodoArbol* aux = root;
	NodoArbol* antes = root;

	if (root == NULL)
	{
		root = nuevo;
	}

	else {

		while (aux != NULL && nuevo->getDato() != aux->getDato())
		{
			antes = aux;
			if (aux->getDato() > num)
			{
				aux = aux->getIzquierda();
			}
			else
				aux = aux->getDerecha();
		}

		if (aux != NULL) {
			cout << "Repetido" << endl;
		}
		else {
			if (antes->getDato() > num)
				antes->setIzquierda(nuevo);
			else
				antes->setDerecha(nuevo);
		}
	}
}

void ABB::preorden(NodoArbol* aux)
{
	if (aux != NULL) {
		cout << aux->getDato() << endl;
		preorden(aux->getIzquierda());
		preorden(aux->getDerecha());
	}
}

void ABB::posorden(NodoArbol* aux)
{
	if (aux != NULL) {
		posorden(aux->getIzquierda());
		posorden(aux->getDerecha());
		cout << aux->getDato() << endl;
	}
}

void ABB::inorden(NodoArbol* aux)
{
	if (aux != NULL) {
		inorden(aux->getIzquierda());
		cout << aux->getDato() << endl;
		inorden(aux->getDerecha());
	}
}


int ABB::cuentaInternos(NodoArbol* aux, int cuenta) {
	if (aux != NULL) {
		if (aux->getIzquierda() != NULL || aux->getDerecha() != NULL)
			cuenta++;

		cuenta = cuentaInternos(aux->getIzquierda(), cuenta);
		cuenta = cuentaInternos(aux->getDerecha(), cuenta);
	}
	return cuenta;
}

void ABB::cuentaNodosIH(NodoArbol* aux, int& internos, int& hoja) {
	internos = 0;
	hoja = 0;
	internos = cuentaInternos(aux, internos);
	hoja = cuentaHojas(aux, hoja);
}

int ABB::cuentaNodos(NodoArbol* aux, int cuenta) {
	if (aux != NULL) {
		cuenta++;
		cuenta = cuentaNodos(aux->getIzquierda(), cuenta);
		cuenta = cuentaNodos(aux->getDerecha(), cuenta);
	}
	return cuenta;
}

int ABB::cuentaHojas(NodoArbol* aux, int cuenta) {
	if (aux != NULL) {
		if (aux->getIzquierda() == NULL && aux->getDerecha() == NULL)
			cuenta++;
		cuenta = cuentaHojas(aux->getIzquierda(), cuenta);
		cuenta = cuentaHojas(aux->getDerecha(), cuenta);
	}
	return cuenta;
}

NodoArbol* ABB::borraSinHijos(NodoArbol* antes, NodoArbol* aux) {
	// borra nodos hojas
	// ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
	// SALIDA: nodo padre del nodo que se borro
	if (aux == root)
		return NULL;
	else {
		if (antes->getDerecha() == aux)
			antes->setDerecha(NULL);
		else
			antes->setIzquierda(NULL);
		return antes;
	}
}

NodoArbol* ABB::borraUnHijo(NodoArbol* antes, NodoArbol* aux)
{
	// borra un nodo con un hijo
	// ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
	// SALIDA: nodo padre del nodo que se borro
	if (aux == root) {
		if (root->getIzquierda() == NULL)
			root = root->getDerecha();
		else
			root = root->getIzquierda();
		delete aux;
		return root;
	}
	else {
		NodoArbol* hijo; // el que borro tiene hijo der o izq
		if (aux->getDerecha() == NULL)
			hijo = aux->getIzquierda();
		else
			hijo = aux->getDerecha();
		if (antes->getDerecha() == aux) // el que borro es hijo izq o der
			antes->setDerecha(hijo);
		else
			antes->setIzquierda(hijo);
		delete aux;
		return antes;
	}
}

NodoArbol* ABB::borraDosHijos(NodoArbol* antes, NodoArbol* aux)
{   // borra un nodo con dos hijos
	// ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
	// SALIDA: nodo padre del nodo que se borro
	NodoArbol* antesd = aux->getDerecha(), * auxd = antesd;
	while (auxd->getIzquierda() != NULL) { // busco sustituto del nodo que borro, el mas izquierdo de la derecha
		antesd = auxd;
		auxd = auxd->getIzquierda();
	}
	if (aux == root) {// el nodo que borro es raiz con dos hijos
		if (auxd != antesd) {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setDerecha(antesd);
		}
		auxd->setIzquierda(aux->getIzquierda());
		delete aux;
		root = auxd;
		return auxd;
	}
	else {// el nodo que borro es cualquiera
		if (auxd == antesd)// el sustituto es inmediato derecho del que borro
			auxd->setIzquierda(aux->getIzquierda());
		else {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setIzquierda(aux->getIzquierda());
			auxd->setDerecha(aux->getDerecha());
		}
		if (antes->getDerecha() == aux) // el nodo que borro es hijo derecho
			antes->setDerecha(auxd);
		else
			antes->setIzquierda(auxd); // el que borro es hijo izquierdo
		delete aux;
		return antes;
	}
}

NodoArbol* ABB::buscarNodo(std::string key){

	NodoArbol* aux = root;

	while (aux != NULL && key != aux->getDato()){
		//Moverse entre nodos
		if (key > aux->getDato())
			aux = aux->getDerecha();
		else
			aux = aux->getIzquierda();
	}
	if (aux == NULL){
		cout << key << " ¡No se encuentra dentro del diccionario!" << endl;
		return aux;
	}
	else{
		cout << key  << " ¡Registro encontrado!" << endl;
	}
	return aux;
}

void ABB::borrar(string str) { 

	NodoArbol* aux = buscarNodo(str);
	NodoArbol* auxiliar = root;
	NodoArbol* antes = root;

	while (aux != NULL && aux->getDato() != auxiliar->getDato()){
		antes = auxiliar;
		if (aux->getDato() > auxiliar->getDato())
			auxiliar = auxiliar->getDerecha();
		else
			auxiliar = auxiliar->getIzquierda();
	}

	if (aux != NULL) {
		if (aux->getDerecha() == NULL && aux->getIzquierda() == NULL) {
			cout << " Una Hoja" << endl;
			if (aux == root) {
				cout << " root Una Hoja" << endl;
				borraSinHijos(antes, aux);
			}else{
				cout << " Una Hoja " << endl;
				antes = borraSinHijos(antes, aux);
			}
			
		}
		else if (aux->getDerecha() == NULL && aux->getIzquierda() != NULL || aux->getDerecha() != NULL && aux->getIzquierda() == NULL )
		{	
			if (aux == root) {
				cout << " root Una Hijo  " << endl;
				borraUnHijo(antes, aux);
			}else{
				cout << " Una Hijo " << endl;
				borraUnHijo(antes, aux);
			}			
			
		}
		else
		{
			if (aux == root) {
				cout << " root Dos hijos " << endl;
				borraDosHijos(antes, aux);
			}else{
				cout << " Dos hijos " << endl;
				borraDosHijos(antes, aux);
			}
		}
	}
	else {
		cout << "¡No se encuentra dentro del diccionario!" << endl;
	}
}








