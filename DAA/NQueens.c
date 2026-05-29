#include <stdio.h>

int board[20][20], n, count = 0;

int isSafe(int row, int col) {
  int i, j;

  // Check left side row
  for (i = 0; i < col; i++)
    if (board[row][i])
      return 0;

  // Check upper diagonal
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return 0;

  // Check lower diagonal
  for (i = row, j = col; i < n && j >= 0; i++, j--)
    if (board[i][j])
      return 0;

  return 1;
}

void printBoard() {
  count++;
  printf("\nSolution %d:\n", count);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (board[i][j] == 1)
        printf("Q ");
      else
        printf(". ");
    }
    printf("\n");
  }
}

void solveNQ(int col) {

  if (col == n) {
    printBoard();
    return;
  }

  for (int i = 0; i < n; i++) {

    if (isSafe(i, col)) {

      board[i][col] = 1;

      solveNQ(col + 1);

      board[i][col] = 0; // Backtrack
    }
  }
}

int main() {

  printf("Enter number of queens: ");
  scanf("%d", &n);

  solveNQ(0);

  if (count == 0)
    printf("No solution exists");

  return 0;
}
// Enter number of queens: 4
//
// Solution 1:
// . . Q .
// Q . . .
// . . . Q
// . Q . .
//
// Solution 2:
// . Q . .
// . . . Q
// Q . . .
// . . Q .
