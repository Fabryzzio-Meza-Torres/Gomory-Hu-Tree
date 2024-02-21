#include <iostream>
#include "gomoryhutree.h"

int main() {
	freopen("input.txt", "r", stdin);

    Graph graph;

    // Leer el grafo desde la entrada estándar
    graph.read_input_file();

    cout<< graph.bfs(0, 2)<<endl;
    return 0;
}
