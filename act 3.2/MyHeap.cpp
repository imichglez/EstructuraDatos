/*
Árbol Heap: Implementando una fila priorizada
Autor: Ingrid González A01641116
Fecha: 23/oct/22
*/

#include "MyHeap.h"
#include <iostream>
using namespace std;

/*
Inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
Complejidad O(1), todos los casos tienen la misma complejidad.
*/
MyHeap::MyHeap(){
    len = 7;
    values = new int[len];
    size = 0;
}

// Complejidad O(1), todos los casos tienen la misma complejidad.
int MyHeap::right(int i){
    return ((i * 2) + 2);
}

// Complejidad O(1), todos los casos tienen la misma complejidad.
int MyHeap::left(int i){
    return ((i * 2) + 1);
}

// Complejidad O(1), todos los casos tienen la misma complejidad.
int MyHeap::parent(int i){
    return (i - 1) / 2;
}

// Complejidad O(1), todos los casos tienen la misma complejidad.
void MyHeap::swap(int i, int j){
    int aux = values[i];
    values[i] = values[j];
    values[j] = aux;
}

/*
Inserta un valor en el heap.
Cuando el nuevo valor no cabe en el arreglo, este crece al tamaño 2*n+1.
Complejidad O(n) en el mejor caso, Complejidad O(log n) en el peor.
*/
void MyHeap::push(int n){
    size++;
    int i = size - 1;
    values[i] = n;
    heapify(values, n, i);
    if (size == len){
        return;
    }
}

/*
Reordena los valores ingresados.
Complejidad O(log n)
*/
void MyHeap::heapify(int arr[], int x, int y){
    int currentL = left(y);
    int currentR = right(y);
    int aux = y;

    if(currentL < x && arr[currentL] > arr[aux]){
        aux = currentL;
    }
    if(currentR < x && arr[currentR] > arr[aux]){
        aux = currentR;
    }
    if(aux != y){
        swap(arr[y], arr[aux]);
        heapify(arr, x, aux);
    }
}

/*
Elimina un valor del heap. No es necesario nunca decrementar el tamaño del arreglo.
Complejidad O(log n) en el mejor caso, Complejidad O(n) en el peor.
*/
void MyHeap::pop(){
    if (isEmpty()){
        cout << "El árbol no se pude eliminar" << endl;
    } 
    if (size == 1){
    size--;
    cout << values[0];
    }
    int i = values[0];
    values[0] = values[size - 1];
    size--;
    heapify(values, i, size - 1);
}

/*
Regresa quien es el siguiente elemento en salir pero sin borrarlo.
Complejidad O(1), todos los casos tienen la misma complejidad.
*/
int MyHeap::top(){
    if(isEmpty()){
        return -1;
    }
    return values [0];
}

/*
Regresa true si el heap está vacío caso contrario regresa false.
Complejidad O(1), todos los casos tienen la misma complejidad.
*/
bool MyHeap::isEmpty(){
    return size == 0;
}

/*
Regresa cuántos elementos están almacenando el heap.
Complejidad O(1), todos los casos tienen la misma complejidad.
*/
int MyHeap::length(){
    return size;
}

/*
Se imprimen los valores al compilar.
Complejidad O(n), todos los casos tienen la misma complejidad.
*/
void MyHeap::print(){
    for(int i = 0; i < size; i++){
        cout << values[i] << " ";
    }
}