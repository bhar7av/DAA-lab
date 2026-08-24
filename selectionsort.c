#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(&arr[i], &arr[minIndex]);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr[] = {4, 2, 3, 6, 32, 1, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    print_array(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}