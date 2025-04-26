#include <stdio.h>

void shellSort(int arr[], int size)
{
    for(int gap = size/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;

            for (; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}



void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array:\n");
    printArray(arr, size);

    shellSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
