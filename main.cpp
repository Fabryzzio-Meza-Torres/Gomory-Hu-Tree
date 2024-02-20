#include "GomoryHuTree.h"
#include <iostream>
using namespace std;

int main()
{
    Graph graph;
    freopen("input.txt", "r", stdin);
    graph.read_input_file();
    graph.mgh();

    return 0;
}