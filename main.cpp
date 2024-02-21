#include <iostream>
#include "gomoryhutree.h"

int main() {
	freopen("input.txt", "r", stdin);

    Graph graph;

    // Leer el grafo desde la entrada estándar
    graph.read_input_file();
    graph.print();
    //cout<< graph.bfs(2,0)<<endl;
    return 0;
}
