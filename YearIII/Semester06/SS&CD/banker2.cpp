#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

int main() {
	static int num_resources = 3;
	static int num_processes = 5;
	int count = 0;
	static int available[MAX_RESOURCES] = {3, 3, 2}; 
	static int maximum[MAX_PROCESSES][MAX_RESOURCES] = {
		{7, 5, 3},
		{3, 2, 2},
		{7, 0, 2},
		{2, 2, 2},
		{4, 3, 3}
	};
	static int allocation[MAX_PROCESSES][MAX_RESOURCES] = {
		{0, 1, 0},
		{2, 0, 0},
		{3, 0, 2},
		{2, 1, 1},
		{0, 0, 2}
	};

	int need[MAX_PROCESSES][MAX_RESOURCES];
	bool finish[MAX_PROCESSES] = {false};
	int safe_sequence[MAX_PROCESSES];

	for (int i = 0; i < num_processes; i++)
		for (int j = 0; j < num_resources; j++)
			need[i][j] = maximum[i][j] - allocation[i][j];
	for (int i = 0; i < num_processes; i++) {
		for (int j = 0; j < num_resources; j++)
			std::cout << need[i][j] << " ";
		std::cout << endl;
	}
	while (count < num_processes) {
		bool found = false;
		for (int i = 0; i < num_processes; i++) {
			if (!finish[i]) {
				bool safe = true;
				for (int j = 0; j < num_resources; j++)
					if (need[i][j] > available[j]) {
						safe = false;
						break;
					}
				if (safe) {
					for (int j = 0; j < num_resources; j++)
						available[j] += allocation[i][j];
					finish[i] = true;
					safe_sequence[count++] = i;
					found = true;
					printf("Process %d runs to completion!\n", i);
				}
			}
		}
		if (!found) break;
	}

	if (count == num_processes) {
		printf("Safe sequence: ");
		for (int i = 0; i < num_processes; i++)
			printf("%d ", safe_sequence[i]);
	printf("\n");
	} else
		printf("Unsafe state\n");
	return 0;
}