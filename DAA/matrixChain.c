#include <stdio.h>

#define MAX 20

int m[MAX][MAX];

int matrixChain(int p[], int n) {
  int i, j, k, l, q;

  for (i = 1; i < n; i++) {
    m[i][i] = 0;
  }

  for (l = 2; l < n; l++) {
    for (i = 1; i < n - l + 1; i++) {
      j = i + l - 1;
      m[i][j] = 99999;

      for (k = i; k <= j - 1; k++) {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

        if (q < m[i][j]) {
          m[i][j] = q;
        }
      }
    }
  }

  return m[1][n - 1];
}

int main() {
  int p[MAX];
  int n, i, result;

  printf("Enter number of matrices: ");
  scanf("%d", &n);

  printf("Enter dimensions:\n");

  for (i = 0; i <= n; i++) {
    scanf("%d", &p[i]);
  }

  result = matrixChain(p, n + 1);

  printf("Minimum number of multiplications = %d", result);

  return 0;
}
// Enter number of matrices: 4
// Enter dimensions:
// 10 20 30 40 30
// Minimum number of multiplications = 30000
