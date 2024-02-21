#include <iostream>
#include <stdio.h>
#include "gomoryhutree.h"
using namespace std;

int main()
{
    freopen("E:/UTEC/Ciclo 4/AED 2/Gomory-Hu-Tree/input.txt", "r", stdin);
    Graph graph;
    // Leer el grafo desde la entrada estándar
    graph.read_input_file();
    graph.print();
<<<<<<< Updated upstream
    cout << endl;
    cout << graph.bfs(2, 0) << endl;
    cout << endl;
    graph.mgh();

=======
    cout<<endl;
    graph.mgh();
>>>>>>> Stashed changes
    return 0;
}