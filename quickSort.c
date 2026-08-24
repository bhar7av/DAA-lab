#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
// quickSort is recursive in nature

int partition(int *A, int low, int high)
{
    int temp;
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (i<= high &&A[i] <= pivot)
        {
            i++;
        }
        while (i>= low &&A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while (i<j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

int selectionProcedure(int A[], int p, int q, int k){
    if(p ==q){
        if(p==k){
            return A[p];
        }
        else {
            return -1;
        }}
        else{
            int m = partition(A,p,q);
            if(m == k){
                return A[m];
            }
            if(m < k){
                return selectionProcedure(A,m+1,q,k);
            }
            else 
            return selectionProcedure(A,p,m-1,k);
        }
    }

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); // this will return the position of the pivot element
        //printArray(A,high+1); // will show me the array after each partition
        quickSort(A, low, partitionIndex - 1);    // quickSort implemented to the left sub array of the pivot
        quickSort(A, partitionIndex + 1, high);   // quickSort implemented to the right sub array of the pivot
        // after this whole of the array will get sorted
    }
}

int main()
{
    int A[] = {31,23,33,43,234,34,63,53,436,37,83,39,36,34,13};
    int n = sizeof(A) / sizeof(int);
    

    printf("%d \n",selectionProcedure(A,0,n-1,4));
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}