#include "sorting.h"
#include <string.h>

void displaySort(int * num, int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", num[i]);
    printf("\n");
}

void bubbleSort(int * num, int size)
{
    int i , j, temp;
    for(i = 0; i < size - 1; i++)
        for(j = 0; j < size - i - 1; j++)
            if(num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
}

void selectSort(int * num, int size)
{
    int i, j, temp;
    for(i = 0; i < size; i++)
        for(j = i + 1; j < size; j++)
            if(num[j] < num[i])
            {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
}

void insertSort(int *num, int size)
{
    int i, j, temp;
    for(i = 1; i < size; i++)
    {
        temp = num[i];
        for(j = i - 1; j > -1; j--)
            if(temp < num[j])
                num[j + 1] = num[j];
            else
                break;
        num[j + 1] = temp;
    }
}

void quickSort(int *num, int left, int right)
{
    if(left < right)
    {
        int i = left, j = right, temp;
        temp = num[left];
        while(i < j)
        {
            while(i < j && num[j] >= temp)
                j--;
            if(i < j)
                num[i++] = num[j];
            while(i < j && num[i] < temp)
                i++;
            if(i < j)
                num[j--] = num[i];
        }
        num[i] = temp;
    quickSort(num, left, i - 1);
    quickSort(num, i + 1, right);
    }
}

void shellSort(int *num, int size)
{
    int k = size / 2, i, temp, d, j, m;
    for(d = k; d > 0; d /= 2)
        for(i = 0; i < d; i++)
            for(j = i + d; j < size; j += d)
            {
                temp = num[j];
                for(m = j - d; m >= 0; m -= d)
                    if(num[m] > temp)
                    {
                        num[m + d] = num[m];
                    }
                    else
                        break;
                num[m + d] = temp;
            }
}

void heapSort(int * num, int size)
{
    int son, parent, i, temp, j, k = size;
    for(j = 0; j < size - 1; j++, k--)
    {
        for(i = k/2 - 1; i > -1; i--)
        {
            parent = i;
            son = parent * 2 + 1;
            if(son < k)
            {
                if(son + 1 < k && num[son] < num[son + 1])
                    son ++;
                if(num[son] > num[parent])
                {
                    temp = num[son];
                    num[son] = num[parent];
                    num[parent] = temp;
                }
            }
        }
        temp = num[0];
        num[0] = num[size - j - 1];
        num[size - j - 1] = temp;
    }
}

void mergeSort(int *num, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) /2, i, j;
        mergeSort(num, left, mid);
        mergeSort(num, mid + 1, right);
        i = left;
        j = mid + 1;
        int *temp, k = 0;
        temp = (int *)malloc(sizeof(int) * (right - left + 1));
        while(1)
        {
            if(num[i] <= num[j] && i < mid + 1 && j < right + 1)
                temp[k ++] = num[i ++];
            else if(num[i] > num[j] && i < mid + 1 && j < right + 1)
                temp[k ++] = num[j ++];
            else 
                break;
        }
        while(i < mid + 1)
            temp[k ++] = num[i ++];
        while(j < right + 1)
            temp[k ++] = num[j ++];
        for(i = left, j = 0; i < right + 1; i++, j++)
            num[i] = temp[j];
        free(temp);
    }
}

void radixSort(int *num, int size)
{
    int maxNum, count = 1, digit = 1;
    int i, j;
    int basic[10], * arr;
    arr = (int *)malloc(sizeof(int) * size);
    maxNum = num[0];
    for(i = 1; i < size; i++)
        if(num[i] > maxNum)
            maxNum = num[i];
    while(maxNum != 0)
    {
        count ++;
        maxNum /= 10;
    }
    for(i = 0; i < count; i++, digit *= 10)
    {
        for(j = 0; j < 10; j++)
            basic[j] = 0;
        for(j = 0; j < size; j++)
            basic[num[j] / digit % 10] ++;
        for(j = 1; j < 10; j++)
            basic[j] += basic[j - 1]; 
        for(j = size - 1; j > -1; j--)
        {
            basic[num[j] / digit % 10] --;
            arr[basic[num[j] / digit % 10]] = num[j];
        }
        for(j = 0; j < size; j ++)
            num[j] = arr[j];
    }
    free(arr);
}

void countingSort(int *num, int size)
{
    int *basic, * arr;
    int i;
    int maxNum = num[0], minNum = num[0];
    for(i = 1; i < size; i++)
    {
        if(num[i] > maxNum)
            maxNum = num[i];
        if(num[i] < minNum)
            minNum = num[i];
    }
    basic = (int *)malloc(sizeof(int) * (maxNum - minNum + 1));
    arr = (int *)malloc(sizeof(int) * size);
    for(i = 0; i < maxNum - minNum + 1; i++)
        basic[i] = 0;
    for(i = 0; i < size; i++)
        basic[num[i] - minNum]++;
    for(i = 1; i < maxNum - minNum + 1; i++)
        basic[i] += basic[i - 1];
    for(i = size - 1; i > -1; i--)
        arr[--basic[num[i] - minNum]] = num[i];
    for(i = 0; i < size; i++)
        num[i] = arr[i];
    free(basic);
    free(arr);
}

void bucketSort(int *num, int size)
{
    int i, group = 10, j = 0, temp, k;
    int digit[11][10], count[11], arr[11];
    for(i = 0; i < 11; i++)
    {
        count[i] = 0;
        arr[i] = 0;
    }
    for(i = 0; i < size; i++)
    {
        digit[num[i] / 10][arr[num[i] / 10] ++] = num[i];
        count[num[i] / 10]++;
    }
    for(i = 0; i < 11; i++)
        for(j = 1; j < count[i]; j++)
        {
            temp = digit[i][j];
            for(k = j - 1; k > -1; k--)
                if(temp < digit[i][k])
                    digit[i][k + 1] = digit[i][k];
                else
                    break;
            digit[i][k + 1] = temp;
        }
    k = 0;
    for(i = 0; i < 11; i++)
        for(j = 0; j < count[i]; j++)
            num[k ++] = digit[i][j];
}