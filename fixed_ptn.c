#include <stdio.h>

int main() {

    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb], originalBlock[nb];

    for(i = 0; i < nb; i++) {

        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &block[i]);

        originalBlock[i] = block[i];
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

    printf("\n========== FIXED PARTITIONING ==========\n");

    int fixedBlock[nb];

    for(i = 0; i < nb; i++)
        fixedBlock[i] = originalBlock[i];

    for(i = 0; i < np; i++) {

        for(j = 0; j < nb; j++) {

            if(fixedBlock[j] >= process[i]) {

                allocation[i] = j;

                internalFrag[i] =
                    fixedBlock[j] - process[i];

                fixedBlock[j] = 0;

                break;
            }
        }
    }

    printf("\nProcess\tP.Size\tBlock\tInternal Frag\n");

    for(i = 0; i < np; i++) {

        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\t%d\n",
                   allocation[i] + 1,
                   internalFrag[i]);
        else
            printf("Not Allocated\n");
    }

    printf("\n========== VARIABLE PARTITIONING ==========\n");

    int variableBlock[nb];

    for(i = 0; i < nb; i++)
        variableBlock[i] = originalBlock[i];

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++) {

        for(j = 0; j < nb; j++) {

            if(variableBlock[j] >= process[i]) {

                allocation[i] = j;

                variableBlock[j] -= process[i];

                break;
            }
        }
    }

    printf("\nProcess\tP.Size\tBlock\n");

    for(i = 0; i < np; i++) {

        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("\nRemaining Memory Blocks (External Fragmentation)\n");

    for(i = 0; i < nb; i++) {

        printf("Block %d = %d\n",
               i + 1,
               variableBlock[i]);
    }

    return 0;
}
