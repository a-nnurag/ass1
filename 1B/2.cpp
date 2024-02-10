#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void MakingNormalDist(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < 12; j++)
        {
            int k = rand() % 100 + 1;
            sum += k;
        }
        sum = sum / 12;
        arr[i] = sum;
    }
}

int main()
{
    srand(time(NULL));

    int dataSize = 1000000;
    int arr[dataSize];

    MakingNormalDist(arr, dataSize);

    FILE *ptr = fopen("Normal_try.xls", "w");

    for (int i = 0; i < dataSize; i++)
    {
        fprintf(ptr, "%d \n", arr[i]);
    }
}