#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int burst_time[50], process[50], wating_time[50], turnaround_time[50], priority[50];
    int i, j;
    int n, total = 0, pos;

    printf("Enter Number Of Processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for Process P%d : ", i + 1);
        scanf("%d%d", &burst_time[i], &priority[i]);
        process[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
            if (priority[j] < priority[pos])
                pos = j;

        swap(&priority[i], &priority[pos]);
        swap(&burst_time[i], &burst_time[pos]);
        swap(&process[i], &process[pos]);
    }

    wating_time[0] = 0;

    for (i = 1; i < n; i++)
    {
        wating_time[i] = 0;
        for (j = 0; j < i; j++)
            wating_time[i] += burst_time[j];

        total += wating_time[i];
    }

    int average_waiting_time = total / n;
    total = 0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + wating_time[i];
        total += turnaround_time[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d", process[i], burst_time[i], wating_time[i], turnaround_time[i]);
    }

    int average_turnaround_time = total / n;
    printf("\n\nAverage Waiting Time : %d", average_waiting_time);
    printf("\nAverage Turnaround Time : %d\n", average_turnaround_time);

    return 0;
}