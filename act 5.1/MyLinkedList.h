#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <iostream>
using namespace std;

struct MyNodoLL {
    string key;
    int data;
    MyNodoLL *next;

    MyNodoLL(int data, MyNodoLL *next, string key){
        this -> data = data;
        this -> next = next;
        this -> key = key;
    } 

    MyNodoLL(int data): MyNodoLL(data, nullptr, key){
        this -> data = data;
        this -> next = nullptr;
        this -> key = key;
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
    MyNodoLL *first();
    int length();
    bool isEmpty(); 

    int getAt(string key);
    int posLL(string key);

    void insertFirst(int data, string key);
    //void insertLast(int data);
    //void insertAt(int data, int pos); // pos:[0,size] Exc invalid_argument

    void removeFirst();
    void removeLast();
    void removeAt(int pos);  // pos:[0,size-1] Exc invalid_argument

    friend ostream& operator<<(ostream& os,const MyLinkedList& ll); //el0,el1,el2...
};

#endif