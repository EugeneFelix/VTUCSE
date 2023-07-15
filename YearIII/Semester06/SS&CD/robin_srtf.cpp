#include<iostream>
#define MAX_PROCESSES 10
using namespace std;

int current_process, number_processes, time_lapsed, time_quantum;
int total_wait_time = 0, total_turnaround_time = 0;
int endTime, smallest;
int processes_remaining = 0, sum_wait = 0, sum_turnaround = 0;
int at[MAX_PROCESSES] = {0, 2, 4, 6, 8};
int bt[MAX_PROCESSES] = {5, 7, 3, 2, 6};
int rem_time[MAX_PROCESSES] = {0};

void round_robin() {
	time_quantum = 2;
	processes_remaining = number_processes;
	cout << "\nProcess Time | Turnaround Time | Waiting Time" << endl;
	bool finished = false;
	time_lapsed = 0;
	current_process = 0;
	while(!finished) {
		if (rem_time[current_process] <= time_quantum && rem_time[current_process] > 0) {
			time_lapsed += rem_time[current_process];
			rem_time[current_process] = 0;
			finished = true;
		} else if (rem_time[current_process] > 0) {
			time_lapsed += time_quantum;
			rem_time[current_process] -= time_quantum;
		}
		if (rem_time[current_process] == 0 && finished) {
			processes_remaining--;
			cout << "P[" << current_process + 1 << "]\t\t|\t" << time_lapsed << "\t\t|\t" << time_lapsed - bt[current_process] << endl;
			total_turnaround_time += time_lapsed;
			total_wait_time += time_lapsed - bt[current_process];
			finished = false;
		}
		if (current_process == number_processes - 1)
			current_process = 0;
		else
			current_process++;
		if (processes_remaining == 0)
            break;
	}
	cout << "\nAverage Waiting Time = " << total_wait_time * 1.0 / number_processes << endl;
	cout << "Average Turnaround Time = " << total_turnaround_time * 1.0 / number_processes << endl;
}

void srt() {
	current_process = 0;
	cout << "\nProcess | Turnaround Time | Waiting Time" << endl;
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
			cout << "P[" << smallest + 1 << "]\t|\t" << endTime - at[smallest] << "\t|\t" << endTime - bt[smallest] - at[smallest] << endl;
			sum_wait += endTime - bt[smallest] - at[smallest];
			sum_turnaround += endTime - at[smallest];
		}
	}
	cout << "\nAverage Waiting Time = " << sum_wait * 1.0 / number_processes << endl;
	cout << "Average Turnaround Time = " << sum_turnaround * 1.0 / number_processes << endl;
}

int main() {
	number_processes = 5;
	for (int i = 0; i < number_processes; i++)
		rem_time[i] = bt[i];
	round_robin();
	srt();
	return 0;
}