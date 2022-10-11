#include <iostream>     
#include <fstream>
using namespace std;

// Ingrid González  A01641116

unsigned long long factorial (int n){
    if (n == 0 || n == 1) {
        return 1;
    } else{
        return n*factorial(n-1);
    }
};

int main(){
    int n;
    cout << "Factorial !" << endl;
    cout<< "Ingresa el valor del factorial a calcular: ";
    cin >> n;
    unsigned long long fac = factorial(n);
    cout << "El factorial de " << n << " es " << fac << endl;
    return 0;
};