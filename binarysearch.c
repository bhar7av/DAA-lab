#include<stdio.h>

int arr[] = {21,32,34,54,65,67,78,89,99,100};

int binarySearchDAC(int arr[], int low, int high, int key) {

    if (low > high)
        return -1;

    if (low == high) {
        if (arr[low] == key)
            return low;
        else
            return -1;
    }

    int mid = (low + high) / 2;
     if (arr[mid] == key)
        return mid;
    if(key< arr[mid]){
    return binarySearchDAC(arr, low, mid-1, key);}
    else
    return binarySearchDAC(arr, mid + 1, high, key);
}

int main(){
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int index = binarySearchDAC(arr, 0, n - 1, 78);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    
    return 0;
}