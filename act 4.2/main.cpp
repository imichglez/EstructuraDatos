/*
Grafos: Algoritmos complementarios
Autor: Ingrid González A01641116
Fecha: 18/11/22
*/

#include "MyGraph2.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // test 1
    vector<vector<int> > matrix1 = {{0, 1, 0, 1},
                                    {1, 0, 1, 0},
                                    {0, 1, 0, 1},
                                    {1, 0, 1, 0}};

    MyGraph2 graph(matrix1, 0);
    cout << "---- TEST 1 ----" << endl;
    graph.isTree() ? cout << "Si es árbol" : cout << "No es árbol" << endl; // no es 

    cout << "Orden topológico del grafo: "; // 3, 2, 1 , 0
    graph.topologicalSort();
    cout << endl;

    graph.bipartiteGraph() ? cout << "Es bipartito" : cout << "No es bipartito"; // si es 
    cout << endl;

    // -----------------------------------------------------------------------------------

    // test 2
    vector<vector<int> > matrix2 = {{0, 1, 1, 1}, 
                                    {1, 0, 1, 0}, 
                                    {1, 1, 0, 0}, 
                                    {1, 0, 0, 0}};
    
    MyGraph2 graph1(matrix2, 0);
    cout << "\n---- TEST 2 ----" << endl;
    graph1.isTree() ? cout << "Si es árbol" : cout << "No es árbol" << endl; // no es 

    cout << "Orden topológico del grafo: ";
    graph1.topologicalSort(); // 3, 2, 1, 0
    cout << endl;

    graph1.bipartiteGraph() ? cout << "Es bipartito" : cout << "No es bipartito" << endl; // no es

    // -----------------------------------------------------------------------------------

    // test 3

    vector<vector<int> > matrix3 = {{0, 0, 0, 1, 1}, 
                                    {0, 0, 1, 0, 1}, 
                                    {0, 1, 0, 1, 0}, 
                                    {1, 0, 1, 0, 0},
                                    {1, 1, 0, 0, 0}};
    
    MyGraph2 graph2(matrix3, 0);
    cout << "\n---- TEST 3 ----" << endl;
    graph2.isTree() ? cout << "Si es árbol" : cout << "No es árbol" << endl; // no es 

    cout << "Orden topológico del grafo: ";
    graph2.topologicalSort();
    cout << endl;

    graph2.bipartiteGraph() ? cout << "Es bipartito" : cout << "No es bipartito" << endl; // no es

    // -----------------------------------------------------------------------------------

    // test 4
    
    vector<vector<int> > matrix4 = {{0, 0, 0, 1, 1, 1}, 
                                    {0, 0, 0, 1, 1, 1}, 
                                    {0, 0, 0, 1, 1, 1}, 
                                    {1, 1, 1, 0, 0, 0},
                                    {1, 1, 1, 0, 0, 0},
                                    {1, 1, 1, 0, 0, 0}};
    
    MyGraph2 graph3(matrix4, 0);
    cout << "\n---- TEST 4 ----" << endl;
    graph3.isTree() ? cout << "Si es árbol" : cout << "No es árbol" << endl; // no es 

    cout << "Orden topológico del grafo: "; // 5, 2, 4, 1, 3, 0
    graph3.topologicalSort();
    cout << endl;

    graph3.bipartiteGraph() ? cout << "Es bipartito" : cout << "No es bipartito"; // si es

    return 0;
}