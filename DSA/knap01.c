#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int profit[50], weight[50];
  int k[50][50];
  int n, m;
  int i, w;

  printf("Enter number of items: ");
  scanf("%d", &n);

  printf("Enter profits:\n");

  for (i = 1; i <= n; i++) {
    scanf("%d", &profit[i]);
  }

  printf("Enter weights:\n");

  for (i = 1; i <= n; i++) {
    scanf("%d", &weight[i]);
  }

  printf("Enter knapsack capacity: ");
  scanf("%d", &m);

  for (i = 0; i <= n; i++) {
    for (w = 0; w <= m; w++) {
      if (i == 0 || w == 0) {
        k[i][w] = 0;
      } else if (weight[i] <= w) {
        k[i][w] = max(profit[i] + k[i - 1][w - weight[i]], k[i - 1][w]);
      } else {
        k[i][w] = k[i - 1][w];
      }
    }
  }

  printf("Maximum profit = %d", k[n][m]);

  return 0;
}
// Enter number of items: 5
// Enter profits:
// 1 2 5 6 7
// Enter weights:
// 2 3 4 5 6
// Enter knapsack capacity: 10
// Maximum profit = 14
