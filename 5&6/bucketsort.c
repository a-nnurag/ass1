#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort within each bucket
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n, int num_buckets)
{
    // Create an array of buckets
    int *buckets[num_buckets];

    // Initialize each bucket with an empty list
    for (int i = 0; i < num_buckets; i++)
    {
        buckets[i] = (int *)malloc(0);
    }

    // Distribute the elements into buckets
    for (int i = 0; i < n; i++)
    {
        int bucket_index = arr[i] / num_buckets;
        int *bucket = buckets[bucket_index];

        // Add the element to the bucket
        bucket = (int *)realloc(bucket, (sizeof(int) * (bucket[0] + 1)));
        bucket[0]++;
        bucket[bucket[0]] = arr[i];
        buckets[bucket_index] = bucket;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < num_buckets; i++)
    {
        insertionSort(buckets[i], buckets[i][0] + 1);
    }

    // Concatenate the sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < num_buckets; i++)
    {
        int *bucket = buckets[i];
        for (int j = 1; j <= bucket[0]; j++)
        {
            arr[index++] = bucket[j];
        }
        free(bucket);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_buckets = 5; // Adjust the number of buckets as needed

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n, num_buckets);

    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
