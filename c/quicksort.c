#include <stdio.h>

// Function to swap two elements
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = low - 1;       // Initialize the index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(arr, i, j); // Swap arr[i] and arr[j]
        }
    }

    swap(arr, i + 1, high); // Swap the pivot element with the element at (i + 1)
    return (i + 1); // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find pivot element such that
        // elements smaller than pivot are on the left
        // and elements greater than pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
