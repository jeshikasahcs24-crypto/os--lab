#include <stdio.h>
struct process
{
    int at;
    int bt;
    int rt;
    int pr;
    int wt;
    int tat;
    int ct;
};
#define max 100
void PriorityPreemptive(struct process p[], int n)
{
    int t = 0, completed = 0;
    int min_pr, idx;

    for (int i = 0; i < n; i++)
    {
        p[i].rt = p[i].bt;
    }

    while (completed < n)
    {
        idx = -1;
        min_pr = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].rt > 0)
            {
                if (p[i].pr < min_pr)
                {
                    min_pr = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == min_pr)
                {
                    if (p[i].at < p[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }
        if (idx == -1)
        {
            t++;
            continue;
        }
        p[idx].rt--;
        t++;

        if (p[idx].rt == 0)
        {
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
    }
    printf("\nID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);

        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main()
{
    int n;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &p[i].at);

        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].bt);

        printf("Enter priority for process %d: ", i);
        scanf("%d", &p[i].pr);
    }

    PriorityPreemptive(p, n);

    return 0;
}
