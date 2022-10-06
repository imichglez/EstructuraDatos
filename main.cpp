#include "MyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
	MyLinkedList list;

	// creamos una lista
	list.insertFirst(10);
	list.insertFirst(11);
	list.insertFirst(12);
	list.insertFirst(13);
	list.insertLast(8);
	cout << list << endl;

	// insertamos un dato en cierta posición
	list.insertAt(9, 5);
	cout << list << endl;

	// removemos un dato de cierta posición
	list.removeAt(3);
	cout << list << endl;

  	// removemos el primer elemento
	list.removeFirst();
	cout << list << endl;

  	// removemos el último elemento
	list.removeLast();
	cout << list << endl;
  
	// elimina todos los datos de la lista
	list.~MyLinkedList();
	cout << list << endl;
}