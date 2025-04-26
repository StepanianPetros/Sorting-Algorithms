#include <stdio.h>

int getMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size) {
    int capacity = getMax(arr, size) + 1;
    int countArray[capacity];
    int output[size];

    for (int i = 0; i < capacity; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int index = arr[i];
        countArray[index]++;
    }

    for (int i = 1; i < capacity; i++) {
        countArray[i] += countArray[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int value = arr[i];
        int index = --countArray[value];
        output[index] = value;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 8, 2, 3, 11, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array:\n");
    printArray(arr, size);

    countingSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
