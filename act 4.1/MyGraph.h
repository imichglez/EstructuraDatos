/*
Grafo: sus representaciones y sus recorridos
Autor: Ingrid González A01641116
Fecha: 9/11/22
*/

#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>
using namespace std;

class MyGraph {
private:
    vector<vector<int> > matriz;
public:
    MyGraph(vector<vector<int> > &matriz);
    void loadGraph(vector<vector<int> > &matriz);
    void DFS(int n);
    void BFS(int n);
};

// print: A,B,C,D....

#endif