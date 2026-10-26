
#include <stdio.h>

#define INF 99999
#define MAX 100

int main() {
    int n;
    int dp[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (99999 for INF):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][k] != INF && dp[k][j] != INF) {
                    int newDist = dp[i][k] + dp[k][j];

                    if (newDist < dp[i][j]) {
                        dp[i][j] = newDist;
                    }
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
