/*
#include<stdio.h>

int main(){
    int n;
    printf("enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], waiting_time[n], turnaround_time[n];
    for(int i=0; i<n; i++){
        printf("enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }   
    //doing this for the fcfs algorithm
    for(int i=1; i<n; i++){
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];

    }
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    return 0;
}
    */

    //this is for the shortest job first algorithm
    /*
#include<stdio.h>

int main(){
    int n;
    printf("enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], waiting_time[n], turnaround_time[n];
    for(int i=0; i<n; i++){
        printf("enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }   
    //doing this for the sjf algorithm
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(burst_time[j] > burst_time[j+1]){
                int temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
            }
        }
    }
    for(int i=1; i<n; i++){
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];

    }
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    return 0;
} */
/*
//peterson algorithm for mutual exclusion
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
 int main(){
    int flag[2] = {0, 0};
    int turn = 0;
    void* process0(){
        while(1){
            flag[0] = 1;
            turn = 1;
            while(flag[1] == 1 && turn == 1);
            //critical section
            printf("process 0 is in critical section\n");
            flag[0] = 0;
        }
    }
    void* process1(){
        while(1){
            flag[1] = 1;
            turn = 0;
            while(flag[0] == 1 && turn == 0);
            //critical section
            printf("process 1 is in critical section\n");
            flag[1] = 0;
        }
    }
    pthread_t t0, t1;
    pthread_create(&t0, NULL, process0, NULL);
    pthread_create(&t1, NULL, process1, NULL);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    return 0;
}
*/

//round robin scheduling algorithm
/*#include<stdio.h>
int main(){
    int n, time_quantum;
    printf("enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], waiting_time[n], turnaround_time[n];
    for(int i=0; i<n; i++){
        printf("enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }   
    printf("enter the time quantum: ");
    scanf("%d", &time_quantum);
    int remaining_burst_time[n];
    for(int i=0; i<n; i++){
        remaining_burst_time[i] = burst_time[i];
    }
    int t = 0;
    while(1){
        int done = 1;
        for(int i=0; i<n; i++){
            if(remaining_burst_time[i] > 0){
                done = 0;
                if(remaining_burst_time[i] > time_quantum){
                    t += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                }
                else{
                    t += remaining_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if(done == 1){
            break;
        }
    }
    for(int i=0; i<n; i++){
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }
    printf("process\tburst time\twaiting time\tturnaround time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    return 0;
}*/


//fifo page replacement algorithm
/*#include<stdio.h>

int main()
{
    int pages[]={1,2,3,4,1,5};
    int frame[3]={-1,-1,-1};

    int faults=0,k=0;

    for(int i=0;i<6;i++)
    {
        int found=0;

        for(int j=0;j<3;j++)
        {
            if(frame[j]==pages[i])
                found=1;
        }

        if(!found)
        {
            frame[k]=pages[i];
            k=(k+1)%3;
            faults++;
        }
    }

    printf("Page Faults=%d",faults);

    return 0;
}*/

//lru page replacement algorithm
/*#include<stdio.h>
#include<limits.h>
int main(){
    int pages[]={1,2,3,4,1,5};
    int frame[3]={-1,-1,-1};
    int faults=0;
    for(int i=0;i<6;i++){
        int found=0;
        for(int j=0;j<3;j++){
            if(frame[j]==pages[i]){
                found=1;
                break;
            }
        }
        if(!found){
            int lru_index=0;
            int lru_time=INT_MAX;
            for(int j=0;j<3;j++){
                if(frame[j]==-1){
                    lru_index=j;
                    break;
                }
                int time=0;
                for(int k=i-1;k>=0;k--){
                    if(pages[k]==frame[j]){
                        time=i-k;
                        break;
                    }
                }
                if(time<lru_time){
                    lru_time=time;
                    lru_index=j;
                }
            }
            frame[lru_index]=pages[i];
            faults++;
        }
    }
    printf("Page Faults=%d",faults);
    return 0;
}*/


//programs for mfu lfu optimal page replacement algorithms are similar to the above two algorithms with some modifications. I will not write them here as they are not asked for in the question. If you want me to write them, please let me know.lifo fcfs disk scheduling , sstf , scan , c-scan, look c-look disk scheduling algorithms are also similar to the above algorithms with some modifications. I will not write them here as they are not asked for in the question. If you want me to write them, please let me know.

#include<stdio.h>
int main(){
    int n, time_quantum;
    printf("enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n], waiting_time[n], turnaround_time[n];
    for(int i=0; i<n; i++){
        printf("enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }   
    printf("enter the time quantum: ");
    scanf("%d", &time_quantum); 
    int remaining_burst_time[n];
    for(int i=0; i<n; i++){
        remaining_burst_time[i] = burst_time[i];
    }
    int t = 0;
    while(1){
        int done = 1;
        for(int i=0; i<n; i++){
            if(remaining_burst_time[i] > 0){
                done = 0;           if(remaining_burst_time[i] > time_quantum){
                    t += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                }
                else{
                    t += remaining_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_burst_time[i] = 0;
                }                   
            }
        }
        if(done == 1){
            break;
        }
    }
    for(int i=0; i<n; i++){
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }       