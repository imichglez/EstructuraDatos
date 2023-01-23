/*
Grafos: Implementación individual de operaciones sobre conjuntos
Autor: Ingrid González A01641116
Fecha: 25/11/22

Consultado:
Pumpkin Programmer. (2014). C++ Tutorial: Intro to HashTables [YouTube Video]. 
In YouTube. https://www.youtube.com/watch?v=jEdaduyLLqY&t=294s
*/

#include "MyHashTable.h"
#include "MyLinkedList.h"
#include <string>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;

/*
Constructor de la tabla hash.
Complejidad O(1)
*/
MyHashTable::MyHashTable(){
    this -> size = 0;
    this -> sizeA = 11;
    this -> tabla = new MyLinkedList[this -> sizeA];
}

/*
Destructor.
Complejidada O(n)
*/
MyHashTable::~MyHashTable(){
    int tamano = 0;
    for(int i = 0; i< this -> sizeA; i++){
        tamano = this -> tabla[i].length();
        if(tamano > 0){
            this -> tabla[i].~MyLinkedList();
            this -> size -= tamano;
        }
    }
}

/*
Si la lista está vacía, regresa un valor booleano.
Complejidad O(1) 
*/
bool MyHashTable::isEmpty(){
    return this -> size == 0;
}

/*
Obtenemos el key insertado de la hashtable.
Complejidad O(n)
*/
int MyHashTable::getPos(string key){
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode)% this -> sizeA;
}

/*
Incrementa el tamaño del hash.
Complejidad O(n)
*/
void MyHashTable::rehashing(){
    int oldCap = this -> sizeA;
    this -> sizeA = (this -> sizeA * 2) + 1;
    MyLinkedList* newHash = new MyLinkedList[oldCap];

    for(int i = 0; i < oldCap; i++){
        if(newHash[i].length() != 0){
            MyNodoLL* tmp = newHash[i].first();
            while (tmp != nullptr){
                int position = getPos(tmp -> key);
                this -> tabla[position].insertFirst(tmp -> data, tmp -> key);
                this -> size++;
            }
            newHash[i].~MyLinkedList();
        }  
        delete [] newHash;
    }
}

/*
Inserta un valor y la key a la tabla.
Complejidad O(1)
*/
void MyHashTable::put(string key, int value){
    float t = this -> size;
    float tA = this -> sizeA;
    float balance = t/tA;
    if(balance >= 0.75){
        rehashing();
    }
    int p = getPos(key);
    this -> tabla[p].insertFirst(value, key);
    this -> size++;
}

/*
Se obtiene el valor de la key que se ingresa.
Complejidad O(1) en el mejor caso, Complejidad O(n) en el peor. 
*/
int MyHashTable::get(string key){
    int p = getPos(key);
    MyLinkedList* lista = &this -> tabla[p];
    return lista -> getAt(key);
}

/*
Elimina un dato de la tabla hash.
Complejidad O(n)
*/
void MyHashTable::remove(string key){
    MyLinkedList* lista = &this -> tabla[getPos(key)];
    int val = lista -> posLL(key);
    if(val < 0){
        throw invalid_argument("Llave no encontrada " +key);
    } 
    lista -> removeAt(val);
    this -> size--;
}

int MyHashTable::sizeComp(){
    return this -> size;
}