#include <iostream>
using namespace std;

void swap1(int x, int y){
    int aux = x;
    x = y;
    y = aux;
}

void swap2(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void swap3(int &x, int &y){
    int aux = x;
    x = y;
    y = aux;
}

int main(){
    cout << "Hello World! \n";
    int a = 10;
    int *ptr = &a;
    *ptr = 50;
    cout << a << " " << *ptr << endl;
    a = 100;
    cout << a << " " << *ptr << endl; // los dos refieren a la misma dirección 
    int b = 200;

    swap1(a,b);
    cout << a << " " << b << endl; 

    swap2(&a,&b);
    cout << a << " " << b << endl;

    swap3(a,b);
    cout << a << " " << b << endl;
    cout << ptr << " " << (ptr + 1) << endl;
    return 0;
}