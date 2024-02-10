#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *a, int *b)
{
    // *a = *a ^ *b;
    // *b = *a ^ *b;
    // *a = *a ^ *b;
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int *arr, int s, int e, int *scount, int *lcount)
{
    int pivot = arr[s];
    int i = s;
    int j = e;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= e - 1)
        {
            i++;
            (*(lcount))++;
        }
        while (arr[j] > pivot && j >= s + 1)
        {
            j--;
            (*(lcount))++;
        }
        if (i < j)
        {
            (*(scount))++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[s], &arr[j]);
    (*(scount))++;
    return j;
}

void quickSort(int *arr, int s, int e, int *scount, int *lcount)
{
    if (s >= e)
    {
        return;
    }
    int pivot = partition(arr, s, e, scount, lcount);
    quickSort(arr, s, pivot - 1, scount, lcount);
    quickSort(arr, pivot + 1, e, scount, lcount);
}

int main()
{
    FILE *inputfile = fopen("Normal_try.xls", "r");
    FILE *outputfilescount = fopen("qsoutputscount.xls", "w");
    FILE *outputfilelcount = fopen("qsoutputlcount.xls", "w");
    FILE *outputfilelcounttime = fopen("qsoutputlcounttime.xls", "w");

    int data = 0;
    int scount = 0, lcount = 0;
    int n = 1;
    int k = 0;
    printf("enter the  max size\n ");
    scanf("%d", &k);
    while (n < k)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(inputfile, "%d", &arr[n - i - 1]);
        }
        int start = clock();
        quickSort(arr, 0, n - 1, &lcount, &scount);
        int end = clock();
        lcount = lcount;
        scount = scount;
        int lcountn = lcount / (n * log(n));
        int scountn = scount / (n * log(n));
        int time = end - start;
        printf("\n length=%d scount=%d  lcount=%d lcount=%d lcount=%d time=%dns", n, scount, lcount, scountn, lcountn, time);
        fprintf(outputfilescount, "%d \n", scount);
        fprintf(outputfilelcount, "%d \n", lcount);
        fprintf(outputfilelcounttime, "%d", time);
        n = n * 2;
    }
}