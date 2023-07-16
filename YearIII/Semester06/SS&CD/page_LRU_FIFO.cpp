#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

static int sequence_length = 5;
static int num_frames = 3;

void FIFO(char sequence[], char frames[]) {
	printf("\nFIFO Algorithm:\n");
	int idx = 0;
	bool present = false;
	printf("PAGE\tFRAMES\tFAULTS");
	for(int i = 0; i < sequence_length; i++) {
		for(int j = 0; j < num_frames; j++)
			if(frames[j] == sequence[i]) {
				present = true;
				break;
			}
		printf("\n%c\t", sequence[i]);
		if(!present) {
			frames[idx++] = sequence[i];
			printf("%s\t Page Fault", frames);
		} else {
			present = !present;
			printf("%s\t Page Hit", frames);
		}
		if(idx == num_frames)
			idx = 0;
	}
}

void LRU(char sequence[], char frames[]) {
	printf("\n\nLRU Algorithm:\n");
	int filled_frames = 0,
	oldest_frame_index = 0;
	bool present = false;
	printf("\nPAGE\tFRAMES\tFAULTS");
	for (int i = 0; i < sequence_length; i++) {
		for (int j = 0; j < num_frames; j++)
			if (frames[j] == sequence[i])
				present = true;
		printf("\n%c\t", sequence[i]);
		
		if (!present && filled_frames != num_frames) {
			frames[oldest_frame_index] = sequence[i];
			if (++filled_frames != num_frames)
				oldest_frame_index++;
		} else {
			if (!present) {
				for (int k = 0; k < oldest_frame_index; k++)
					frames[k] = frames[k + 1];
			}
			frames[oldest_frame_index] = sequence[i];
		}
		printf("%s", frames);
		if (present)
			printf("\tPage Hit");
		else
			printf("\tPage Fault");
		present = false;
	}
}

int main() {
	char frames[3] = {-1, -1, -1};
	static char sequence[6] = "hello";
	//FIFO(sequence, frames);
	for (int i = 0; i < num_frames; i++) //NEEDED!
		frames[i] = -1;
	LRU(sequence, frames);
	return 0;
}
