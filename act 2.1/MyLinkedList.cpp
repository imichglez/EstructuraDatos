/*
Diseño e implementación de interfaz para ADT.
Autor: Ingrid González A01641116
Fecha: 3/oct/22
*/

#include "MyLinkedList.h"
#include <iostream>
using namespace std;

/*
Complejidad O(1)

Constructor; inicializa variables
*/ 
MyLinkedList::MyLinkedList(){
    this -> size = 0;
    this -> head = this -> tail = nullptr;
}

/*
Complejidad O(n)

Destructor; elimina todos los datos de la lista
*/ 
MyLinkedList::~MyLinkedList(){
    MyNodoLL* tmp;
    while(this->head != NULL){
        tmp = this->head->next;
        delete this->head;
        this->head = tmp;
        this->size--;
    }
}

/*
Complejidad O(1)

Regresa el primer dato de la lista
Regresa un mensaje si la lista está vacía
*/
int MyLinkedList::first() { 
    if(this -> size > 0){
        return this -> head -> data; 
    } else{
        throw invalid_argument("Vacío");
    }
}

/*
Complejidad 

Regresa el último dato de la lista
Regresa un mensaje si la lista está vacía
*/ 
int MyLinkedList::last() { 
    if(this -> size > 0){
        return this -> tail -> data; 
    } else{
        throw invalid_argument("Vacío");
    }
}

/*
Complejidad O(1)

Regresa el número de datos en la lista
*/ 
int MyLinkedList::length(){
    return this -> size;
}

/*
Complejidad O(1)

Analiza si la lista está vacía o no
*/ 
bool MyLinkedList::isEmpty(){
    return this -> size == 0;
}

/*
Complejidad O(n)

Trae datos de una cierta posición en la lista
*/
int MyLinkedList::getAt(int pos){
    MyNodoLL* tmp = this -> head;
    for(int i=0; i<pos-1; i++){
        tmp = tmp -> next;
    } 
    return tmp -> data;
}

// Complejidad O(n)
void MyLinkedList::setAt(int data, int pos){
   MyNodoLL* tmp = this -> head;

   for(int i=0; i<pos-1; i++){
    tmp = tmp -> next;
   }
   tmp -> data = data;
}

/*
Complejidad O(1)

Inseta un dato al inicio de la lista
*/ 
void MyLinkedList::insertFirst(int data){
    this -> head = new MyNodoLL(data, this -> head);
    if(this -> size == 0){
        this -> tail = this -> head;
    }
    this -> size++;
}

/*
Complejidad O(n)

Inserta datos al final de la lista
*/ 
void MyLinkedList::insertLast(int data){
    if(this -> size == 0){
        this -> head = this -> tail;
    } else {
        MyNodoLL* tmp = new MyNodoLL(data);
        this -> tail -> next = tmp;
        this -> tail = tmp;
        this -> size++;
    }
}

/*
Complejidad O(1) si se encuentra al inicio, fuera de esto sería O(n)

Inserta datos en un nodo dado
*/ 
void MyLinkedList::insertAt(int data, int pos){
    if(this -> size > 0){
        MyNodoLL* aux = this -> head;
        MyNodoLL* tmp = new MyNodoLL(data);

        for(int i=0; i<pos-2; i++){
            aux = aux -> next;
        }

        tmp -> next = aux -> next;
        aux -> next = tmp;
        this -> size++;
    } else {
        throw invalid_argument("No se puede agregar ya que no hay suficientes elementos");
    }
}

/*
Complejidad O(1)

Elimina el primer dato
*/ 
void MyLinkedList::removeFirst(){
    if(this -> size > 0){
        MyNodoLL* tmp = this -> head;
        this -> head = this -> head -> next;
        delete tmp;

        if(this -> size == 1){
            this -> tail = nullptr;
        } 
        this -> size --;
    } else {
        throw invalid_argument("No se puede borrar un elemento de una lista vacía");
    }
}

/*
Complejidad O(n)

Elimina el último dato
*/ 
void MyLinkedList::removeLast(){
    if(this -> size <= 1){
        removeFirst();
    } else{
        MyNodoLL* tmp = this -> head;
        for(int i=0; i< this->size-2;i++){
            tmp = tmp -> next;
        } 
        // tmp ya está en una posición atras de tail
        tmp -> next = nullptr;
        delete this -> tail; 
        this -> tail = tmp;
        this -> size --;
    }
}

/*
Complejidad O(n)

Elimina datos de un nodo dado
*/ 
void MyLinkedList::removeAt(int pos){
	if(this -> size > 0){
        MyNodoLL* tmp;
        MyNodoLL* aux = this -> head;

        for(int i=0; i<pos-2; i++){
            aux = aux -> next;
        }
        tmp = aux -> next;
        aux -> next = tmp ->next;
        delete tmp;
        this -> size--;
    } else{
        throw invalid_argument("No se puede borrar un elemento de una lista vacía");
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