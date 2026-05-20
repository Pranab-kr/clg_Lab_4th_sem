#include <stdio.h>

#define INF 999

int parent[10];

int find(int i) {
  while (parent[i]) {
    i = parent[i];
  }

  return i;
}

int uni(int i, int j) {
  if (i != j) {
    parent[j] = i;
    return 1;
  }

  return 0;
}

int main() {
  int cost[10][10];
  int n, i, j;

  int min, minCost = 0;
  int a, b, u, v;
  int edge = 1;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);

      if (cost[i][j] == 0) {
        cost[i][j] = INF;
      }
    }
  }

  while (edge < n) {
    min = INF;

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (cost[i][j] < min) {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }

    u = find(u);
    v = find(v);

    if (uni(u, v)) {
      printf("Edge %d : (%d - %d) cost = %d\n", edge, a, b, min);

      minCost = minCost + min;

      edge++;
    }

    cost[a][b] = cost[b][a] = INF;
  }

  printf("Minimum Cost = %d", minCost);

  return 0;
}
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 2 0 6
// 2 0 3 8
// 0 3 0 0
// 6 8 0 0
//
// Edge 1 : (0 - 1) cost = 2
// Edge 2 : (1 - 2) cost = 3
// Edge 3 : (0 - 3) cost = 6
// Minimum Cost = 11
