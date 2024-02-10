#include <stdio.h>
#include <math.h>
#include <time.h>

void merge(int *arr, int s, int mid, int e, int *comp, int *branch)
{
    int left = s, right = mid + 1;
    int k = 0;
    int temp[e - s + 1];

    while (left <= mid && right <= e)
    {
        if (arr[left] > arr[right])
        {
            temp[k++] = arr[right++];
            *comp = *comp + 1;
        }
        else
        {
            temp[k++] = arr[left++];
            *comp = *comp + 1;
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
        *comp = *comp + 1;
    }

    while (right <= e)
    {
        temp[k++] = arr[right++];
        *comp = *comp + 1;
    }
    left = s;
    for (int i = 0; i < (e - s + 1); i++)
    {
        arr[left++] = temp[i];
    }
}

void mergeSort(int *arr, int s, int e, int *comp, int *branch)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    *branch += 2;
    mergeSort(arr, s, mid, comp, branch);
    mergeSort(arr, mid + 1, e, comp, branch);
    merge(arr, s, mid, e, comp, branch);
}

int main()
{
    FILE *inputfile = fopen("uniform_data.xls", "r");
    FILE *outputfilescount = fopen("msoutputscountcomp.xls", "w");
    FILE *outputfilelcount = fopen("msoutputlcountbranch.xls", "w");
    FILE *outputfilescountn = fopen("msoutputlcountbranchnormalized.xls", "w");
    FILE *outputfilelcountn = fopen("msoutputlcountbranchnormalized.xls", "w");
    FILE *outputfiletime = fopen("msoutputlcounttime.xls", "w");

    int comp = 0;
    int branch = 0;
    int n = 1;
    int k = 0;
    printf("enter the  max size\n ");
    scanf("%d", &k);
    while (n < k)
    {
        n = n * 2;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(inputfile, "%d", &arr[i]);
        }
        int start = clock();
        mergeSort(arr, 0, n - 1, &comp, &branch);
        int stop = clock();
        int time = stop - start;
        int compn = comp / (n * log(n));
        int branchn = branch / (n * log(n));
        printf("\n length=%d comp=%d  branch=%d branchnormalized=%d branchnormlized=%d time=%dms", n, comp, branch, compn, branchn, time);
        fprintf(outputfilescount, "%d \t %d \n", n, comp);
        fprintf(outputfilelcount, "%d \t %d \n", n, branch);
        fprintf(outputfilescountn, "%d \t %d \n", n, compn);
        fprintf(outputfilelcountn, "%d \t %d \n", n, branchn);
        fprintf(outputfiletime, "%d \t %d \n", n, time);
    }
}