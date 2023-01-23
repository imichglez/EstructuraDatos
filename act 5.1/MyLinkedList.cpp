/*
Diseño e implementación de interfaz para ADT.
Autor: Ingrid González A01641116
Fecha: 3/oct/22
*/

#include "MyLinkedList.h"
#include <iostream>
using namespace std;

/*
Constructor; inicializa variables.
Complejidad O(1)
*/ 
MyLinkedList::MyLinkedList(){
    this -> size = 0;
    this -> head = this -> tail = nullptr;
}

/*
Destructor; elimina todos los datos de la lista.
Complejidad O(n)
*/ 
MyLinkedList::~MyLinkedList(){
    MyNodoLL* tmp;
    while(this -> head != NULL){
        tmp = this -> head -> next;
        delete this -> head;
        this -> head = tmp;
        this -> size--;
    }
}

//Complejidad O(1)
MyNodoLL* MyLinkedList::first(){
    return this -> head;
}

/*
Regresa el número de datos en la lista.
Complejidad O(1)
*/ 
int MyLinkedList::length(){
    return this -> size;
}

/*
Analiza si la lista está vacía o no.
Complejidad O(1)
*/ 
bool MyLinkedList::isEmpty(){
    return this -> size == 0;
}

/*
Complejidad O(n)
*/
int MyLinkedList::getAt(string key){
    MyNodoLL* tmp = this -> head;
    for(int i = 0; i < this -> size; i++){
        if(tmp -> key == key){
            return tmp -> data;
        }
        tmp = tmp -> next;
    }
    throw invalid_argument("Llave no encontrada " + key);
}

/*
Complejidad O(n)
*/
int MyLinkedList::posLL(string key){
    MyNodoLL* tmp = this -> head;
    for(int i = 0; i < this -> size; i++){
        if(tmp -> key == key){
            return i;
        }
        tmp = tmp -> next;
    }
    return -1;
}

/*
Inseta un dato al inicio de la lista.
Complejidad O(1)
*/ 
void MyLinkedList::insertFirst(int data, string key){
    MyNodoLL* n = new MyNodoLL(data, this -> head, key);
    this -> head = n;
    if(this -> size == 0){
        this -> tail = this -> head;
    }
    this -> size++;
}

/*
Elimina el primer dato.
Complejidad O(1)
*/ 
void MyLinkedList::removeFirst(){
    if(this -> size > 0){
        MyNodoLL* tmp = this -> head;
        this -> head = this -> head -> next;
        delete tmp;
        this -> size--;
        
        if(this -> size == 0){
            this -> tail = nullptr;
        } 
        
    } else {
        throw invalid_argument("No se puede borrar un elemento de una lista vacía");
    }
}

/*
Elimina el último dato.
Complejidad O(n)
*/ 
void MyLinkedList::removeLast(){
    if(this -> size > 0){
        MyNodoLL *tmp = this -> tail;
        this -> tail = this -> tail -> next;
        this -> size--;

        if(this -> size == 0){
            this -> head = nullptr;
        }
    } else {
        throw invalid_argument("No se puede puede borrar un elemento de una lista vacía");
    }
}

/*
Elimina datos de un nodo dado.
Complejidad O(n)
*/ 
void MyLinkedList::removeAt(int pos){
	MyNodoLL *tmp = this -> head;
    if(tmp == nullptr){
        throw invalid_argument("No se puede puede borrar un elemento de una lista vacía");
    } else if(pos == 0){
        this -> removeFirst();
    } else{
        for(int i = 1; i < pos; i++){
            tmp = tmp -> next;
        }
        MyNodoLL* temp = tmp -> next;
        tmp -> next = temp -> next;
        this -> size--;
        delete tmp;
    }
}

// Sobrecarga del operador
ostream &operator << (ostream & os, const MyLinkedList& ll){
    MyNodoLL* tmp = ll.head;
    for(int i=0; i<ll.size; i++){
        os << tmp -> data << ",";
        tmp = tmp -> next;
    }
    return os;
}