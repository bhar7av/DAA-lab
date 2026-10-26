#include <stdio.h>
#include <string.h>

#define MAX 100

int dp[MAX][MAX];
char X[MAX], Y[MAX];

int lcs(int i, int j) {
 
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (X[i - 1] == Y[j - 1])
        dp[i][j] = 1 + lcs(i - 1, j - 1);
    else {
        int a = lcs(i - 1, j);
        int b = lcs(i, j - 1);
        dp[i][j] = (a > b) ? a : b;
    }
    return dp[i][j];
}

int main(void) {
    printf("Enter first string: ");
    scanf("%99s", X);
    printf("Enter second string: ");
    scanf("%99s", Y);

    int m = strlen(X), n = strlen(Y);

    memset(dp, -1, sizeof(dp));

    printf("Length of LCS = %d\n", lcs(m, n));
    return 0;
}