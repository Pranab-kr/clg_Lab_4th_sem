#include <stdio.h>

int partition(int arr[], int low, int high) {
  int pivot, i, j, temp;

  pivot = arr[low];
  i = low + 1;
  j = high;

  while (i <= j) {
    while (arr[i] <= pivot && i <= high) {
      i++;
    }

    while (arr[j] > pivot) {
      j--;
    }

    if (i < j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;

  return j;
}

void quickSort(int arr[], int low, int high) {
  int p;

  if (low < high) {
    p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
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

  quickSort(arr, 0, n - 1);

  printf("Sorted array:\n");

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
// Enter number of elements: 5
// Enter elements:
// 7 3 10 4 1
// Sorted array:
// 1 3 4 7 10
