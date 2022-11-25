/*
Grafos: Algoritmos complementarios
Autor: Ingrid González A01641116
Fecha: 18/11/22
*/

#ifndef MYGRAPH2_H
#define MYGRAPH2_H
#include <vector>
using namespace std;

class MyGraph2 {
    private:
        vector<vector<int> > matriz;
        vector<bool> vis;
        vector<int> print;
        int vertex;

    public:
        MyGraph2(vector<vector<int> > &matriz, int vertex);
        void loadGraph(vector<vector<int> > &matriz);
        bool isTreeUtil(int n, bool reached[], int prt);
        bool isTree();
        void DFS2(int n);
        void topologicalSort();
        bool bipartiteGraph();
};

#endif