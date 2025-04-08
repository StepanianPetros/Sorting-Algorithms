#include <stdio.h>

void printArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void Sort(int* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int main()
{
    int arr[] = {4,7,3,8,2,1,5,6,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr,size);

    Sort(arr,size);
    printArray(arr,size);

    return 0;
}