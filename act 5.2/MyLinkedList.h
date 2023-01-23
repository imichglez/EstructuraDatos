// Jorge Wolburg A01640826
// Act 2.1: Implementacion de un ADT de estructurras de datos lineal

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;

struct MyNodoLL {
  string data;
  string key;
  MyNodoLL *next;

  MyNodoLL(string key, string data, MyNodoLL *next) {
    this->key = key;
    this->data = data;
    this->next = next;
  }

  MyNodoLL(string key, string data) : MyNodoLL(key, data, nullptr) {}
};

class MyLinkedList {
private:
  MyNodoLL *head;
  MyNodoLL *tail;
  int size;
  void quickSort(int start, int end);
  void swap(MyNodoLL* one, MyNodoLL* two);
  int part(int start, int end);

public:
  MyLinkedList();
  ~MyLinkedList();
  MyNodoLL *first(); // Exc invalid argument
  string last();            // Exc invalid argument
  int length();
  bool isEmpty();
  string getAt(string key); // a[3] getPos(3)
  void setAt(int data, int pos);
  int searchKey(string key);

  void insertFirst(string key, string data);
  void insertLast(string key, string data); // Inserta al final de la lista
  void insertAt(string key, string data, int pos);

  void removeFirst();
  void removeLast();
  void removeAt(int pos);

  friend ostream &
  operator<<(ostream &os, const MyLinkedList &ll); // elemento0,elemento1,elemento2...
  void quickSort();
  void getData();
  MyNodoLL* getNodo(int pos);
};
#endif