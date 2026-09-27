#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    int n, capacity;
    int i, j;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    // Sort according to profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            // Take complete item
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {
            // Take fraction of item
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}