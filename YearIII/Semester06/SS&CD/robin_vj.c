#include<stdio.h>

int count, j, number_processes, time, flag = 0, time_quantum, choice = 0;
int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
int endTime, i, smallest;
int remain = 0, sum_wait = 0, sum_turnaround = 0;
void round_robin() {
  printf("Enter Time Quantum:\t");
  scanf("%d", & time_quantum);
  remain = number_processes;
  printf("\nProcess time|Turnaround Time|Waiting Time\n");
  for (time = 0, count = 0; remain != 0;) {
    if (rt[count] <= time_quantum && rt[count] > 0) {
      time += rt[count];
      rt[count] = 0;
      flag = 1;
    } else if (rt[count] > 0) {
      rt[count] -= time_quantum;
      time += time_quantum;
    }
    if (rt[count] == 0 && flag == 1) {
      remain--;
      printf("P[%d]\t\t|\t%d\t\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
      wait_time += time - at[count] - bt[count];
      turnaround_time += time - at[count];
      flag = 0;
    }
    if (count == number_processes - 1)
      count = 0;
    else if (at[count + 1] <= time)
      count++;
    else
      count = 0;
  }
  printf("\nAverage Waiting Time= %.2f\n", wait_time * 1.0 / number_processes);
  printf("Avg Turnaround Time = %.2f\n", turnaround_time * 1.0 / number_processes);
}
void srt() {
  remain = 0;
  printf("\nProcesst|Turnaround Time| Waiting Timen\n");
  rt[9] = 9999;
  for (time = 0; remain != number_processes; time++) {
    smallest = 9;
    for (i = 0; i < number_processes; i++)
      if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
        smallest = i;
    rt[smallest]--;
    if (rt[smallest] == 0) {
      remain++;
      endTime = time + 1;
      printf("\nP[%d]\t|\t%d\t|\t%d", smallest + 1, endTime - at[smallest], endTime - bt[smallest] - at[smallest]);
      printf("\n");
      sum_wait += endTime - bt[smallest] - at[smallest];
      sum_turnaround += endTime - at[smallest];
    }
  }
  printf("\nAverage waiting time = %f\n", sum_wait * 1.0 / number_processes);
  printf("Average Turnaround time = %f", sum_turnaround * 1.0 / number_processes);
}
int main() {
  printf("1.Round Robin \n2.SRTF \n");
  scanf("%d", &choice);
  printf("Enter no of Processes : ");
  scanf("%d", &number_processes);
  for (i = 0; i < number_processes; i++) {
    printf("Enter arrival time for process P%d : ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter burst time for process P%d :", i + 1);
    scanf("%d", &bt[i]);
    rt[i] = bt[i];
  }
  switch (choice) {
  case 1:
    round_robin();
    break;
  case 2:
    srt();
    break;
  }
  return 0;
}