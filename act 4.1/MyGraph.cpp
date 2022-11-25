/*
Grafo: sus representaciones y sus recorridos
Autor: Ingrid González A01641116
Fecha: 9/11/22

Se utilizó como referencia el libro de la materia:
de la Cueva , V. M., González, L. H., & Salinas, E. G. (2020). Estructuras de
datos y algoritmos fundamentales (Primera). Editorial Digital Tecnológico de
Monterrey. Pág. 256-258.
*/

#include "MyGraph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

MyGraph::MyGraph(vector<vector<int> >& matriz){
    loadGraph(matriz);
};

/*
Almacena el número de nodos y arcos en el grafo.
Complejidad O(1)
*/
void MyGraph::loadGraph(vector<vector<int> >& matriz){
    this -> matriz = matriz;
}

/*
Recorrido de profundidad.
Complejidad O(n)
*/
void MyGraph::DFS(int n){
    stack<int> p;
    int matrixSize = matriz.size();
    int v;
    vector<bool> status(matriz.size(),false);
    
    for(int i = n; i<matrixSize;i++){
        if(!status[i]){
            p.push(i);
            while(!p.empty()){
                v = p.top();
                p.pop();
                if(!status[v]){
                    cout << (v) << ",";
                    status[v] = true;
                    for(int i=matriz[v].size()-1; i>=0; i--){
                        if(!status[matriz[v][i]]){
                            p.push(matriz[v][i]);
                        }
                    }
                }
            }
        }
    }    
    cout << endl;
}

/*
Hace un recorrido por niveles, implementando queue. 
Complejidad O(n + m)
*/
void MyGraph::BFS(int n){
    int matrixSize = matriz.size();
    vector<bool> status(matrixSize, false);
    queue<int> q;
    int v;
    for(int i = n; i<matrixSize; i++){
        if(!status[i]){
            q.push(i);
            status[i]=true;
            while(!q.empty()){
                v = q.front();
                q.pop();
                cout << (v) << ",";
                for(int j=0; j<matrixSize; j++){
                    if(matriz[v][j] && !status[j]){
                        q.push(j);
                        status[j] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}