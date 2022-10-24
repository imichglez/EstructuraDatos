/*
Operaciones avanzadas en un BST.
Autor: Ingrid González A01641116
Fecha: 18/oct/22
*/

#include <iostream>
#include "MyBST.h"

int main(){
    // test 1
    /*

        21
      /    \
     13     33
    /  \   /  \
   10  18 25  40

    */
    MyBST arbol;
    cout << "---- TEST 1 ----" << endl;
    arbol.insert(21);
    arbol.insert(13);
    arbol.insert(33);
    arbol.insert(10);
    arbol.insert(18);
    arbol.insert(25);
    arbol.insert(40);

    cout << "preOrder: ";
    arbol.preorder(); // 21, 13, 10, 18, 33, 25, 40
    cout << endl;

    cout << "inOrder: ";
    arbol.inorder(); // 10, 13, 18, 21, 25, 33, 40
    cout << endl;

    cout << "posOrder: ";
    arbol.posorder(); // 10, 18, 13, 25, 40, 33, 21 
    cout << endl;

    cout << "levelOrder: ";
    arbol.level(); // 21, 13, 33, 10, 18, 25, 40 
    cout << endl;

    cout << "visit case 1 (preOrder): ";
    arbol.visit(1) ;
    cout << endl;

    cout << "Altura del árbol: " << arbol.height() << endl; // 3

    cout << "Ancestros número 13: "; //21
    arbol.ancestors(13);
    cout << endl;

    cout << "En qué nivel estoy para el número 13: " << arbol.whatLevelAmI(13) << endl; // 1 

    // ---------------------------------------------------------------------------------------- //

    // test 2
    /*

        5
       /  \
      3    7
    /  \    \
   1    4     8

    */
    
    MyBST arbol1;
    cout << "---- TEST 2 ----" << endl;
    arbol1.insert(5);
    arbol1.insert(3);
    arbol1.insert(4);
    arbol1.insert(1);
    arbol1.insert(7);
    arbol1.insert(8);

    cout << "preOrder: ";
    arbol1.preorder(); // 5, 3, 1, 4, 7, 8
    cout << endl;

    cout << "inOrder: ";
    arbol1.inorder(); // 1, 3, 4, 5, 7, 8
    cout << endl;

    cout << "posOrder: ";
    arbol1.posorder(); // 1, 4, 3, 8, 7, 5
    cout << endl;

    cout << "levelOrder: ";
    arbol1.level(); // 5, 3, 7, 1, 4, 8
    cout << endl;

    cout << "visit case 2 (inOrder): ";
    arbol1.visit(2) ;
    cout << endl;

    cout << "Altura del árbol: " << arbol1.height() << endl; // 3

    cout << "Ancestros número 1: "; // 5, 3
    arbol1.ancestors(1);
    cout << endl;
    
    cout << "En qué nivel estoy para el número 4: " << arbol1.whatLevelAmI(4) << endl; // 2

    // ---------------------------------------------------------------------------------------- //

    // test 3
    /*

        4
      /   \
     2     8
    / \   /  \
   1   3 6    9

    */

    MyBST arbol2;
    cout << "---- TEST 3 ----" << endl;
    arbol2.insert(4);
    arbol2.insert(2);
    arbol2.insert(8);
    arbol2.insert(1);
    arbol2.insert(3);
    arbol2.insert(6);
    arbol2.insert(9);

    cout << "preOrder: ";
    arbol2.preorder(); // 4, 2, 1, 3, 8, 6, 9
    cout << endl;

    cout << "inOrder: ";
    arbol2.inorder(); // 1, 2, 3, 4, 6, 8, 9
    cout << endl;

    cout << "posOrder: ";
    arbol2.posorder(); // 1, 3, 2, 6, 9, 8, 4
    cout << endl;

    cout << "levelOrder: ";
    arbol2.level(); // 4, 2, 8, 1, 3, 6, 9
    cout << endl;

    cout << "visit case 3 (posOrder): ";
    arbol2.visit(3) ;
    cout << endl;

    cout << "Altura del árbol: " << arbol2.height() << endl; // 3

    cout << "Ancestros número 8: "; // 4
    arbol2.ancestors(8);
    cout << endl;
    
    cout << "En qué nivel estoy para el número 4: " << arbol2.whatLevelAmI(4) << endl; // 0

    // ---------------------------------------------------------------------------------------- //

    // test 4
    /*

        8
      /   \
     3    10
    / \     \
   1   6     14
      / \    /
     4   7  13

    */
    MyBST arbol3;
    cout << "---- TEST 4 ----" << endl;
    arbol3.insert(8);
    arbol3.insert(3);
    arbol3.insert(10);
    arbol3.insert(1);
    arbol3.insert(6);
    arbol3.insert(14);
    arbol3.insert(4);
    arbol3.insert(7);
    arbol3.insert(13);

    cout << "preOrder: "; // 8, 3, 1, 6, 4, 7, 10, 14, 13
    arbol3.preorder(); 
    cout << endl;

    cout << "inOrder: ";
    arbol3.inorder(); // 1, 3, 4, 6, 7, 8, 10, 13, 14 
    cout << endl;

    cout << "posOrder: ";
    arbol3.posorder(); // 1, 4, 7, 6, 3, 13, 14, 10, 8, 
    cout << endl;

    cout << "levelOrder: ";
    arbol3.level(); // 8, 3, 10, 1, 6, 14, 4, 7, 13 
    cout << endl;

    cout << "visit case 4 (levelOrder): ";
    arbol3.visit(4) ;
    cout << endl;

    cout << "Altura del árbol: " << arbol3.height() << endl; // 4

    cout << "Ancestros número 4: "; // 8, 3, 6
    arbol3.ancestors(4);
    cout << endl;

    cout << "En qué nivel estoy para el número 4: " << arbol3.whatLevelAmI(4) << endl; // 3

    arbol3.remove(4);
    arbol3.remove(13);
    arbol3.remove(7);
    cout << "Removemos los datos 4, 7, 13. La nueva altura del árbol es: " << arbol3.height() << endl; // 3
    return 0;
}