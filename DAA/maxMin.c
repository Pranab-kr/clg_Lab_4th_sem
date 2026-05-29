#include <stdio.h>

int max, min;

void maxMin(int arr[], int low, int high) {
  int mid;
  int max1, min1;

  if (low == high) {
    max = arr[low];
    min = arr[low];
  } else if (low == high - 1) {
    if (arr[low] > arr[high]) {
      max = arr[low];
      min = arr[high];
    } else {
      max = arr[high];
      min = arr[low];
    }
  } else {
    mid = (low + high) / 2;

    maxMin(arr, low, mid);

    max1 = max;
    min1 = min;

    maxMin(arr, mid + 1, high);

    if (max < max1) {
      max = max1;
    }

    if (min > min1) {
      min = min1;
    }
  }
}

int main() {
  int arr[100];
  int n, i;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Enter elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  maxMin(arr, 0, n - 1);

  printf("Maximum element = %d\n", max);
  printf("Minimum element = %d\n", min);

  return 0;
}
//
// Enter number of elements: 5
// Enter elements:
// 10 4 25 12 8
// Maximum element = 25
// Minimum element = 4
