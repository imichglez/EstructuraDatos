#ifndef MYBST_H
#define MYBST_H
#include <iostream>
using namespace std;

struct MyNodeBST {
  string data;
  int key;
  MyNodeBST *left, *right;
  MyNodeBST(string data, int key) {
    this->data = data;
    this->key = key;
    this->left = this->right = nullptr;
  }
};

class MyBST {
private:
  int size;
  MyNodeBST *root;
  MyNodeBST *insert(MyNodeBST *current, string data, int key);
  int length(MyNodeBST *current);
  void printTop(MyNodeBST *current, int n, int &j);
  // En caso de hacer alguno de los métodos recursivos y necesiten
  // otro método que haga la recursión deben de colocarlo como privado
  // sólo la función de preparación sería pública
public:
  MyBST();
  int length();
  bool isEmpty();
  bool insert(string data, int key); // true si lo inserto o no
  int height();         // regresa la altura del BST.
  void printTop(int n);

};
#endif