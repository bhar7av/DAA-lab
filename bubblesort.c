#include<stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[],int n){
    for(int i = 0;i<n-1 ; i++){
        for(int j = 0; j<n-i-1;j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={4,2,3,6,32,1,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array \n");
    print_array(arr,n);
    bubblesort(arr,n);

    printf("sorted array \n");
    print_array(arr,n);

}