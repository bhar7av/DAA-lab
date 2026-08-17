#include<stdio.h>

    int arr[]={1,32,4,565,43,75,46,32,43,67};

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, i, found = 0;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Element not found.\n");

    return 0;
}