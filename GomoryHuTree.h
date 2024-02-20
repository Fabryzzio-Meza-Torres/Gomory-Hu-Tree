#include <iostream>
#include <stdio.h>
#include "queue.h"

using namespace std;

#define Max_nodes 5000
#define oo 1000000000
constexpr int White = 0;
constexpr int Gray = 1;
constexpr int Black = 2;

class Graph
{
private:
  int num_nodes{};
  int num_edges{};
  int capacity[Max_nodes][Max_nodes];
  int flow[Max_nodes][Max_nodes];
  int color[Max_nodes];
  int pred[Max_nodes];
  int tree[Max_nodes][Max_nodes];
  Queue<int> queue;

public:
  int minimun(int a, int b)
  {
    return a > b ? b : a;
  }
  int bfs(int start, int target)
  {
    int u, v;
    for (u = 0; u < num_nodes; u++)
    {
      color[u] = White;
    }
    queue.enqueue(start);
    pred[start] = -1;
    while (!queue.isEmpty())
    {
      u = queue.dequeue();
      for (v = 0; v < num_nodes; v++)
      {
        if (color[v] == White && capacity[u][v] - flow[u][v] > 0)
        {
          queue.enqueue(v);
          pred[v] = u;
        }
      }
    }

    return color[target] == Black;
  }

  int Ford_Fulkerson(int source, int sink)
  {
    int i, j, u;
    int max_flow = 0;
    for (i = 0; i < num_nodes; i++)
    {
      for (j = 0; j < num_nodes; j++)
      {
        flow[i][j] = 0;
      }
    }
    while (bfs(source, sink))
    {
      int increment = oo;
      for (u = sink; pred[u] != (-1); u = pred[u])
      {
        increment = minimun(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
      }
      for (u = sink; pred[u] != (-1); u = pred[u])
      {
        flow[pred[u]][u] += increment;
        flow[u][pred[u]] -= increment;
      }
      max_flow += increment;
    }
    return max_flow;
  }

  void read_input_file()
  {
    int a, b, c, i, j;

    cin >> num_nodes >> num_edges;

    for (i = 0; i < num_nodes; i++)
    {
      for (j = 0; j < num_nodes; j++)
      {
        capacity[i][j] = 0;
      }
    }

    for (i = 0; i < num_edges; i++)
    {
      cin >> a >> b >> c;
      capacity[a][b] = c;
      capacity[b][a] = c;
    }
  }

  void mgh(){
    short p[Max_nodes], f1 [Max_nodes], corteMin, t ;
    for(int i=0; i<num_nodes;i++){
      //Inicializamos el arreglo de supernodos(p) y los flujos maximos de los supernodos(f1)
      p[i]=0;
      f1[i]=0;
      for(int j=0;j<num_nodes;j++){
        //Inicializamos el flujo maximo entre los supernodos i j 
        tree[i][j]=0;
      }
    }

    for(int source=1; source<num_nodes; source++){
      short sink=p[source];

      corteMin= Ford_Fulkerson(source, sink);
    }
  }
};