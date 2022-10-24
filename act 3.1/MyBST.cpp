/*
Operaciones avanzadas en un BST.
Autor: Ingrid González A01641116
Fecha: 18/oct/22

Se utilizó como referencia el libro de la materia:
de la Cueva , V. M., González, L. H., & Salinas, E. G. (2020). Estructuras de
datos y algoritmos fundamentales (Primera). Editorial Digital Tecnológico de
Monterrey. Pág. 203.
*/

#include "MyBST.h"
#include <iostream>
#include <queue>
using namespace std;

/*
Crea el BST.
Complejidad O(1)
*/
MyBST::MyBST(){
    this -> root = nullptr;
    this -> size = 0;
}

/*
Complejidad O(1)
*/
int MyBST::length(){
    return this -> size;
}

/*
Analiza si el árbol está vacía o no.
Complejidad O(1)
*/
bool MyBST::isEmpty(){
    return this -> size == 0;
}

/*
Busca un valor en el árbol. 
Comlejidad O(n)
*/
bool MyBST::search(int data,MyNodeBST *current){
    if (this->root == nullptr) {
    return false;
  } else if (data < this->root->data) {
    return search(data, this->root->left);
  } else if (data > this->root->data) {
    return search(data, this->root->right);
  } else {
    return true;
  }
}

bool MyBST::search(int data){
    return search(data,this -> root);
}

/*
Inserta un valor al árbol.
Complejidad O(n)
*/
bool MyBST::insert(int data){
    if(isEmpty()){
        this -> root = new MyNodeBST(data);
        this -> size = 1;
        return true;
    } else {
        MyNodeBST *current,
                  *prev;
        current = prev = this -> root;
        while (current != nullptr) {
            prev = current;
            if(data == current -> data){
                return false;
            } else if(data < current -> data){
                current = current -> left;
            } else {
                current = current -> right;
            }
        }
        // prev está apuntando a quien será el padre del nuevo nodo

        if(data < prev -> data){
            prev -> left = new MyNodeBST(data);
        } else {
            prev -> right = new MyNodeBST(data);
        }

        this -> size++;
    }
    return true;
}

/*
Si el valor estaba en el árbol lo borra. 
Complejidad O(n)
*/
MyNodeBST* MyBST::remove(int data, MyNodeBST *current){
    if (current == nullptr) {
    return nullptr;
    }
    if (current -> left == nullptr && current -> right == nullptr) {
        if (current -> data == data) {
        return nullptr;
        } else {
        return current;
        }
    }

    MyNodeBST *dNode = nullptr;
    MyNodeBST *aux;
    MyNodeBST *aux1;
    queue<MyNodeBST *> qDel;
    qDel.push(root);

    while (qDel.empty() == false) {
        aux = qDel.front();
        qDel.pop();
        if (aux -> data == data) {
        dNode = aux;
        }
        if (aux -> left) {
        aux1 = aux;
        qDel.push(aux -> left);
        }
        if (aux -> right) {
        aux1 = aux;
        qDel.push(aux -> right);
        }
    }
    if (dNode != nullptr) {
        dNode -> data = aux -> data;
        if (aux1->right == aux) {
        aux1 -> right = nullptr;
        } else {
        aux1 -> left = nullptr;
        }
    }
    return current;
}

bool MyBST::remove(int data){
    return remove(data,(this->root));
}

/*
Este método recorre el árbol en preOrder.
Comlejidad O(n)
*/
void MyBST::preorder(MyNodeBST* current){
    if(current != nullptr){
        cout << current -> data << " ";
        preorder(current -> left);
        preorder(current -> right);
    }
}

void MyBST::preorder(){
    preorder(this -> root);
}

/*
Este método recorre el árbol en inOrder.
Complejidad O(n)
*/
void MyBST::inorder(MyNodeBST* current){
    if(current != nullptr){
        inorder(current -> left);
        cout << current -> data << " ";
        inorder(current -> right);
    }
}

void MyBST::inorder(){
    inorder(this -> root);
}

/*
Este método recorre el árbol en posOrder.
Complejidad O(n)
*/
void MyBST::posorder(MyNodeBST* current){
    if(current != nullptr){
        posorder(current -> left);
        posorder(current -> right);
        cout << current -> data << " ";
    }
}

void MyBST::posorder(){
    posorder(this -> root);
}

/*
Este metodo recorre en arbol posOrder.
Complejidad O(n)
*/
void MyBST::level(){
    queue<MyNodeBST*> q;
    MyNodeBST *current;
    q.push(this -> root);

    while (!q.empty()) {
        MyNodeBST *current = q.front();
        q.pop();
        cout << current -> data << " ";

        if (current -> left != nullptr)
            q.push(current -> left);
        if (current -> right != nullptr)
            q.push(current -> right);
    }
}

/*
Complejidad O(n)
*/
void MyBST::visit(int type){
    switch (type){
        case 1:
            preorder();
            break;
        case 2:
            inorder();
            break;
        case 3:
            posorder();
            break;
        case 4:
            level();
            break;

        default:
            break;
        }
        cout << endl;
}

/*
Este metodo regresa la altura del árbol.
Complejidad O(n)
*/

int MyBST::height(MyNodeBST* current){
    if(current == nullptr){
        return 0;
        cout << "Árbol vacío" << endl;
    } else {
        int leftS = height(current -> left);
        int rightS = height(current -> right);

        if(leftS > rightS){
            return (leftS +1);
        } else {
            return (rightS +1);
        }
    }
}

int MyBST::height(){
    return height(this -> root);
}

/*
Imprime los ancestros del valor (desde la raíz hacia abajo).
Complejidad O(logn)
*/

void MyBST::ancestors(int data, MyNodeBST* current){
    if (current == nullptr) {
        return;
    } else if (data < current -> data) {
        cout << current -> data << " ";
        ancestors(data, current -> left);
    } else if (data > current -> data) {
        cout << current -> data << " ";
        ancestors(data, current -> right);
    } else {
        return;
    }
}

void MyBST::ancestors(int data){
    return ancestors(data, this -> root);
}

/*
Regresa el nivel en que se encuentra el valor dentro del árbol

Complejidad O(n)
*/
int MyBST::whatLevelAmI(int data, MyNodeBST* current){
    if (current == nullptr) {
        return -1;
    } else if (data < current -> data) {
        return whatLevelAmI(data,current -> left) + 1;
    } else if (data > current -> data) {
        return whatLevelAmI(data, current -> right) + 1;
    } else {
        return 0;
    }
}

int MyBST::whatLevelAmI(int data){
    return whatLevelAmI(data, this -> root);
}