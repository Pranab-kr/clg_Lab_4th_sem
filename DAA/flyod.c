#include <stdio.h>

#define INF 999

int main() {
  int cost[10][10];
  int i, j, k, n;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);

      if (cost[i][j] == 0 && i != j) {
        cost[i][j] = INF;
      }
    }
  }

  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }

  printf("\nShortest path matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (cost[i][j] == INF) {
        printf("INF ");
      } else {
        printf("%d ", cost[i][j]);
      }
    }

    printf("\n");
  }

  return 0;
}
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 5 999 10
// 999 0 3 999
// 999 999 0 1
// 999 999 999 0
//
// Shortest path matrix:
// 0 5 8 9
// INF 0 3 4
// INF INF 0 1
// INF INF INF 0
