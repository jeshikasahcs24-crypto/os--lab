#include <stdio.h>
#include<limits.h>

void srtf(){
    int at[10], bt[10], rt[10], wt[10], tat[10], ct[10];
    int n, i, time = 0, min, st = -1, completed = 0;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(completed != n){
        min = 9999;
        st = -1;

        for(i = 0; i < n; i++){
            if(at[i] <= time && rt[i] > 0 && rt[i] < min){
                min = rt[i];
                st = i;
            }
        }

        if(st == -1){
            time++;
            continue;
        }

        rt[st]--;

        if(rt[st] == 0){
            completed++;
            ct[st] = time + 1;
            tat[st] = ct[st] - at[st];
            wt[st] = tat[st] - bt[st];

            awt += wt[st];
            atat += tat[st];
        }

        time++;
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);
}

int main(){
    srtf();
    return 0;
}

