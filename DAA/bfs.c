#include <stdio.h>

int graph[10][10], visited[10];
int queue[10];
int front = -1, rear = -1;
int n;

void bfs(int start) {
  int i, current;

  visited[start] = 1;
  queue[++rear] = start;

  while (front != rear) {
    current = queue[++front];
    printf("%d ", current);

    for (i = 0; i < n; i++) {
      if (graph[current][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        queue[++rear] = i;
      }
    }
  }
}

int main() {
  int i, j, start;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  printf("Enter starting vertex: ");
  scanf("%d", &start);

  bfs(start);

  return 0;
}

// Enter number of vertices: 5
/* Enter adjacency matrix: */
/* 0 1 1 0 0 */
/* 1 0 0 1 1 */
/* 1 0 0 0 0 */
/* 0 1 0 0 0 */
/* 0 1 0 0 0 */
/* Enter starting vertex: 0 */
/* 0 1 2 3 4  output */
