//with divide and conquer

#include <stdio.h>

long long power(int base, int exp) {
    if (exp == 0)
        return 1;

    long long half = power(base, exp / 2);

    if (exp % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    int base, exp;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    printf("%d^%d = %lld\n", base, exp, power(base, exp));

    return 0;
}

