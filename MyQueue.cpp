#include "MyQueue.h"
#include <iostream>

MyQueue::~MyQueue(){

}

void MyQueue::enqueue(int data){
    this -> lista.insertLast(data);
}

void MyQueue::dequeue(){
    this -> lista.removeFirst();
}

int MyQueue::peek(){
    return this -> lista.first();
}

bool MyQueue::isEmpty(){
    this -> lista.isEmpty();
}

int MyQueue::length(){
    return this -> lista.length();
}

void MyQueue::flush(){
    while(this -> isEmpty()){
        this -> dequeue();
    }
}