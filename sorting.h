#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void displaySort(int * num, int size);
void bubbleSort(int * num, int size);
void selectSort(int * num, int size);
void insertSort(int * num, int size);
void quickSort(int *num, int left, int right);
void shellSort(int *num, int size);
void heapSort(int * num, int size);
void mergeSort(int *num, int left, int right);
void radixSort(int *num, int size);
void countingSort(int *num, int size);
void bucketSort(int *num, int size);

#endif