#include <iostream>
#include <climits>
#define MAX_PROCESSES 10
using namespace std;

int current_process = 0, NUM_PROCESSES = 3, time_lapsed = 0, slice = 4;
int total_wait_time = 0, total_turnaround_time = 0;
int processes_remaining = 0, sum_wait = 0, sum_turnaround = 0;
int at[MAX_PROCESSES] = {1, 2, 4};
int bt[MAX_PROCESSES] = {24, 3, 3};
int rem_time[MAX_PROCESSES] = {24, 3, 3};

void round_robin() {
	processes_remaining = NUM_PROCESSES;
	cout << "\nProcess Time | Turnaround Time | Waiting Time" << endl;
	bool finished = false;
	while(processes_remaining != 0) {
		if (rem_time[current_process] <= slice && rem_time[current_process] > 0) {
			time_lapsed += rem_time[current_process];
			rem_time[current_process] = 0; //Line 27
			finished = true;
		} else if (rem_time[current_process] > 0) {
			time_lapsed += slice;
			rem_time[current_process] -= slice;
		}
		if (rem_time[current_process] == 0 && finished) {
			processes_remaining--;
			cout << "P[" << current_process + 1 << "]\t\t|\t" << time_lapsed << "\t\t|\t" << time_lapsed - bt[current_process] << endl;
			total_turnaround_time += time_lapsed;
			total_wait_time += time_lapsed - bt[current_process];
			finished = false;
		}
		if (current_process == NUM_PROCESSES - 1)
			current_process = 0;
		else
			current_process++;
	}
	cout << "\nAverage Waiting Time = " << total_wait_time * 1.0 / NUM_PROCESSES << endl;
	cout << "Average Turnaround Time = " << total_turnaround_time * 1.0 / NUM_PROCESSES << endl;
}

void srtf() {
	bool completed[3] = { false };
	cout << "\nProcess Time | Turnaround Time | Waiting Time" << endl;
	int currentTime = 0;
	int completedProcesses = 0;
	while (completedProcesses < NUM_PROCESSES) {
		int shortestProcess = -1;
		int shortestTime = INT_MAX;
		for (int i = 0; i < NUM_PROCESSES; i++)
			if (at[i] <= currentTime && !completed[i] && rem_time[i] < shortestTime) {
				shortestProcess = i;
				shortestTime = rem_time[i];
			}
		if (shortestProcess == -1) {
			currentTime++;
			continue;
		}
		rem_time[shortestProcess]--;
		if (rem_time[shortestProcess] == 0) {
			completedProcesses++;
			completed[shortestProcess] = true;
			cout << "Process " << shortestProcess + 1 << ": Turnaround Time = " << currentTime + 1 - at[shortestProcess];
			cout << ", Waiting Time = " << currentTime + 1 - at[shortestProcess] - bt[shortestProcess] << endl;
		}
		currentTime++;
	}
}
int main() {
	//round_robin(); // Call only one at a time! GLOBALITY!
	srtf();
	return 0;
}