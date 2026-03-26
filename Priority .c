#include <stdio.h>
#define max 10

struct process
{
    int at;
    int bt;
    int pr;
    int wt;
    int tat;
    int ct;
    int done;
};

void priority_scheduling(struct process p[], int n)
{
    int completed = 0, t = 0;
    float total_wt = 0, total_tat = 0;

    while (completed < n)
    {
        int idx = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].done == 0)
            {
                if (p[i].pr < highest_priority)
                {
                    highest_priority = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == highest_priority)
                {
                    if (p[i].at < p[idx].at)
                        idx = i;
                }
            }
        }

        if (idx != -1)
        {
            p[idx].wt = t - p[idx].at;
            if (p[idx].wt < 0)
                p[idx].wt = 0;

            t = t + p[idx].bt;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].done = 1;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            completed++;
        }
        else
        {
            t++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               p[i].at,
               p[i].bt,
               p[i].pr,
               p[i].ct,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

int main()
{
    int n;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Priority: ");
        scanf("%d", &p[i].pr);

        p[i].done = 0;
    }

    priority_scheduling(p, n);

    return 0;
}
