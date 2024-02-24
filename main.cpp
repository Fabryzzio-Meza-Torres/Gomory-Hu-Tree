#include <iostream>
#include <stdio.h>
#include "gomoryhutree.h"
using namespace std;

int main()
{
    Graph graph;
    // Leer el grafo desde la entrada estándar
    graph.read_input_file("input.txt");
    graph.print();
    cout << endl;
    cout << graph.bfs(2, 0) << endl;
    cout << "Gomory-Hu Tree"<<endl;
    graph.mgh();
    graph.grabar_datos("output.txt");

    return 0;
}