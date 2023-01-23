/*
Grafos: Implementación individual de operaciones sobre conjuntos
Autor: Ingrid González A01641116
Fecha: 25/11/22
*/

#include "MyHashTable.h"
#include "MyLinkedList.h"
#include <iostream>
using namespace std;

int main(){
    MyHashTable store;
    store.put("Manzana", 1);
    store.put("Leche", 2);
    store.put("Huevos", 3);
    store.put("Tortillas", 4);
    store.put("Sandía", 5);

    string item1 = "Manzana", item2 = "Leche", item3 = "Huevos", item4 = "Tortillas", item5 = "Sandía";
    cout << "---- STORE INVENTORY ----" << endl;
    cout << "El item " << item1 << " con código " << store.get(item1) << ", se encuentra en existencia." << endl;
    cout << "El item " << item2 << " con código " << store.get(item2) << ", no se encuentra en existencia." << endl;
    cout << "El item " << item3 << " con código " << store.get(item3) << ", se encuentra en existencia." << endl;
    cout << "El item " << item4 << " con código " << store.get(item4) << ", se encuentra en existencia." << endl;
    cout << "El item " << item5 << " con código " << store.get(item5) << ", se encuentra en existencia." << endl;

    //store.remove(item2);
    //cout << "\nSe ha removido el item 2 por falta de existencia en tienda." << endl;

    cout << "\nEl tamaño de la lista es de: " << store.sizeComp() << endl;
    cout << "La hash table está vacia?: " << store.isEmpty() << endl;
    cout << "\nEliminando la hash table..." << endl;
    store.~MyHashTable();
    cout << "La hash table está vacia?: " << store.isEmpty() << endl;

    return 0;
}