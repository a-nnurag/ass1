#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    float data;
    struct Node *next;
};

struct Node *newNode(float data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertSorted(struct Node **head, float data)
{
    struct Node *current;
    struct Node *temp = newNode(data);
    if (*head == NULL || (*head)->data >= temp->data)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        current = *head;
        while (current->next != NULL && current->next->data < temp->data)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void bucketSort(float arr[], int n, int *insertCall, int *concatCalled)
{
    struct Node **buckets = (struct Node **)malloc(n * sizeof(struct Node *));
    for (int i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
        (*insertCall)++;
    }

    // Concatenate all the buckets
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        struct Node *current = buckets[i];
        while (current != NULL)
        {
            arr[index++] = current->data;
            current = current->next;
        }
        (*concatCalled)++;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++)
    {
        struct Node *current = buckets[i];
        while (current != NULL)
        {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

int main()
{
    FILE *inputfile = fopen("Normal_try.xls", "r");
    FILE *outputfilescount = fopen("bsoutputscount.xls", "w");
    FILE *outputfilelcount = fopen("bsoutputlcount.xls", "w");
    int data = 0;
    int insertCall = 0, concatCalled = 0;
    int n = 1;
    int k = 0;
    printf("enter the  max size\n ");
    scanf("%d", &k);
    while (n < k)
    {
        n = n * 2;
        float arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(inputfile, "%d", &arr[i]);
            arr[i] = arr[i] / 100.00000;
        }
        bucketSort(arr, n, &insertCall, &concatCalled);
        printf("\n length=%d insertCall=%d  concatCalled=%d ", n, insertCall, concatCalled);
        insertCall = insertCall / (n);
        fprintf(outputfilescount, "%d \n", insertCall);
        fprintf(outputfilelcount, "%d \n", concatCalled);
    }
}
