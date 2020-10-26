// Andrea Espinosa Azuela  + Ricardo Solis Zugarazo
// Viernes 23 de Octubre del 2020
// En este c�digo implementaremos los met�dos b�sicos de los arboles binarios y un diccionario basado en el ABB
// Referencias: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html ,http://c.conclase.net/edd/?cap=007c
#pragma once
#include "NodoArbol.h"
#include <string>
class ABB
{
	NodoArbol* root;
	NodoArbol* ax;

public:
	ABB();
	~ABB();

	NodoArbol* getRoot();
	void setRoot(NodoArbol*);
	void Inserta(std::string);

	NodoArbol* borraSinHijos(NodoArbol*, NodoArbol*);
	NodoArbol* borraUnHijo(NodoArbol*, NodoArbol*);
	NodoArbol* borraDosHijos(NodoArbol*, NodoArbol*);
	
	void preorden(NodoArbol*);
	void posorden(NodoArbol*);
	void inorden(NodoArbol*);

	int cuentaInternos(NodoArbol*,int);
	void cuentaNodosIH(NodoArbol*, int&,int&);
	int cuentaNodos(NodoArbol*,int);
	int cuentaHojas(NodoArbol*, int);

	NodoArbol* buscarNodo(std::string);
	void borrar(std::string);

};
