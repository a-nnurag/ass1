#include <stdio.h>

void swap(int *a, int *b)
{
    // *a = *a ^ *b;
    // *b = *a ^ *b;
    // *a = *a ^ *b;
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int i = s;
    int j = e;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= e - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= s + 1)
        {
            j--;
        }
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[s], &arr[j]);
    return j;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivot = partition(arr, s, e);
    quickSort(arr, s, pivot - 1);
    quickSort(arr, pivot + 1, e);
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 9;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}