/*
Árbol Heap: Implementando una fila priorizada
Autor: Ingrid González A01641116
Fecha: 23/oct/22
*/

#ifndef MYHEAP_H
#define MYHEAP_H

class MyHeap{
    private:
        int* values; // Arreglo donde se van a guardar los valores del HEAP
        int size; // Representa cuantos valores tiene almacenado el Heap
        int len; // Representa el tamaño o capacidad máxima actual del arreglo

        int right(int i);
        int left(int i);
        int parent(int i);
        void swap(int i, int j);
        void heapify(int arr[], int x, int y);

    public:
        MyHeap(); 
        void push(int n); 
        void pop(); 
        int top(); 
        bool isEmpty(); 
        int length(); 
        void print();
    };
#endif 