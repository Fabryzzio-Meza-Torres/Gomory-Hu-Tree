#ifndef GOMORYHUTREE_H
#define GOMORYHUTREE_H

#include <iostream>
#include <stdio.h>
using namespace std;

constexpr int Max_nodes = 5000;
constexpr int oo = 1000000000;
constexpr int White = 0;
constexpr int Gray = 1;
constexpr int Black = 2;
int num_nodes;
int num_edges;
short capacity[Max_nodes][Max_nodes];
short flow[Max_nodes][Max_nodes];
short color[Max_nodes];
short pred[Max_nodes];
short tree[Max_nodes][Max_nodes];
using namespace std;
class Graph
{
public:
  int minimun(int a, int b)
  {
    return a > b ? b : a;
  }

  int bfs(int source, int sink)
  {
    int i, j, u, v;
    for (i = 0; i < num_nodes; i++)
    {
      color[i] = White;
    }
    color[source] = Gray;
    pred[source] = (-1);
    for (i = 0; i < num_nodes; i++)
    {
      pred[i] = (-1);
    }
    int head = 0;
    int tail = 0;
    int q[Max_nodes];
    q[tail] = source;
    tail++;
    while (head < tail)
    {
      u = q[head];
      head++;
      for (v = 0; v < num_nodes; v++)
      {
        if (color[v] == White && (capacity[u][v] - flow[u][v]) > 0)
        {
          color[v] = Gray;
          pred[v] = u;
          q[tail] = v;
          tail++;
        }
      }
      color[u] = Black;
    }
    return (color[sink] == Black);
  }

  void print_tree()
  {
    int i, j;
    for (i = 0; i < num_nodes; i++)
    {
      for (j = 0; j < num_nodes; j++)
      {
        std::cout << tree[i][j] << " ";
      }
      std::cout << std::endl;
    }
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

  void print()
  {
    cout << "num_node " << num_nodes << endl;
    cout << "num_edges " << num_edges << endl;
    cout << "capacity matriz: " << endl;
    for (int i = 0; i < num_nodes; i++)
    {
      for (int j = 0; j < num_nodes; j++)
      {
        cout << capacity[i][j] << " ";
      }
      cout << endl;
    }
  }

  void mgh()
  {
    short i, j, s, p[Max_nodes], t, pos, f1[Max_nodes], minimumCut;

    for (i = 0; i < num_nodes; i++)
    {
      p[i] = 0;
      f1[i] = 0;
      for (j = 0; j < num_nodes; j++)
      {
        tree[i][j] = 0;
      }
    }

    for (s = 1; s < num_nodes; s++)
    {

      // Initialize sink
      t = p[s];

      // Calculate the minimum cut
      minimumCut = Ford_Fulkerson(s, t);

      f1[s] = minimumCut;

      /*for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          tree[i][j] = 0;
        }
      }*/

      // Mark the nodes in the supernode with its representative
      for (i = 0; i < num_nodes; i++)
      {
        if (i != s && p[i] == t && color[i] == Black)
        {
          p[i] = s;
        }
      }

      // Change the label
      if (color[p[t]] == Black)
      {
        p[s] = p[t];
        p[t] = s;
        f1[s] = f1[t];
        f1[t] = minimumCut;
      }

      // Store the final cut tree when s is the last node of the input graph.
      if (s == num_nodes - 1)
      {
        for (i = 1; i <= s; i++)
        {
          tree[i][p[i]] = f1[i];
        }
      }
    }

    // Print the Cut Tree
    printf("\n");
    for (i = 0; i < num_nodes; i++)
      for (j = 0; j < num_nodes; j++)
        if (tree[i][j] > 0)
          printf("%d %d %d\n", i, j, tree[i][j]);
  }
};

#endif
