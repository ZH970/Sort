#include "../Headers/sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  /*Create a random array, which has 1000 elements*/
  int i, size, choice;
  printf("Please input the size of the array:");
  scanf_s("%d", &size, 1);
  int array[size], temp[size];
  printf("Now chose the method to sort the array:\n(0to sort in ascending order, 1 to sort in descending order)\n");
  scanf_s("%d", &choice, 1);

  if (choice != 6) {
    // Create a random array
    for (i = 0; i < size; i++) {
      array[i] = rand();
    }
  }
  else {
    // Create a color array
    for (i = 0; i < size; i++) {
      array[i] = rand() % 3;
    }
  }
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  clock_t start = clock();
  switch (choice) {
    case 0:
      insertSort(array, size);
      break;
    case 1:
      for (i = 0; i < size; i++) {
        printf("%d ", temp[i]);
      }
      printf("\n");
      MergeSort(array, 0, size - 1, temp);
      break;
    case 2:
      QuickSort_Recursion(array, 0, size - 1);
      break;
    case 3:
      QuickSort(array, size);
      break;
    case 4:
      CountSort(array, size, 0);
      break;
    case 5:
      RadixCountSort(array, size);
      break;
    case 6:
      ColorSort(array, size);
      break;
  }
  clock_t end = clock();


  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\nThe Algorithm time: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);
  return 0;
}
