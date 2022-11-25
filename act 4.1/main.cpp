/*
Grafo: sus representaciones y sus recorridos
Autor: Ingrid González A01641116
Fecha: 9/11/22
*/

#include "MyGraph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int> > adjMatrix = {{0, 1, 0, 0}, 
                                    {0, 0, 1, 0}, 
                                    {1, 0, 0, 1}, 
                                    {0, 1, 0, 0}};

  MyGraph graph(adjMatrix);
  cout << "---- DFS ----" << endl;
  graph.DFS();
  cout << endl;

  cout << "\n---- BFS ----" << endl;
  graph.BFS();
}