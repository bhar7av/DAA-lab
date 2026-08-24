//using divide and conquer
#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMaxMin(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }


    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }


    mid = (low + high) / 2;


    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

  
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int arr[] = {20, 23, 32, 432, 54, 76, 89, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair ans = findMaxMin(arr, 0, n - 1);

    printf("Maximum = %d\n", ans.max);
    printf("Minimum = %d\n", ans.min);

    return 0;
}