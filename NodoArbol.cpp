// Andrea Espinosa Azuela  + Ricardo Solis Zugarazo
// Viernes 23 de Octubre del 2020
// En este c�digo implementaremos los met�dos b�sicos de los arboles binarios y un diccionario basado en el ABB
// Referencias: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html ,http://c.conclase.net/edd/?cap=007c

#include "NodoArbol.h"
#include <iostream>
#include <string>
NodoArbol::NodoArbol() {
	derecha = NULL;
	izquierda = NULL;
}
NodoArbol::NodoArbol(std::string _dato) {
	dato = _dato;
	derecha = NULL;
	izquierda = NULL;
}

std::string NodoArbol::getDato() { //Accesor
	return dato;
}
void NodoArbol::setDato(std::string _dato) {//Modificador 
	dato = _dato;
}

NodoArbol* NodoArbol::getDerecha() {//Accesor
	return derecha;
}
void NodoArbol::setDerecha(NodoArbol* _derecha) {//Modificador
	derecha = _derecha;
}

NodoArbol* NodoArbol::getIzquierda() {//Accesor
	return izquierda;
}
void NodoArbol::setIzquierda(NodoArbol* _izquierda) {//Modificador
	izquierda = _izquierda;
}

NodoArbol::~NodoArbol() {

}