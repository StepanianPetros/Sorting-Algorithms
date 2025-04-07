#include <stdio.h>

void printArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void Sort(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        int max = arr[0];
        int max_index = 0;
        for(int j = 1; j < size - i - 1; j++)
        {
            if(arr[j] > max)
            {
                max = arr[j];
                max_index = j;
            }
        }
        arr[max_index] = arr[size - i - 1];
        arr[size - i - 1] = max;
    }
}

int main()
{
    int arr[] = {7, 3, 9, 1, 8, 6, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    Sort(arr, size);
    printArray(arr, size);

    return 0;
}