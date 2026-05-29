#include <stdio.h>

#define INF 999

int main() {
  int cost[10][10];
  int dist[10];
  int visited[10];

  int n, i, j, count;
  int min, nextNode;
  int start;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter cost matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);

      if (cost[i][j] == 0 && i != j) {
        cost[i][j] = INF;
      }
    }
  }

  printf("Enter source vertex: ");
  scanf("%d", &start);

  for (i = 0; i < n; i++) {
    dist[i] = cost[start][i];
    visited[i] = 0;
  }

  dist[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    min = INF;

    for (i = 0; i < n; i++) {
      if (dist[i] < min && !visited[i]) {
        min = dist[i];
        nextNode = i;
      }
    }

    visited[nextNode] = 1;

    for (i = 0; i < n; i++) {
      if (!visited[i]) {
        if (min + cost[nextNode][i] < dist[i]) {
          dist[i] = min + cost[nextNode][i];
        }
      }
    }

    count++;
  }

  printf("Shortest distances from source vertex %d:\n", start);

  for (i = 0; i < n; i++) {
    if (i != start) {
      printf("To %d = %d\n", i, dist[i]);
    }
  }

  return 0;
}
// Enter number of vertices: 4
// Enter cost matrix:
// 0 2 0 6
// 2 0 3 8
// 0 3 0 0
// 6 8 0 0
// Enter source vertex: 0
// Shortest distances from source vertex 0:
// To 1 = 2
// To 2 = 5
// To 3 = 6
