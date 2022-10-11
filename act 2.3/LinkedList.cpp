#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/*
Inicializador de la lista
Complejidad O(1)
*/
LinkedList::LinkedList() {
  this->size = 0;
  this->head = this->tail = nullptr;
}

/*
Regresa el tamano de la bitacora
Complejidad O(1)
*/
int LinkedList::getSize() { return this->size; }

/*
Confirma que el tamano del cuarteto sea de 3, por lo contrario se agregan 0s a
la izquierda Complejidad O(n)
*/
string LinkedList::ipValidate(string &a) {
  string valid;
  valid = a;
  if (valid.size() == 3) {
    return valid;
  } else {
    while (valid.size() < 3) {
      valid = "0" + valid;
    }
    return valid;
  }
}

/*
Obtiene la direccion IP de la linea completa y lo transforma en long long
Complejidad O(1)
*/
long long LinkedList::ipGetter(string data) {
  string quit = data.substr(15);
  bool stop = 0;
  if (quit.find(' ') == 0) {
    quit = quit.substr(1);
  }

  string IP = quit.substr(0, quit.find(' '));

  string a1 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  a1 = ipValidate(a1);

  string a2 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  a2 = ipValidate(a2);

  string a3 = IP.substr(0, IP.find('.'));
  IP = IP.substr(IP.find('.') + 1);
  a3 = ipValidate(a3);

  string a4 = IP.substr(0, IP.find(':'));
  IP = IP.substr(IP.find(':') + 1);
  a4 = ipValidate(a4);
  string port = IP.substr(0);

  string preIP = a1 + a2 + a3 + a4 + port;
  return stoll(preIP);
}

/*
Convierte la direccion IP ingresada por el usuario a un long long y confirma el
tamano del cuarteto Complejidad O(1)
*/
long long LinkedList::ipLong(string bIP) {
  string a1 = bIP.substr(0, bIP.find('.'));
  bIP = bIP.substr(bIP.find('.') + 1);
  a1 = ipValidate(a1);

  string a2 = bIP.substr(0, bIP.find('.'));
  bIP = bIP.substr(bIP.find('.') + 1);
  a2 = ipValidate(a2);

  string a3 = bIP.substr(0, bIP.find('.'));
  bIP = bIP.substr(bIP.find('.') + 1);
  a3 = ipValidate(a3);

  string a4 = bIP.substr(0, bIP.find(':'));
  bIP = bIP.substr(bIP.find(':') + 1);
  a4 = ipValidate(a4);
  string port = bIP.substr(0);

  string preBIP = a1 + a2 + a3 + a4 + port;
  return stoll(preBIP);
}

/*
Inserta un nuevo nodo al final de la lista
Complejidad O(1)
*/
void LinkedList::insertLast(string data) {
  MyNodeLL *ult = this->tail;
  this->tail = new MyNodeLL(data, nullptr, ult);
  if (this->size == 0) {
    this->head = this->tail;
  } else {
    ult->next = this->tail;
  }
  this->size++;
}

/*
Regresa el MyNodeLL en la posicion deseada de la lista
Complejidad O(n)
*/
MyNodeLL *LinkedList::getAt(int pos) {
  MyNodeLL *current = this->head;
  if (pos >= 0 && pos < this->size) {
    for (int i = 0; i < pos; i++) {
      current = current->next;
    }
  } else {
    throw invalid_argument("No se puede acceder a la posicion " + to_string(pos) + " en una lista de tamano " + to_string(this->size));
  }
  return current;
}

/*
Intercambia la data de un MyNodeLL por la del otro
Complejidad O(1)
*/
void LinkedList::swap(MyNodeLL *i, MyNodeLL *j) {
  string temp = i->data;

  i->data = j->data;
  j->data = temp;
}

/*
Particion de pivote en quicksort
Complejidad O(n)
*/
int LinkedList::part(int ini, int fin) {
  long long pivot = ipGetter(getAt(ini)->data);
  int i = ini + 1;

  for (int j = i; j <= fin; j++) {
    long long IPtemp = ipGetter(getAt(j)->data);
    if (IPtemp < pivot) {
      MyNodeLL *icurrent = getAt(i++);
      MyNodeLL *jcurrent = getAt(j);
      swap(icurrent, jcurrent);
    }
  }
  MyNodeLL *iniN = getAt(ini);
  MyNodeLL *minX = getAt(i - 1);
  swap(iniN, minX);
  return i - 1;
}

/*
Ordenamiento por Quicksort
Complejidad O(1)
*/
void LinkedList::quickSort(int ini, int fin) {
  if (ini < fin) {
    int pos = part(ini, fin);
    quickSort(ini, pos - 1);
    quickSort(pos + 1, fin);
  }
}

/*
Inicializa el quicksort
Complejidad O(1)
*/
void LinkedList::quickSort() { 
  quickSort(0, this->size - 1); 
}

/*
Genera una busqueda binaria comparando el long long de la direccion IP
Complejidad O(n)
*/
int LinkedList::binarySearch(long long IP) {
  int inicio = 0;
  int fin = this->size - 1;

  while (inicio <= fin) {
    int mitad = (inicio + fin) / 2;

    if (IP == ipGetter(getAt(mitad)->data)) {
      return mitad;
    } else if (IP < ipGetter(getAt(mitad)->data)) {
      fin = mitad - 1;
    } else {
      inicio = mitad + 1;
    }
  }
  return inicio;
}

/*
Sobrecarga del operador
Complejidad O(n)
*/
ostream &operator<<(ostream &os, const LinkedList &ll) {
  MyNodeLL *current = ll.head;
  for (int i = 0; i < ll.size; i++) {
    os << current->data << endl;
    current = current->next;
  }
  os << endl;
  return os;
}