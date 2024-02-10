#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void MakingUniformDist(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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

    MakingUniformDist(arr, dataSize);

    FILE *ptr = fopen("random_data.csv", "w");

    for (int i = 0; i < dataSize; i++)
    {
        fprintf(ptr, "%d \n", arr[i]);
    }
    fclose(ptr);
}