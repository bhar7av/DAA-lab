#include <stdio.h>

int main() {

    int nb, np, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    int block[nb];

    for(i = 0; i < nb; i++) {

        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];

    for(i = 0; i < np; i++) {

        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    int allocation[np];
    int internalFrag[np];

    for(i = 0; i < np; i++) {

        allocation[i] = -1;
        internalFrag[i] = 0;
    }

    for(i = 0; i < np; i++) {

        for(j = 0; j < nb; j++) {

            if(block[j] >= process[i]) {

                allocation[i] = j;

                internalFrag[i] =
                    block[j] - process[i];

                block[j] = 0;

                break;
            }
        }
    }

    printf("\nProcess\tP.Size\tBlock\tInternal Fragmentation\n");

    for(i = 0; i < np; i++) {

        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\t%d\n",
                   allocation[i] + 1,
                   internalFrag[i]);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
