#include <fstream>
#include <iostream>
using namespace std;

/* 
Ingrid González A01641116 
El programa calcula la sumatoria de 1 hasta n con un método recursivo.
*/

int sumaRecursiva(int n){
    if (n <= 0) { // Es de orden lineal ---- O(n)
        return 0;
    } else {
        return n + sumaRecursiva(n-1); // Es de orden lineal ---- O(n)
    }
}

int main(){
    int n, sumaRec;
    cout << "--- Suma recursiva ---" << endl;
    cout << "Ingrese el número de elementos a sumar: ";
    cin >> n;
    sumaRec = sumaRecursiva(n);
    cout << "La suma es: " << sumaRec << endl;

    return 0;
}