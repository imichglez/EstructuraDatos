#ifndef LISTAENTEROS_H
#define LISTAENTEROS_H

class ListaEnteros{
    private:
        int* valores;  //Almacenamos valores
        int length;   //Capacidad del Arreglo
        int size;       //Número de elementos del arreglo
        void swap(int i, int j);

        void mergeSort(int ini, int fin);
	    void mezcla(int ini, int fin);
	    int particionar(int ini, int fin);

    public:
        ListaEnteros(int length);
        ListaEnteros(int valores[], int length);
        void imprime();
        int busquedaSec(int valor);
        int busquedaBin(int valor, int min, int max);

        void bubbleSort();
        void insertionSort();
        void mergeSort();
	    void mezcla();
};

#endif