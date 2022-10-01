#include <fstream>
#include <iostream>
using namespace std;
/* 
Ingrid González A01641116 
El programa calcula la sumatoria de 1 hasta n con un método iterativo.
*/

int sumaIterativa(int n){
    int suma = 0;
    for (int i=1; i<=n; i++){  // Es de orden lineal ---- O(n)
        suma += i; // Es de orden constante ---- O(1)
    } 
    return suma;
}


int main(){
    int n, sumaIt; 
    cout << "--- Suma iterativa ---" << endl;
    cout << "Ingrese el número de elementos a sumar: ";
    cin >> n;
    sumaIt = sumaIterativa(n);
    cout << "La suma es: " << sumaIt << endl;

    return 0;
}