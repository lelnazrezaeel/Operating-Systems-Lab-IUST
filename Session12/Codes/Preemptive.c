#include <stdio.h>

void print_gantt_chart(int p[], int bt[], int wt[], int tat[], int n);

int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total = 0, pos, temp, avg_wt, avg_tat;

    puts("PREEMPTIVE PRIORITY SCHEDULING ALGORITHM");
    printf("Enter Total Number of Process:");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time:");
        scanf("%d", &bt[i]);
        printf("Priority:");
        scanf("%d", &pr[i]);
        p[i] = i + 1; 
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; 

    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = total / n;
    total = 0;

    puts("");
    puts("+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+------------+--------------+-----------------+");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n", p[i], bt[i], wt[i], tat[i]);
        puts("+-----+------------+--------------+-----------------+");
    }

    avg_tat = total / n; 
    printf("\n\nAverage Waiting Time=%d", avg_wt);
    printf("\nAverage Turnaround Time=%d\n", avg_tat);

    puts("");
    puts("          GANTT CHART          ");
    puts("          ***********          ");
    print_gantt_chart(p, bt, wt, tat, n);
    return 0;
}

void print_gantt_chart(int p[], int bt[], int wt[], int tat[], int n)
{
    int i, j;
    printf(" ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i] - 1; j++)
            printf(" ");
        printf("P%d", p[i]);
        for (j = 0; j < bt[i] - 1; j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bt[i]; j++)
            printf("  ");
        if (tat[i] > 9)
            printf("\b");
        printf("%d", tat[i]);
    }
    printf("\n");
}