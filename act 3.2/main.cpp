/*
Árbol Heap: Implementando una fila priorizada
Autor: Ingrid González A01641116
Fecha: 23/oct/22
*/

#include "MyHeap.h"
#include <iostream>
using namespace std;

int main(){
    MyHeap tree;
    tree.push(6);
    tree.push(20);
    tree.push(43);
    tree.push(10);
    tree.push(36);
    tree.push(19);
    tree.push(2);

    cout << "---- HEAP TREE ----" << endl;
    cout << "Árbol antes del pop: ";
    tree.print(); 
    cout << endl;


    tree.pop();
    tree.pop();
    tree.pop();
    cout << "Después del pop: ";
    tree.print();

    // tamaño del árbol heap
    cout << "\nEl tamaño del árbol es: " << tree.length() << endl;

    // primer valor del árbol
    cout << "El primer valor del árbol es: " << tree.top() << endl;

    return 0;
}