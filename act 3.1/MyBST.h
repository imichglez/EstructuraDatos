/*
Operaciones avanzadas en un BST.
Autor: Ingrid González A01641116
Fecha: 18/oct/22
*/

#ifndef MYBST_H
#define MYBST_H
#include <iostream>
using namespace std;

struct MyNodeBST {
    int data;
    MyNodeBST *left;
    MyNodeBST *right;

    MyNodeBST(int data){
        this -> data = data;
        this -> left = this -> right = nullptr;
    }
};

class MyBST{
private:
	MyNodeBST *root;
    int size;
    bool search(int data,MyNodeBST *current);
    MyNodeBST* remove(int data,MyNodeBST *current);
    void preorder(MyNodeBST* current);
    void inorder(MyNodeBST* current);
    void posorder(MyNodeBST* current);

    int height(MyNodeBST* current);
    void ancestors(int data, MyNodeBST* current);
    int whatLevelAmI(int data, MyNodeBST* current);

public:
	MyBST();
    int length();
    bool isEmpty();
    bool search(int data);
    bool insert(int data); //true si lo inserto o no
    bool remove(int data); // si el valor estaba en el árbol lo borra 

    void preorder();
    void inorder();
    void posorder();
    void level();

    void visit(int type); // Type: 1->preorder,2->inorder.3->postorder,4->level
    int height(); // Regresa la altura del BST.
    void ancestors(int data);// Imprime los ancestros del valor pasado.
                             // El orden de impresión debe ser de la raíz hacía abajo.
                             // Si valor no se localiza en el árbol no imprime nada
    int whatLevelAmI(int data);// Regresa el nivel en que se encuentra el valor dentro del árbol. 
                               // Si el valor no está en árbol imprime -1.
};

#endif
