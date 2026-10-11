//insertion sort 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int sizes[] = {10, 100, 1000};
    int i, j, n;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    printf("Insertion Sort Time Complexity Analysis\n");
    printf("----------------------------------------\n");

    for (i = 0; i < 3; i++)
    {
        n = sizes[i];

        int arr[n];

        for (j = 0; j < n; j++)
        {
            arr[j] = rand() % 10000;
        }

        start = clock();

        insertionSort(arr, n);

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Input Size: %d\tTime: %f seconds\n", n, time_taken);
    }

    return 0;
}