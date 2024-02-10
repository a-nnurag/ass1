#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void UniformDistribution(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int k = rand() % 100 + 1;
        arr[i] = k;
    }
}

int main()
{
    srand(time(NULL));

    int dataSize = 1000000;
    int arr[dataSize];

    UniformDistribution(arr, dataSize);
    FILE *ptr = fopen("random_data.xls", "w");

    for (int i = 0; i < dataSize; i++)
    {
        int data = arr[i];
        fprintf(ptr, "%d \n", data);
    }
}