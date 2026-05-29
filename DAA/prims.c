#include <stdio.h>

#define INF 999

int main() {
  int cost[10][10];
  int visited[10];

  int n, i, j;
  int edge = 1;
  int min, a, b;
  int minCost = 0;

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

  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  visited[0] = 1;

  while (edge < n) {
    min = INF;

    for (i = 0; i < n; i++) {
      if (visited[i] == 1) {
        for (j = 0; j < n; j++) {
          if (visited[j] == 0 && cost[i][j] < min) {
            min = cost[i][j];
            a = i;
            b = j;
          }
        }
      }
    }

    printf("Edge %d : (%d - %d) cost = %d\n", edge, a, b, min);

    minCost = minCost + min;

    visited[b] = 1;

    edge++;
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
