#include <iostream>
#include "queue.h"

using namespace std;

#define Max_nodes 5000
#define oo 1000000000000
constexpr int White = 0;
constexpr int Gray = 1;
constexpr int Black = 2;

class Graph
{
  int num_nodes{};
  int num_edges{};
  int capacity[Max_nodes][Max_nodes];
  int flow[Max_nodes][Max_nodes];
  int color[Max_nodes];
  int pred[Max_nodes];
  int tree[Max_nodes][Max_nodes];

  int minimun(int a, int b)
  {
    return a > b ? b : a;
  }
};