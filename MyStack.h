#ifndef MYSTACK_H
#define MYSTACK_H
#include "MyLinkedList.h"
#include <iostream>
using namespace std;


class MyStack{
    private:
    MyLinkedList lista;

    public: 
    ~MyStack();
    void push(int data);
    void pop(); // si la queue está vacía
    int top(); // si la queue está vacía
    bool isEmpty();
    void flush();
};

#endif