/*
Equipo: 2
Ingrid Michelle González Mendoza - A01641116
Jorge Esteban Madrigal Ramírez - A01641409
Jorge Germán Wolburg Trujillo - A01640826

Profesor: Edgar Gerardo Salinas Gurrión

Actividad Integral Estructura de Datos Lineales 
*/

#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  LinkedList bitacora;
  ifstream lector("bitacora.txt");
  string data, linea;
  while (getline(lector, linea)) {
    stringstream ss(linea);
    getline(ss, data, '\n');
    bitacora.insertLast(data);
  }
  lector.close();

  bitacora.quickSort();

  ofstream escritor("bitacoraOrdenada-Eq#2.txt"); // crea el archivo bitacoraCorrecta.txt con todos los registros ordenados
  if (escritor.is_open()) {
    for (int i = 0; i < bitacora.getSize(); i++) {
      escritor << bitacora.getAt(i)->data << "\n";
    }
    escritor.close();
    cout << "La bitacora ordenada se encuentra en \"bitacoraOrdenada-Eq#2.txt\"." << endl;
  }

  bool another = 1;
  int N = 1;

  while (another == 1) {
    cout << "\nBúsqueda de registros: \n" << endl;
    cout << "Favor de ingresar los datos en el siguiente formato XXX.XXX.XXX.XXX (no es necesario llenar los 3 espacios por cuarteto)" << endl;
    string firstIP;
    cout << "\nDireccion IP de inicio: ";
    cin >> firstIP;
    long long IPInicial = bitacora.ipLong(firstIP + ":0000");

    cout << "\nIgual que el formato anterior, favor de ingresar la direccion IP final" << endl;
    string lastIP;
    cout << "\nDireccion IP final: ";
    cin >> lastIP;
    long long IPFinal = bitacora.ipLong(lastIP + ":9999");

    int posIni = bitacora.binarySearch(IPInicial);
    int posFin = bitacora.binarySearch(IPFinal);

    cout << "\nLos registros de la direccion IP inicial a la direccion IP final son: ";
    cout << endl;
    for (int i = posIni; i < posFin; i++) {
      cout << bitacora.getAt(i)->data << endl;
    }

    string M = to_string(N);
    ofstream doc("salida" + M + "-Eq#2.txt");
    if (doc.is_open()) {
      for (int i = posIni; i < posFin; i++) {
        doc << bitacora.getAt(i)->data << endl;
      }
      doc.close();
      cout << "\nLos registros ordenados fueron guardados en salida" + M + "\"-Eq#2.txt\"." << endl;
    }
    cout << "\nGustaria realizar otra busqueda? si(1) no(0)" << endl;
    cin >> another;
    N++;
  }
}