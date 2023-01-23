// Jorge Wolburg A01640826

#include "MyHashTable.h"
#include <cmath>
#include <functional>
#include <iostream>

using namespace std;

MyHashTable::MyHashTable() { // Constructor O(1)
  this->size = 0;
  this->sizeA = 11;
  this->tabla = new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable() { // Destructor O(n)  
  for (int i = 0; i < this->sizeA; i++){
    if(this->tabla[i].length() > 0){
      this->size -= this->tabla[i].length();
      this->tabla[i].~MyLinkedList();
    }
  }
} 

bool MyHashTable::isEmpty() { return this->size == 0; } // Complejidad O(1)

int MyHashTable::getPos(string key) { // Regresa el hash de la key que se inserto. Complejidad O(n)
  size_t hashC = hash<string>()(key);
  int hashCode = static_cast<int>(hashC);
  return abs(hashCode % this->sizeA);
}

void MyHashTable::rehashing() { // Aumenta el tamano de la tabla y vuelve a acomodar las keys que ya tenia. Complejidad O(n)
  MyLinkedList *base = this->tabla;
  int size = this->sizeA;
  this->sizeA = (2 * this->sizeA) + 1;
  this->tabla = new MyLinkedList[this->sizeA];

  for (int i = 0; i < size; i++) {
    if (base[i].isEmpty() == 0) {
      MyNodoLL *tmp = base[i].first();
      while (tmp != nullptr) {
        int pos = getPos(tmp->key);
        this->tabla[pos].insertFirst(tmp->key, tmp->data);
        tmp = tmp->next;
      }
      base[i].~MyLinkedList();
    }
  }
  delete base;
}

void MyHashTable::put(string key, string data) { // Inserta una nueva key con su valor. Complejidad O(1)
  float factor = this->size / this->sizeA;
  if (factor >= 0.75) {
    rehashing();
  }
  int pos = getPos(key);
  this->tabla[pos].insertFirst(key, data);
  this->size++;
}

string MyHashTable::get(string key) { // Retorna el valor de la key que se inserto. Complejidad O(1) y en el peor de los casos O(n)
  int pos = getPos(key);
  MyLinkedList *list = &this->tabla[pos];
  return list->getAt(key);
}
void MyHashTable::remove(string key) { // Elimina una key. Complejidad O(n)
  int pos = getPos(key);
  if (this->tabla[pos].searchKey(key) >= 0) {
    int poss = this->tabla[pos].searchKey(key);
    this->tabla[pos].removeAt(poss);
    this->size--;
  }
}

int MyHashTable::compSize(){
    return this->sizeA;
}

int MyHashTable::getPosition(string key){ //Hash del key insertado. Complejidad O(n)
    size_t hashC=hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

void MyHashTable::getList(int pos){
    this->tabla[pos].getData();
}

MyLinkedList MyHashTable::getLinkL(int pos){
    return this->tabla[pos];
}