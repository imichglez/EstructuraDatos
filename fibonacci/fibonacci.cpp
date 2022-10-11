#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;

// Ingrid González  A01641116

unsigned long fibo(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return fibo(n - 1) + fibo(n - 2);
  }
}

unsigned long fiboOpt(int n, unsigned long tabla[]) {
    if (tabla[n] != 0){
      return tabla[n];
    } else {
      return tabla[n] = fiboOpt(n-1, tabla) +fiboOpt(n-2,tabla);
    }
}

unsigned long fiboOpt(int n) {
  unsigned long tabla[n+1];
  for (int i=0; i<n+1; i++){
    tabla[i] = 0;
  }
  tabla[0] = tabla[1] = 1;
  return fiboOpt(n,tabla);
}

int main() {
  int n;
  cout << "Fibonacci" << endl;
  cout << "Ingresa el número de términos a cálcular: ";
  cin >> n;

  auto ini = high_resolution_clock::now();
  unsigned long fib = fiboOpt(n);
  auto fin = high_resolution_clock::now();
  auto dif = fin - ini;
  auto ms = duration_cast<milliseconds>(dif).count();

  cout << "El número fibonacci de "<< n << " es "<< fib << endl;
  cout << "Tiempo en calcular: " << ms << " milisegundos " << endl;
  return 0;
};