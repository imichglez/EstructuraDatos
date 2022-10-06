#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;

struct MyNodoLL {
    int data;
    MyNodoLL *next;

    MyNodoLL(int data, MyNodoLL *next){
        this -> data = data;
        this -> next = next;
    } 

    MyNodoLL(int data): MyNodoLL(data, nullptr){
        this -> data = data;
        this -> next = nullptr;
    }
};

class MyLinkedList {
private:
    MyNodoLL *head;
    MyNodoLL *tail;
    int size;

public:
    MyLinkedList();
    ~MyLinkedList();
    int first();  // Exc invalid_argument
    int last();  // Exc invalid_argument
    int length();
    bool isEmpty(); 
    int getAt(int pos);  // a[3] getPos(3)
    void setAt(int data, int pos);

    void insertFirst(int data);
    void insertLast(int data);
    void insertAt(int data, int pos); // pos:[0,size] Exc invalid_argument

    void removeFirst();
    void removeLast();
    void removeAt(int pos);  // pos:[0,size-1] Exc invalid_argument

    friend ostream& operator<<(ostream& os,const MyLinkedList& ll); //el0,el1,el2...
};

#endif