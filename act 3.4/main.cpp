/*
Equipo: 2
Ingrid Michelle González Mendoza - A01641116
Jorge Esteban Madrigal Ramírez - A01641409
Jorge Germán Wolburg Trujillo - A01640826

Profesor: Edgar Gerardo Salinas Gurrión

Actividad Integral de BST
*/

#include "MyBST.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void swap(vector<vector<string>> &x, int i, int j) { // Intercambia registros dentro de la bitacora O(1)
  vector<string> step;
  step = x[i];
  x[i] = x[j];
  x[j] = step;
}

string correctQ(string &q) { // Comprueba que sea la cantidad correcta de digitos por cuarteto. O(1)
  string correct;
  correct = q;
  if (correct.size() == 3) {
    return correct;
  } else {
    while (correct.size() < 3) {
      correct = "0" + correct;
    }
    return correct;
  }
}

/*
Convierte la direecion IP en long long para su comparacion
Complejidad O(log n)
*/
long long obtainIP(vector<string> registro) { 
  string IP = registro[3];

  string q1 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  q1 = correctQ(q1);

  string q2 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  q2 = correctQ(q2);

  string q3 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  q3 = correctQ(q3);

  string q4 = IP.substr(0, IP.find(':'));
  IP = IP.substr(IP.find(':') + 1);
  q4 = correctQ(q4);
  string port = IP.substr(0);

  string preIP = q1 + q2 + q3 + q4 + port;
  return stoll(preIP);
}

/*
Particion de pivote 
Complejidad O(n)
*/
int part(vector<vector<string>> &bitacora, int first, int last) {
  long long pivot = obtainIP(bitacora[first]);
  int x = first + 1;

  for (int y = x; y <= last; y++) {
    long long IPtemp = obtainIP(bitacora[y]);
    if (IPtemp < pivot) {
      swap(bitacora, x++, y);
    }
  }
  swap(bitacora, first, x - 1);
  return x - 1;
}

// Método de ordenamiento Quick Sort recursivo.
void quickSort(vector<vector<string>> &bitacora, int first, int last) {
  if (first < last) {
    int pos = part(bitacora, first, last);
    quickSort(bitacora, first, pos - 1);
    quickSort(bitacora, pos + 1, last);
  }
}

void quickSort(vector<vector<string>> &bitacora) { // Tiene una complejidad promedio de O(nlogn) y en peor de los casos O(n2)
  quickSort(bitacora, 0, bitacora.size() - 1);
}

string stringReg(vector<string> reg) { // Regresa el registro completo en un string O(1)
  string completo;
  for (int i = 0; i < reg.size() - 1; i++) {
    completo += reg[i] + " ";
  }
  completo = completo + reg[4];
  return completo;
}

int main() {
  vector<vector<string>> bitacora;
  vector<string> registro;
  ifstream lector("bitacora2.txt");
  string linea, mes, hora, dirIP, razon, dia;
  int size = 0;
  int counter = 1;
  while (getline(lector, linea)) // Recorre todas las lineas de la bitacora, separa y almacena sus contenidos O(1)
  {
    registro.clear();

    stringstream ss(linea);
    getline(ss, mes, ' ');
    registro.push_back(mes);
    getline(ss, dia, ' ');
    registro.push_back(dia);
    getline(ss, hora, ' ');
    registro.push_back(hora);
    getline(ss, dirIP, ' ');
    registro.push_back(dirIP);
    getline(ss, razon, '\n');
    registro.push_back(razon);
    bitacora[size];
    bitacora.push_back(registro);
    size++;
  }
  lector.close();

  quickSort(bitacora);

  ofstream escritor(
      "bitacoraOrdenada-Eq#2.txt"); // crea el archivo bitacoraCorrecta.txt con todos los registros ordenados
  if (escritor.is_open()) {
    for (int i = 0; i < bitacora.size(); i++) {
      escritor << stringReg(bitacora[i]) << "\n";
    }
    escritor.close();
  }

  cout << "Bitácora ordenada" << endl;

  MyBST tree; // Crea un arbol vacío
  ifstream file("bitacoraOrdenada-Eq#2.txt");
  string month, day, hour, ip, reas, line2;
  string lastIP = "";
  int count = 1;
  while (getline(file, line2)) { // Almacenamiento de los datos separados por espacios
    stringstream st(line2);
    getline(st, month, ' ');
    getline(st, day, ' ');
    getline(st, hour, ' ');
    getline(st, ip, ':');
    getline(st, reas, '\n');

    if(lastIP == "") { // Aqui es donde se cuentan cuantas veces aparece una direccion ip y se utiliza como key en el arbol BST
      lastIP = ip;
      count--;
    } else {
      if(lastIP  == ip) {
        count++;
      } else {
        count++;
        tree.insert(lastIP, count);
        lastIP = ip;
        count = 0;
      }
    }
  }
  tree.insert(lastIP, count + 1); //Inserta al árbol la ip, así como la cantidad de veces que se registro en la bitácora
  escritor.close();

  cout << "Las 5 direcciones IP con mayor recurrencia son:" << endl << endl;
  tree.printTop(5); //Ip con más recurrencia
}