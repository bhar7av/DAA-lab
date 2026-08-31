#include <stdio.h>

void strassen(int A[4][4], int B[4][4],
              int C[4][4], int n)
{
    int i, j;

    /* Base case */
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int a[4][4] = {0};
    int b[4][4] = {0};
    int c[4][4] = {0};
    int d[4][4] = {0};

    int e[4][4] = {0};
    int f[4][4] = {0};
    int g[4][4] = {0};
    int h[4][4] = {0};

    int p1[4][4] = {0};
    int p2[4][4] = {0};
    int p3[4][4] = {0};
    int p4[4][4] = {0};
    int p5[4][4] = {0};
    int p6[4][4] = {0};
    int p7[4][4] = {0};

    int temp1[4][4] = {0};
    int temp2[4][4] = {0};

    /* Divide A and B */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + k];
            c[i][j] = A[i + k][j];
            d[i][j] = A[i + k][j + k];

            e[i][j] = B[i][j];
            f[i][j] = B[i][j + k];
            g[i][j] = B[i + k][j];
            h[i][j] = B[i + k][j + k];
        }
    }

    /* p1 = a(f-h) */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = f[i][j] - h[i][j];
        }
    }

    strassen(a, temp1, p1, k);

    /* p2 = (a+b)h */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = a[i][j] + b[i][j];
        }
    }

    strassen(temp1, h, p2, k);

    /* p3 = (c+d)e */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = c[i][j] + d[i][j];
        }
    }

    strassen(temp1, e, p3, k);

    /* p4 = d(g-e) */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = g[i][j] - e[i][j];
        }
    }

    strassen(d, temp1, p4, k);

    /* p5 = (a+d)(e+h) */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = a[i][j] + d[i][j];
            temp2[i][j] = e[i][j] + h[i][j];
        }
    }

    strassen(temp1, temp2, p5, k);

    /* p6 = (b-d)(g+h) */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = b[i][j] - d[i][j];
            temp2[i][j] = g[i][j] + h[i][j];
        }
    }

    strassen(temp1, temp2, p6, k);

    /* p7 = (a-c)(e+f) */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            temp1[i][j] = a[i][j] - c[i][j];
            temp2[i][j] = e[i][j] + f[i][j];
        }
    }

    strassen(temp1, temp2, p7, k);

    /* Combine */

    /* C11 = p5 + p4 - p2 + p6 */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i][j] =
                p5[i][j] +
                p4[i][j] -
                p2[i][j] +
                p6[i][j];
        }
    }

    /* C12 = p1 + p2 */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i][j + k] =
                p1[i][j] + p2[i][j];
        }
    }

    /* C21 = p3 + p4 */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i + k][j] =
                p3[i][j] + p4[i][j];
        }
    }

    /* C22 = p1 + p5 - p3 - p7 */

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            C[i + k][j + k] =
                p1[i][j] +
                p5[i][j] -
                p3[i][j] -
                p7[i][j];
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

    strassen(A, B, C, 4);

    printf("\nResultant Matrix using Strassen:\n");

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