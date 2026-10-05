#include <stdio.h>

int main()
{
    int n, i;
    int fib[100];
    int calculated[100] = {0};

    printf("Enter number of terms: ");
    scanf("%d", &n);

    fib[0] = 0;
    calculated[0] = 1;

    fib[1] = 1;
    calculated[1] = 1;

    for(i = 2; i < n; i++)
    {
        if(calculated[i] == 0)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
            calculated[i] = 1;
        }
    }

    printf("Fibonacci Series:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\n", fib[i]);
    }

    return 0;
}