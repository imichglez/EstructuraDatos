#include "MyBST.h"
#include <iostream>
#include <queue>

using namespace std;

/*
Crea el BST.
Complejidad O(1)
*/
MyBST::MyBST() {
  this->root = nullptr;
  this->size = 0;
}

int MyBST::length() { // Complejidad O(1)
  return length(this->root);
}

int MyBST::length(MyNodeBST *current) { // Complejidad O(n)
  if (current == nullptr) {
    return 0;
  } else {
    return (length(current->left) + 1 + length(current->right));
  }
}

/*
Analiza si el árbol está vacío o no.
Complejidad O(1)
*/
bool MyBST::isEmpty() { 
  return this->size == 0;
}

MyNodeBST *MyBST::insert(MyNodeBST *current, string data, int key) { // inserta un valor en el árbol
  if(current == nullptr) {
    return new MyNodeBST(data, key);
  } else if(key < current->key) {
    MyNodeBST *nvo = insert(current->left, data, key);
    if(nvo != nullptr) {
      current->left = nvo;
      return current;
    } else {
      return nullptr;
    }
  } else {
    MyNodeBST *nvo = insert(current->right, data, key);
    if(nvo != nullptr){
      current->right = nvo;
      return current;
    } else{
      return nullptr;
    }
  }
}

/*
Inserta un valor al árbol.
Complejidad O(n)
*/
bool MyBST::insert(string data, int key) {
  if(this->root == nullptr) {
    this->root = new MyNodeBST(data, key);
    this->size++;
    return true;
  } else {
    MyNodeBST *nvo = insert(this->root, data, key);
    if(nvo != nullptr) {
      this->size++;
      return true;
    } else {
      return false;
    }
  }
}

void MyBST::printTop(int n) { // Imprime las direcciones IP con mayor cantidad de accesos, recibiendo la cantidad que quiere que se imprima Complejidad O(1) ya que inicializa la busqueda
  if (this->size < n) {
    cout << "La bitacora tiene menos que " << n << " direcciones IP." << endl;
  } else {
    int j = 0;
    printTop(this->root, n, j);
  }
}

void MyBST::printTop(MyNodeBST *current, int n, int &j) { // Recorrido de busqueda de los valores mayores del arbol O(log n) mejor caso, O(n) peor caso
  if (current != nullptr) {
    printTop(current->right, n, j);
    j++;
    if (j <= n) {
      cout << j << "." << " " << current->data << " cuenta con " << current->key << " accesos registrados en la bitacora" << endl;
      cout << endl;
    }
    printTop(current->left, n, j);
  }
}
