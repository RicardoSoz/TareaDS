// Andrea Espinosa Azuela  + Ricardo Solis Zugarazo
// Viernes 23 de Octubre del 2020
// En este c�digo implementaremos los met�dos b�sicos de los arboles binarios y un diccionario basado en el ABB
// Referencias: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html ,http://c.conclase.net/edd/?cap=007c
#include <string>
#pragma once
class NodoArbol
{
public: //Metodos p�blicos
	NodoArbol(); //Constructor por omisi�n
	NodoArbol(std::string);


	std::string getDato(); //Accesor
	void setDato(std::string); //Modificador 
	
	NodoArbol* getDerecha(); //Accesor
	void setDerecha(NodoArbol*); //Modificador

	NodoArbol* getIzquierda(); //Accesor
	void setIzquierda(NodoArbol*); //Modificador

	virtual ~NodoArbol();

private: //Atributos privados
	std::string dato; //Es la parte de la informacion
	NodoArbol* derecha;
	NodoArbol* izquierda;

};
