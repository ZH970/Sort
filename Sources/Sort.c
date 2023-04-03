#include "../Headers/sort.h"
#include <stdio.h>
#include <stdlib.h>

void insertSort (int* a, int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = a[i];
    for (j = i - 1; j >= 0 && a[j] > temp; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = temp;
  }
  return;
}

void MergeSort (int* a, int begin, int end, int* temp) {
  if (begin < end) {
    int mid = (begin + end) / 2;
    //divide the array into two parts in Recursion
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
  }
  return;
}

void MergeArray (int* a, int begin, int mid, int end, int* temp) {
  int i = begin, j = mid + 1, k = 0;
  while (i <= mid && j <= end) {
    if (a[i] <= a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
    }
  }
  while (i <= mid) {
    temp[k++] = a[i++];
  }
  while (j <= end) {
    temp[k++] = a[j++];
  }
  for (i = 0; i < k; i++) {
    a[begin + i] = temp[i];
  }
  return;
}

void QuickSort_Recursion (int* a, int begin, int end) {
  if (begin < end) {
    int pivot = Partition(a, begin, end);
    QuickSort_Recursion(a, begin, pivot - 1);
    QuickSort_Recursion(a, pivot + 1, end);
  }
  return;
}

void QuickSort (int* a, int size) {
  int* stack = (int*)malloc(sizeof(int) * size);
  int top = -1;
  int begin = 0, end = size - 1;
  int pivot;
  if (stack == NULL) {
    printf("Stack malloc failed!");
    return;
  }
  stack[++top] = begin;
  stack[++top] = end;
  while (top >= 0) {
    end = stack[top--];
    begin = stack[top--];
    pivot = Partition(a, begin, end);
    if (pivot - 1 > begin) {
      stack[++top] = begin;
      stack[++top] = pivot - 1;
    }
    if (pivot + 1 < end) {
      stack[++top] = pivot + 1;
      stack[++top] = end;
    }
  }
  free(stack);
  return;
}

int Partition (int* a, int begin, int end) {
  int pivot = a[begin];
  while (begin < end) {
    while (begin < end && a[end] >= pivot) {
      end--;
    }
    a[begin] = a[end];
    while (begin < end && a[begin] <= pivot) {
      begin++;
    }
    a[end] = a[begin];
  }
  a[begin] = pivot;
  return begin;
}

void CountSort (int* a, int size, int max) {
  int i, j;
  for (i = 1; i < size; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  int* count = (int*)malloc(sizeof(int) * (max + 1));
  for (i = 0; i <= max; i++) {
    count[i] = 0;
  }
  for (i = 0; i < size; i++) {
    count[a[i]]++;
  }
  for (i = 0, j = 0; i <= max; i++) {
    //遍历完所有的count数组
    while (count[i]--) {
      a[j++] = i;
    }
  }
  free(count);
  return;
}

void RadixCountSort (int* a, int size) {
  int i, j, k,max = a[0];
  int* count = (int*)malloc(sizeof(int) * 10);
  int* temp = (int*)malloc(sizeof(int) * size);
  int radix = 1;
  for (i = 1; i < size; i++) {
    //find the max number
    if (a[i] > max) {
      max = a[i];
    }
  }
  while (max / radix > 0) {
    for (i = 0; i < 10; i++) {
      //initialize the count array
      count[i] = 0;
    }
    for (i = 0; i < size; i++) {
      //count the number of each digit(j)
      j = (a[i] / radix) % 10;
      count[j]++;
    }
    for (i = 1; i < 10; i++) {
      //count the number of each digit(j) less than j
      count[i] = count[i] + count[i - 1];
    }
    for (i = size - 1; i >= 0; i--) {
      j = (a[i] / radix) % 10;
      temp[count[j] - 1] = a[i];
      count[j]--;
    }
    for (i = 0; i < size; i++) {
      //copy the temp array to the original array
      a[i] = temp[i];
    }
    radix = radix * 10;
  }
  free(count);
  free(temp);
  return;
}

void ColorSort(int* a,int size) {
    int i, j, k;
    int* count = (int*)malloc(sizeof(int) * 3);
    for (i = 0; i < 3; i++) {
        count[i] = 0;
    }
    for (i = 0; i < size; i++) {
        //count the number of each color
        count[a[i]]++;
    }
    for (i = 1; i < 3; i++) {
        //count the number of each color less than i
        count[i] = count[i] + count[i - 1];
    }
    for (i = size - 1; i >= 0; i--) {
        j = a[i];
        k = count[j] - 1;
        a[k] = j;
        count[j]--;
    }
    free(count);
    return;
}