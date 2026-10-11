#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        int temp;

        while (i <= j)
        {
            while (i <= high && arr[i] <= pivot)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Put pivot in its correct position
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        // Sort left and right parts
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[] = {2, 3, 9, 0, -2, 30, 40, -40, 5, 45};
    int n = 10;

    quickSort(arr, 0, n - 1);

    printf("Array after Quick Sort:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}