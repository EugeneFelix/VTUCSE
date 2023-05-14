#include<stdio.h>

int current_process, number_processes, time_lapsed, flag = 0, time_quantum, choice = 0;
int total_wait_time = 0, total_turnaround_time = 0, at[10], bt[10], rem_time[10];
int endTime, smallest;
int processes_remaining = 0, sum_wait = 0, sum_turnaround = 0;
void round_robin() {
  printf("Enter Time Quantum:\t");
  scanf("%d", &time_quantum);
  processes_remaining = number_processes;
  printf("\nProcess Time|Turnaround Time|Waiting Time\n");
  for (time_lapsed = 0, current_process = 0; processes_remaining != 0;) {
    if (rem_time[current_process] <= time_quantum && rem_time[current_process] > 0) {
      time_lapsed += rem_time[current_process];
      rem_time[current_process] = 0;
      flag = 1;
    } else if (rem_time[current_process] > 0) {
      rem_time[current_process] -= time_quantum;
      time_lapsed += time_quantum;
    }
    if (rem_time[current_process] == 0 && flag == 1) {
      processes_remaining--;
      printf("P[%d]\t\t|\t%d\t\t|\t%d\n", current_process + 1, time_lapsed - at[current_process], time_lapsed - at[current_process] - bt[current_process]);
      /****************************/
      total_wait_time += time_lapsed - at[current_process] - bt[current_process];
      total_turnaround_time += time_lapsed - at[current_process];
      /***************************/
      flag = 0;
    }
    if (current_process == number_processes - 1)
      current_process = 0;
    else if (at[current_process + 1] <= time_lapsed)
      current_process++;
    else
      current_process = 0;
  }
  printf("\nAverage Waiting Time= %.2f\n", total_wait_time * 1.0 / number_processes);
  printf("Avg Turnaround Time = %.2f\n", total_turnaround_time * 1.0 / number_processes);
}
void srt() {
  current_process = 0;
  printf("\nProcess| Turnaround Time| Waiting Timen\n");
  rem_time[9] = 9999;
  for (time_lapsed = 0; current_process != number_processes; time_lapsed++) {
    smallest = 9;
    for (int i = 0; i < number_processes; i++)
      if (at[i] <= time_lapsed && rem_time[i] < rem_time[smallest] && rem_time[i] > 0)
        smallest = i;
    rem_time[smallest]--;
    if (rem_time[smallest] == 0) {
      current_process++;
      endTime = time_lapsed + 1;
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
  for (int i = 0; i < number_processes; i++) {
    printf("Enter arrival time for process P%d : ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter burst time for process P%d :", i + 1);
    scanf("%d", &bt[i]);
    rem_time[i] = bt[i];
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