// Andrea Espinosa Azuela  + Ricardo Solis Zugarazo
// Viernes 23 de Octubre del 2020
// En este código implementaremos los metódos básicos de los arboles binarios y un diccionario basado en el ABB
// Referencias: https://blog.martincruz.me/2012/11/arboles-binarios-de-busqueda-c.html ,http://c.conclase.net/edd/?cap=007c

#include <iostream>
#include <fstream>
#include <string>
#include "NodoArbol.h"
#include "ABB.h"

using namespace std;

  std::string noSpace(std::string str){
        std::string espacio = " ";
        size_t pos = 0;
            std::string token;
            while ((pos = str.find(espacio)) != (std::string::npos)) {
                token = str.substr(0, pos);
                str.erase(0, pos + espacio.length());
            }
        return str;
    }


int main()
{
    ABB arbol;  
    int cuenta = 0;
    std::string inPut;
    std::string txt;

    ifstream MyReadFile("read.txt");
    while (getline (MyReadFile, txt)) {
        arbol.Inserta(txt);
    }
    MyReadFile.close();
     do {
        cout << endl;
        cout << "Busca: " << endl;
        cout << "Borrar: D + palabra " << endl;
        cout << "Insertar: I + palabra " << endl;
        cout << "Mostrar Inorden: M " << endl;
        cout << "Mostrar Preorden: Q " << endl;
        cout << "Mostrar Posorden: P " << endl;
        cout << "Contar: N " << endl;
        cout << "Salir: 0 " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        getline(cin, inPut);

        if (inPut[0] == 'D') {
            system("clear");
            arbol.borrar(noSpace(inPut));
        }

        else if (inPut[0] == 'I') {
             system("clear");
            if (noSpace(inPut).size() > 3)
            {
                arbol.Inserta(noSpace(inPut));
            }
            else {
                std::cout << "Debe ser mayor a tres letras" << endl;
            }
        }
        else if (inPut[0] == 'M') {
            system("clear");
            arbol.inorden(arbol.getRoot());
        }
        else if (inPut[0] == 'Q') {
            system("clear");
            arbol.preorden(arbol.getRoot());
        }
        else if (inPut[0] == 'P') {
            system("clear");
            arbol.posorden(arbol.getRoot());
        }
        else if (inPut[0] == 'N') {
            system("clear");
            cout << "Nodos: " << arbol.cuentaNodos(arbol.getRoot(), cuenta) << endl;
        }
        else {
            system("clear");
            arbol.buscarNodo(inPut);
        }
    } while (inPut != "0");


}

