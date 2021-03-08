#include "sorting.h"
#include <time.h>

int main(void)
{
    int num[10][SIZE];
    int i, j;
    srand((unsigned)time(NULL));
    for(i = 0; i < SIZE; i++)
    {
        num[0][i] = rand() % 100 + 1;
        for(j = 1; j < 10; j++)
            num[j][i] = num[0][i];
    }
    
    printf("Initial:\n");
    displaySort(num[0], SIZE);
    printf("\n");

    bubbleSort(num[0], SIZE);
    printf("bubbleSort:\n");
    displaySort(num[0], SIZE);
    printf("\n");

    selectSort(num[1], SIZE);
    printf("selectSort:\n");
    displaySort(num[1], SIZE);
    printf("\n");

    insertSort(num[2], SIZE);
    printf("insertSort:\n");
    displaySort(num[2], SIZE);
    printf("\n");

    quickSort(num[3], 0, SIZE - 1);
    printf("quickSort:\n");
    displaySort(num[3], SIZE);
    printf("\n");

    shellSort(num[4], SIZE);
    printf("shellSort:\n");
    displaySort(num[4], SIZE);
    printf("\n");

    heapSort(num[5], SIZE);
    printf("heapSort:\n");
    displaySort(num[5], SIZE);
    printf("\n");

    mergeSort(num[6], 0, SIZE -1);
    printf("mergeSort:\n");
    displaySort(num[6], SIZE);
    printf("\n");

    radixSort(num[7], SIZE);
    printf("radixSort:\n");
    displaySort(num[7], SIZE);
    printf("\n");

    countingSort(num[8], SIZE);
    printf("countingSort:\n");
    displaySort(num[8], SIZE);
    printf("\n");

    bucketSort(num[9], SIZE);
    printf("bucketSort:\n");
    displaySort(num[9], SIZE);
    printf("\n");

    return 0;
}