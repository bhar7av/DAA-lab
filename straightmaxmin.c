//straight max min
#include <stdio.h>

int main() {
    int  i;
    int arr[] = {20,23,32,432,54,76,89,56};
    int max, min;

    int n = sizeof(arr) / sizeof(arr[0]);
    max = min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}