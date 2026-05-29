#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int arr[100];
  int n, i, target, result;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  printf("Enter sorted elements:\n");

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter element to search: ");
  scanf("%d", &target);

  result = binarySearch(arr, 0, n - 1, target);

  if (result == -1) {
    printf("Element not found");
  } else {
    printf("Element found at position %d", result + 1);
  }

  return 0;
}

// Enter number of elements: 5
// Enter sorted elements:
// 2 4 6 8 10
// Enter element to search: 6
// Element found at position 3
