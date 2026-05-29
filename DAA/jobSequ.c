#include <stdio.h>

struct Job {
  char id[5];
  int deadline;
  int profit;
};

int main() {
  struct Job job[20], temp;

  int slot[20];

  int n, i, j;
  int maxDeadline = 0;
  int totalProfit = 0;

  printf("Enter number of jobs: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter Job ID, Deadline and Profit:\n");

    scanf("%s%d%d", job[i].id, &job[i].deadline, &job[i].profit);

    if (job[i].deadline > maxDeadline) {
      maxDeadline = job[i].deadline;
    }
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (job[j].profit < job[j + 1].profit) {
        temp = job[j];
        job[j] = job[j + 1];
        job[j + 1] = temp;
      }
    }
  }

  for (i = 0; i <= maxDeadline; i++) {
    slot[i] = -1;
  }

  for (i = 0; i < n; i++) {
    for (j = job[i].deadline; j > 0; j--) {
      if (slot[j] == -1) {
        slot[j] = i;
        totalProfit = totalProfit + job[i].profit;
        break;
      }
    }
  }

  printf("\nSelected Jobs:\n");

  for (i = 1; i <= maxDeadline; i++) {
    if (slot[i] != -1) {
      printf("%s ", job[slot[i]].id);
    }
  }

  printf("\nTotal Profit = %d", totalProfit);

  return 0;
}
// Enter number of jobs: 5
// Enter Job ID, Deadline and Profit:
// J1 2 100
// Enter Job ID, Deadline and Profit:
// J2 1 19
// Enter Job ID, Deadline and Profit:
// J3 2 27
// Enter Job ID, Deadline and Profit:
// J4 1 25
// Enter Job ID, Deadline and Profit:
// J5 3 15
//
// Selected Jobs:
// J3 J1 J5
// Total Profit = 142
