#include "listaEnteros.h"
#include <iostream>
using namespace std;

ListaEnteros::ListaEnteros(int length){
    this->length = length;
    this->valores = new int[length];
    this->size = 0;
}

ListaEnteros::ListaEnteros(int valores[], int length) : ListaEnteros(length){
    for(int i = 0; i < length; i++){
        this->valores[i] = valores[i];
    }
    this->size = length;
}

void ListaEnteros::imprime(){
    for(int i=0; i<this->size; i++){
      cout << valores[i] << ",";
    }
  cout << endl;
}

void ListaEnteros::swap(int i, int j){
  int aux = this->valores[i];
  this->valores[i] = this->valores[j];
  this->valores[j] = aux;
}

int ListaEnteros::busquedaSec(int valor){
  for(int i=0; i<this->size; i++){
    if(this->valores[i] == valor){
      return i;
    }
  }
  return -1;
}

/*
int ListaEnteros::busquedaBin(int valor, int min, int max){
  int avg;
  while (min <= max){
    int avg = (min + max)/2;
    if (valor ==)
  }
}
*/

void ListaEnteros::bubbleSort(){
  for(int i=0; i<this->size-1; i++){ //Las iteraciones necesarias
    for(int j=0; j<this->size-1; j++){ //Hace las comparaciones
      if(this->valores[j] > this->valores[j+1]){
        swap(j, j+1);
      }
    }
  }
}

void ListaEnteros::insertionSort(){
  for(int i=1; i<this->size-1; i++){
    for(int j=i-1; j>=0; j--){
      if(this->valores[j+1] < this->valores[j]){
        swap(j+1, j);
      }else{
        break;
      }
    }
    imprime();
  }
}

void ListaEnteros::mezcla(int ini, int fin) {
	// calcular el PM y van  a ordenar sobre un nuevo arreglo
	// 0-pm y pm+1-ultimo
	// regresar los datos a valores
}

void ListaEnteros::mergeSort() {
	mergeSort(0, this->size - 1);
}

void ListaEnteros::mergeSort(int ini, int fin) {
	if (ini < fin) {
		int centro = (ini + fin) / 2;
		mergeSort(ini, centro);
		mergeSort(centro + 1, fin);
		mezcla(ini, fin);
	}
}