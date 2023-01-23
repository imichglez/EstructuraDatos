// Jorge Wolburg A01640826

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h"
using namespace std;

class MyHashTable {
private:
  MyLinkedList *tabla;
  int size;  // Numero de valores que existen en la tabla
  int sizeA; // Tamano del arreglo
  int getPos(string key);
  void rehashing();

public:
  MyHashTable();
  ~MyHashTable();
  bool isEmpty();
  void put(string key, string value);
  string get(string key);
  void remove(string key);
  int compSize();
  void getList(int pos);
  int getPosition(string key);
  MyLinkedList getLinkL(int pos);
};
#endif