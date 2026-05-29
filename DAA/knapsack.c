#include <stdio.h>

struct Item {
  int profit;
  int weight;
  float ratio;
};

int main() {
  struct Item item[50], temp;

  int n, i, j;
  int capacity;
  float totalProfit = 0.0;

  printf("Enter number of items: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter profit and weight of item %d: ", i + 1);
    scanf("%d%d", &item[i].profit, &item[i].weight);

    item[i].ratio = (float)item[i].profit / item[i].weight;
  }

  printf("Enter knapsack capacity: ");
  scanf("%d", &capacity);

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (item[j].ratio < item[j + 1].ratio) {
        temp = item[j];
        item[j] = item[j + 1];
        item[j + 1] = temp;
      }
    }
  }

  printf("\nSelected items:\n");

  for (i = 0; i < n; i++) {
    if (capacity >= item[i].weight) {
      capacity = capacity - item[i].weight;
      totalProfit = totalProfit + item[i].profit;

      printf("Item with profit %d and weight %d selected fully\n",
             item[i].profit, item[i].weight);
    } else {
      totalProfit = totalProfit + (item[i].ratio * capacity);

      printf("Item with profit %d and weight %d selected partially\n",
             item[i].profit, item[i].weight);

      break;
    }
  }

  printf("\nMaximum Profit = %.2f", totalProfit);

  return 0;
}
// Enter number of items : 4 Enter profit and weight of item 1
//     : 10 2 Enter profit and weight of item 2
//     : 5 3 Enter profit and weight of item 3
//     : 15 5 Enter profit and weight of item 4 : 7 7 Enter knapsack capacity :
//     10
//
//     Selected items
//     : Item with profit 10 and weight 2 selected fully Item with profit 15 and
//           weight 5 selected fully Item with profit 5 and weight 3 selected
//           fully
//
//               Maximum Profit = 30.00
