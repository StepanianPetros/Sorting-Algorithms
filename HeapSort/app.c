#include <stdio.h>

void heapify(int arr[], int size, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;

    if (left < size && arr[left] > arr[max])
    {
        max = left;
    }
    if (right < size && arr[right] > arr[max])
    {
        max = right;
    }

    int temp;
    if (max != i) {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, size, max);
    }
}

void HeapSort(int arr[], int size)
{
    int i;

    for(int i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    int temp;

    for (i = size - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {20, 8, 7, 23, 1, 11};
    int Size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < Size; i++)
        printf("%d ", arr[i]);

    HeapSort(arr, Size);
    printf("\n");

    for (int i = 0; i < Size; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
