#include <stdio.h>

int graph[10][10], color[10], n, m;

int isSafe(int node, int c) {
  for (int i = 0; i < n; i++) {
    if (graph[node][i] == 1 && color[i] == c)
      return 0;
  }
  return 1;
}

int solve(int node) {
  if (node == n)
    return 1;

  for (int c = 1; c <= m; c++) {
    if (isSafe(node, c)) {
      color[node] = c;

      if (solve(node + 1))
        return 1;

      color[node] = 0;
    }
  }

  return 0;
}

int main() {
  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  printf("Enter number of colors: ");
  scanf("%d", &m);

  for (int i = 0; i < n; i++)
    color[i] = 0;

  if (solve(0)) {
    printf("Solution exists:\n");
    for (int i = 0; i < n; i++) {
      printf("Vertex %d -> Color %d\n", i, color[i]);
    }
  } else {
    printf("No solution exists\n");
  }

  return 0;
}
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 1
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0
// Enter number of colors: 3
// Solution exists:
// Vertex 0 -> Color 1
// Vertex 1 -> Color 2
// Vertex 2 -> Color 3
// Vertex 3 -> Color 2
