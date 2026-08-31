#include <stdio.h>

void addMatrix(int A[4][4], int B[4][4],
               int C[4][4], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiply(int A[4][4], int B[4][4],
              int C[4][4], int n)
{
    int i, j;
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[4][4] = {0};
    int A12[4][4] = {0};
    int A21[4][4] = {0};
    int A22[4][4] = {0};

    int B11[4][4] = {0};
    int B12[4][4] = {0};
    int B21[4][4] = {0};
    int B22[4][4] = {0};

    int C11[4][4] = {0};
    int C12[4][4] = {0};
    int C21[4][4] = {0};
    int C22[4][4] = {0};

    int M1[4][4] = {0};
    int M2[4][4] = {0};

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    multiply(A11, B11, M1, k);
    multiply(A12, B21, M2, k);
    addMatrix(M1, M2, C11, k);


    multiply(A11, B12, M1, k);
    multiply(A12, B22, M2, k);
    addMatrix(M1, M2, C12, k);

    /* C21 = A21*B11 + A22*B21 */

    multiply(A21, B11, M1, k);
    multiply(A22, B21, M2, k);
    addMatrix(M1, M2, C21, k);

    /* C22 = A21*B12 + A22*B22 */

    multiply(A21, B12, M1, k);
    multiply(A22, B22, M2, k);
    addMatrix(M1, M2, C22, k);

    /* Combine four submatrices */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main()
{
    int A[4][4], B[4][4], C[4][4] = {0};
    int i, j;

    printf("Enter Matrix A (4x4):\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter Matrix B (4x4):\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    multiply(A, B, C, 4);

    printf("\nResultant Matrix:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d\t", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}