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
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}



int main()
{  
    int arr[] = {5, 7, 8, 1, 3, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    Sort(arr, size);
    printArray(arr, size);
    return 0;
}