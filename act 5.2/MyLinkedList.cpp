// Jorge Wolburg A01640826
// Act 2.1: Implementacion de un ADT de estructurras de datos lineal

#include "MyLinkedList.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string cDay(string day){
    if(day.size() >  1){
        return day;
    }else{
        return "0" + day;
    }
}

string numMonth(string month){
    if(month == "Jan"){
        return "01";
    }else if (month == "Feb"){
        return "02";
    }else if (month == "Mar"){
        return "03";
    }else if (month == "Apr"){
        return "04";
    }else if (month == "May"){
        return "05";
    }else if (month == "Jun"){
        return "06";
    }else if (month == "Jul"){
        return "07";
    }else if (month == "Aug"){
        return "08";
    }else if (month == "Sep"){
        return "09";
    }else if (month == "Oct"){
        return "10";
    }else if (month == "Nov"){
        return "11";
    }else if(month == "Dec"){ 
        return "12";
    }else{
        return "10";
    }
}

string nPeriod(string completeHour){
    string hour, min, sec;
    stringstream ss(completeHour);
        getline(ss, hour, ':');
        getline(ss, min, ':');
        getline(ss, sec, ' ');
    
    if(hour.size() <  2){
        hour = "0"+hour;
    }

    return hour + min + sec;
}

int wholeDate(string data){  
    string month, day, hour;
    stringstream ss(data);
        getline(ss, month, ' ');
        getline(ss, day, ' ');
        getline(ss, hour, '\n');
    
    month = numMonth(month);
    day = cDay(day);
    hour = nPeriod(hour);

    string whole = month + day + hour;
    int iDate = stoi(whole);

    return iDate;
}

// Constructor
MyLinkedList::MyLinkedList() { // Complejidad O(1)
  this->size = 0;
  this->head = this->tail = nullptr;
}
// Destructor
MyLinkedList::~MyLinkedList() { // Complejidad O(n)
  MyNodoLL *tmp;
  while (this->head != nullptr) {
    tmp = this->head->next;
    delete this->head;
    this->head = tmp;
    this->size--;
  }
}
// Devuelve el primer elemento de la lista, si la lista esta vacia, lanza una
// excepcion
MyNodoLL *MyLinkedList::first() { // Complejidad O(1)
  return this->head;
}
// Devuelve el primer elemento de la lista, si la lista esta vacia, lanza una
// excepcion
string MyLinkedList::last() { // Complejidad O(1)
  if (this->size > 0) {
    return this->tail->data;
  } else {
    throw invalid_argument("No se puede regresar el ultimo dato de una lista vacia");
  }
}
// Devuelve el tamaño de la lista
int MyLinkedList::length() { // Complejidad O(1)
  return this->size;
}
// Devuelve un 1 si la lista tiene algun elemento y un 0 si esta vacia
bool MyLinkedList::isEmpty() { // Complejidad O(1)
  return this->size == 0;
}
// Inserta un dato en la primera posicion
void MyLinkedList::insertFirst(string key, string data) { // Complejidad O(1)
  /*
  MyNodoLL *tmp = new MyNodoLL(data);
  tmp->next = this->head;
  this->head = tmp;
  */

  this->head = new MyNodoLL(key, data, this->head);
  if (this->size == 0) {
    this->tail = this->head;
  }
  this->size++;
}
// Inserta un dato en la ultima posicion
void MyLinkedList::insertLast(string key, string data) { // Complejidad O(1)
  MyNodoLL *tmp = new MyNodoLL(key, data);
  MyNodoLL *real;
  real = this->head;

  if (this->head == nullptr) {
    this->head = tmp;
  } else {
    while (real->next != nullptr) {
      real = real->next;
      real->next = tmp;
    }
  }
  this->size++;
}
// Inserta un dato en la posicion deseada
void MyLinkedList::insertAt(string key, string data, int pos) { // Complejidad O(n)
  if (this->size > 0) {
    MyNodoLL *tmp = this->head;
    MyNodoLL *real = new MyNodoLL(key, data);
    if (pos >= 0 && pos < this->size) {
      if (pos == 0) {
        insertFirst(key, data);
      } else {
        for (int i = 0; i < pos - 2; i++) {
          tmp = tmp->next;
        }
        real->next = tmp->next;
        tmp->next = real;
        this->size++;
      }
    } else {
      throw invalid_argument("No existen suficientes elemntos en la lista");
    }
  } else {
    throw invalid_argument("No existen suficientes elementos en la lista");
  }
}
// Devuelve el dato de la posicion deseada
string MyLinkedList::getAt(string key) { // Complejidad O(n)
  MyNodoLL *current = this->head;
  for (int i = 0; i < this->size; i++) {
    if (current->key == key) {
      return current->data;
    }
    current = current->next;
  }
  throw invalid_argument("No se encuentra la llave " + key + " en la tabla");
}
//
void MyLinkedList::setAt(int data, int pos) {
  MyNodoLL *tmp = this->head;
  for (int i = 0; i < pos - 1; i++) {
    tmp = tmp->next;
  }
  tmp->data = data;
}
// Elimina el primer dato de la lista
void MyLinkedList::removeFirst() { // Complejidad O(1)
  if (this->size > 0) {
    MyNodoLL *tmp = this->head;
    this->head = this->head->next;
    delete tmp;
    if (size == 1) {
      this->tail = nullptr;
    }
    this->size--;
  } else {
    throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
  }
}
// Elimina el ultimo dato de la lista
void MyLinkedList::removeLast() { // Complejidad O(n)
  if (this->size > 0) {
    MyNodoLL *tmp = this->head;
    for (int i = 0; i < this->size - 2; i++) {
      tmp = tmp->next;
    }
    // tmp ya esta en una poscion atras de tail
    tmp->next = nullptr;
    delete this->tail;
    this->tail = tmp;
    this->size--;
  }
}
// Elimina el dato de la posicion deseada
void MyLinkedList::removeAt(int pos) { // Complejidad O(n)
  if (this->size > 0) {
    MyNodoLL *tmp = this->head;
    MyNodoLL *del;
    if (pos >= 0 && pos < this->size) {
      if (pos == 0) {
        removeFirst();
      } else {
        for (int i = 0; i < pos - 2; i++) {
          tmp = tmp->next;
        }
        del = tmp->next;
        tmp->next = del->next;
        delete del;
        this->size--;
      }
    } else {
      throw invalid_argument("No se puede eliminar el elemento ya que la lista "
                             "esta fuera de limite");
    }
  } else {
    throw invalid_argument(
        "No se puede eliminar un elemento de una lista vacia");
  }
}

int MyLinkedList::searchKey(string key) {
  MyNodoLL *current = this->head;
  for (int i = 0; i < this->size; i++) {
    if (current->key == key) {
      return i;
    }
    current = current->next;
  }
  return -1;
}

// Sobrecarga de operador <<
ostream &operator<<(ostream &os, const MyLinkedList &ll) {
  MyNodoLL *tmp = ll.head;
  for (int i = 0; i < ll.size; i++) {
    os << tmp->data << "\n";
    tmp = tmp->next;
  }
  return os;
}

MyNodoLL* MyLinkedList::getNodo(int pos){ //Regresa el MyNodeLL en la posicion deseada de la lista
   MyNodoLL* current = this->head;
   if(pos>=0 && pos<this->size){
        for(int i=0; i < pos; i++){
            current = current->next;
        }
   }else{
       throw invalid_argument("No se puede acceder a la posicion " + to_string(pos)+ " en una lista de tamano " + to_string(this->size));
   }
    return current;
}

void MyLinkedList::getData(){
    MyNodoLL* current = this->head;
    while(current != nullptr){
        cout<<current->data<<endl;
        current = current->next;
    }
}

void MyLinkedList::swap(MyNodoLL* one, MyNodoLL* two){ //Intercambia la data de un MyNodeLL por la del otro
    string tempData = one->data;
    one->data = two->data;
    two->data = tempData;
}

int MyLinkedList::part(int start, int end){ //Particion de pivote en quicksort
    int pivot = wholeDate(getNodo(start)->data);
    int x = start + 1;

    for(int y = x; y <= end; y++){
        int IPtemp = wholeDate(getNodo(y)->data);
        if(IPtemp < pivot){
            MyNodoLL* currentX = getNodo(x++);
            MyNodoLL* currentY = getNodo(y);
            swap(currentX, currentY);
        }
    }
    MyNodoLL* iniN = getNodo(start);
    MyNodoLL* minX = getNodo(x-1);
    swap(iniN,minX);
    return x-1;
}

void MyLinkedList::quickSort(int start, int end){ //Quicksort
    if (start < end){
        int pos = part(start, end);
        quickSort(start, pos-1);
        quickSort(pos+1, end);
    }
}

void MyLinkedList::quickSort(){ //Inicializa el quicksort
    quickSort(0, this->size -1);
}