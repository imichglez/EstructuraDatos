#include "listaEnteros.h"
#include <iostream>
using namespace std;

int main() {
	int a[] = {11, 9, 7, 15, 6, 10, 5, 17};
	ListaEnteros listaUno(a, 8);
	listaUno.imprime();
	listaUno.insertionSort();
	// listaUno.imprime();
}