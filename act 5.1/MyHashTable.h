/*
Grafos: Implementación individual de operaciones sobre conjuntos
Autor: Ingrid González A01641116
Fecha: 25/11/22
*/

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h" 
#include <string>
using namespace std;

class  MyHashTable{
    private:
        //list<int> *tabla;
        MyLinkedList *tabla;
        int size; // num. de valores que hay en la tabla
        int sizeA; // tamaño del arreglo
        int getPos(string key); // en que posición se debería alojar una llave
        void rehashing();

    public:
        MyHashTable();
        ~MyHashTable();
        bool isEmpty();
        void put(string key, int value);
        int get(string key);
        void remove(string key);
        int sizeComp();
};

#endif