#include <fstream>
#include <iostream>
using namespace std;

/* 
Ingrid González A01641116 
El programa calcula la sumatoria de 1 hasta n con un método mátematico directo.
*/

int sumaDirecta(int n){
    if (n <= 0) { // Es de orden lineal ---- O(n)
        return 0;
    } else {
        return (n * (n+1))/2; // Es de orden lineal ---- O(n)
    }
}

int main(){
    int n, sumaDirec;
    cout << "--- Suma directa ---" << endl;
    cout << "Ingrese el número de elementos a sumar: ";
    cin >> n;
    sumaDirec = sumaDirecta(n);
    cout << "La suma es: " << sumaDirec << endl;

    return 0;
}