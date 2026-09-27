#include <stdio.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

void jobSequencing(struct Job jobs[], int n) {
    int i, j, maxDeadline = 0;
    int totalProfit = 0;

    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) { 
            if (jobs[i].profit < jobs[j].profit) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    char slot[maxDeadline + 1];

    for (i = 0; i <= maxDeadline; i++)
        slot[i] = '-';

    
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline; j >= 1; j--) {
            if (slot[j] == '-') {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nJob Sequence: ");

    for (i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-')
            printf("%c ", slot[i]);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);
}

int main() {
    int n, i;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter Job ID, Deadline and Profit:\n");

    for (i = 0; i < n; i++) {
        scanf(" %c %d %d",
              &jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}