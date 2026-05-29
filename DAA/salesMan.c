#include <stdio.h>

#define MAX 10
#define INF 999

int cost[MAX][MAX];
int visited[MAX];
int n;

int tsp(int city) {
  int i;
  int nearestCity = -1;
  int min = INF;
  int minCost = 0;

  visited[city] = 1;

  printf("%d -> ", city);

  for (i = 0; i < n; i++) {
    if (cost[city][i] != 0 && visited[i] == 0) {
      if (cost[city][i] < min) {
        min = cost[city][i];
        nearestCity = i;
      }
    }
  }

  if (nearestCity == -1) {
    return cost[city][0];
  }

  minCost = min + tsp(nearestCity);

  return minCost;
}

int main() {
  int i, j;
  int totalCost;

  printf("Enter number of cities: ");
  scanf("%d", &n);

  printf("Enter cost matrix:\n");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  printf("Path:\n");

  totalCost = tsp(0);

  printf("0\n");

  printf("Minimum Cost = %d", totalCost);

  return 0;
}
// Enter number of cities: 4
// Enter cost matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
//
// Path:
// 0 -> 1 -> 3 -> 2 -> 0
//
// Minimum Cost = 80
