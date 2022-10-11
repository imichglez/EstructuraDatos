#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

struct MyNodeLL {
  string data;
  MyNodeLL *next;
  MyNodeLL *prev;

  MyNodeLL(string data, MyNodeLL *next, MyNodeLL *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }

  MyNodeLL(string data) : MyNodeLL(data, nullptr, nullptr){}
};

class LinkedList {
private:
  MyNodeLL *head;
  MyNodeLL *tail;
  int size;
  void swap(MyNodeLL *i, MyNodeLL *j);
  int part(int ini, int fin);
  void quickSort(int ini, int fin);

public:
  LinkedList();
  int getSize();
  void insertLast(string data);
  MyNodeLL *getAt(int pos);
  string ipValidate(string &a);
  long long ipGetter(string data);
  long long ipLong(string bIP);
  void quickSort();
  int binarySearch(long long bIP);
  friend ostream &operator<<(ostream &os, const LinkedList &ll);

};

#endif