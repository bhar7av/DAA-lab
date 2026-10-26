#include <stdio.h>
#include <string.h>

#define MAX 100

long long dp[MAX];

long long fib(int n) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main(void) {
    int n;
    printf("Enter n (0-90): ");
    scanf("%d", &n);

    if (n < 0 || n > 90) {
        printf("n must be between 0 and 90.\n");
        return 1;
    }

    memset(dp, -1, sizeof(dp));

    printf("Fibonacci(%d) = %lld\n", n, fib(n));
    return 0;
}