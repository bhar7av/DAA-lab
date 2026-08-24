#include<stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index 'i' in an array 'arr' of size 'n'
// This ensures that the subtree rooted at 'i' satisfies the max-heap property.
void max_heapify(int arr[], int n, int i) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1; // left child = 2*i + 1
    int right = 2 * i + 2; // right child = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        max_heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapsort(int arr[], int n) {
    // 1. Build Max-Heap (rearrange array)
    // Start from the last non-leaf node and move upwards
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }

    // 2. Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest element) to the end
        swap(&arr[0], &arr[i]);

        // Call max_heapify on the reduced heap
        max_heapify(arr, i, 0);
    }
}

// Utility function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = { 5, 6, 7 , 12, 13, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    print_array(arr, n);

    heapsort(arr, n);

    printf("Sorted array: \n");
    print_array(arr, n);

    return 0;
}