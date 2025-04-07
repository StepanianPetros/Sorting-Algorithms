#include <stdio.h>

void swap(int* a, int* b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int split(int arr[], int from, int to) 
{
    int pivot = arr[to - 1];
    int final_pivot_index = from - 1;

    for (int i = from; i < to - 1; i++)
    {
        if (arr[i] < pivot)
        {
            final_pivot_index++;
            swap(&arr[i], &arr[final_pivot_index]);
        }
    }
    
    
    swap(&arr[final_pivot_index + 1], &arr[to - 1]);
    return final_pivot_index + 1;
}

void quickSort(int arr[], int from, int to) 
{
    if (from < to)
    {
        int split_index = split(arr, from, to);

        quickSort(arr, from, split_index);
        quickSort(arr, split_index + 1, to); 
    }
}

int main() 
{
    int arr[] = {10, 7, 8, 9, 1, 5, 13, 12, 11, -1, 99};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    for (int i = 0; i < len; i++) 
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, len);
    printf("\nSorted Array: ");

    for (int i = 0; i < len; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
