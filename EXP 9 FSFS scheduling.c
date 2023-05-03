#include <stdio.h>
#define N 3
int main()
{
	int i;
    int pid[] = {0, 1, 2};        
    int burst_time[] = {2, 4, 8}; 
    int arrival_time[] = {0, 0, 0}; 
    int waiting_time[N], turnaround_time[N];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    waiting_time[0] = 0;
    for (i = 1; i < N; i++) 
	{
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for (i = 0; i < N; i++) 
	{
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    for (i = 0; i < N; i++) 
	{
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= N;
    avg_turnaround_time /= N;
    printf("Process\tBurst time\tArrival time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < N; i++) 
	{
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    return 0;
}#include <stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
int main()
{
	int i,j;
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2}};
    int max[MAX_PROCESSES][MAX_RESOURCES] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};
    int available[MAX_RESOURCES] = {3, 2, 1};
    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (i = 0; i < MAX_PROCESSES; i++) 
	{
        for (j = 0; j < MAX_RESOURCES; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Need matrix:\n");
    for (i = 0; i < MAX_PROCESSES; i++) 
	{
        printf("P%d: ", i);
        for (j = 0; j < MAX_RESOURCES; j++) 
		{
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    return 0;
}
