#include<stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[],int low , int high){
    int pivot = A[low];
    int i = low;
    int j = low+1;
    int temp;

    do{
        while(A[j]<=A[i]){
            i++;
            j++;
        }
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        while(A[i]<A[j]);
            j++;
        
    }
    
}