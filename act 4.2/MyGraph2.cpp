/*
Grafos: Algoritmos complementarios
Autor: Ingrid González A01641116  
Fecha: 18/11/22

Referencias:
Check if a given graph is tree or not - GeeksforGeeks. (2014, October 20). 
GeeksforGeeks. https://www.geeksforgeeks.org/check-given-graph-tree/

Topological Sorting - Algorithms for Competitive Programming. (2022). 
Cp-Algorithms.com. https://cp-algorithms.com/graph/topological-sort.html#the-algorithm
*/

#include "MyGraph2.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/*	
Constructor del grafo. Inicializa el atributo matriz.
Complejidad O(1)
*/
MyGraph2::MyGraph2(vector<vector<int> >& matriz, int vertex){
    loadGraph(matriz);
    this -> vertex = vertex;
};

/*
Carga los arcos del grafo y los almacena en una matriz de adyacencia.
Complejidad O(1)
*/
void MyGraph2::loadGraph(vector<vector<int> >& matriz){
    this -> matriz = matriz;
}

/*
Función recursiva de isTree.
Complejidad O(n)
*/
bool MyGraph2::isTreeUtil(int n, bool reached[], int prt){
    reached[n] = true;
    vector<int> :: iterator itr;
    for(itr = matriz[n].begin(); itr != matriz[n].end(); ++itr){
        if(!reached[*itr]){
            if(isTreeUtil(*itr, reached, n))
            return true;
        } else if (*itr != prt)
        return true;
    }
    return 0;
}

/*
Dice si el Grafo Dirigido (DAG) es un árbol o no.
Complejidad O(n^2)
*/
bool MyGraph2::isTree(){
    bool *reached = new bool[vertex];
    for(int i = 0; i < vertex; i++){
        reached[i] = 0;
    }

    if(isTreeUtil(0, reached, -1)){
        return 0;
    }

    for(int j = 0; j < vertex; j++){
        if(!reached[j]){
            return false;
        }
    }
    return true;
}

// Método 
void MyGraph2::DFS2(int n){
    vis[n] = 1;
    for(int i : matriz[n]){
        if(! vis[i]){
            DFS2(i);
        }
    }
    print.push_back(n);
}

/*
Imprime en forma ascendente los datos en orden topológico.
Complejidad O()
*/
void MyGraph2::topologicalSort(){
    vis.assign(vertex, 0);
    print.clear();

    for(int i = 0; i < vertex; ++i){
        if(!vis[i]){
            DFS2(i);
        }
    }

    // impresión de resultados
    for(int j = 0; j < vertex; j++){
        cout << print[j];
    }
}

/*
Dice si el grafo puede ser representado como grafo bipartito (coloración de grafos).
Complejidad O(n^2)
*/
bool MyGraph2::bipartiteGraph(){
    int n;
    vector<int> tmp(matriz.size(), false);
    vector<int> color(matriz.size(), false);
    // color rojo = 1
    // color azul = 0
    queue<int> q;

    color[0] = 1;
    for(int i = 0; i < matriz.size(); i++){
        if(tmp[i] == 0){
            q.push(i);
            tmp[i] = 1;
            while (!q.empty()){
                n = q.front();
                q.pop();
                for(int j = 0; j < matriz.size(); j++){
                    if(matriz[n][j] == 1){
                        if (tmp[j] == 0){
                            q.push(j);
                            tmp[j] = true;
                            if(color[n] == 1){ 
                                color[j] = 0; // color azul
                            } else {
                                color[j] = 1; // color rojo
                            }
                        } else {
                            if(color[n] == color[j]){
                                return 0;
                            }
                        }
                    }
                }
            }            
        }
    }
    return true;
    cout << endl;
}