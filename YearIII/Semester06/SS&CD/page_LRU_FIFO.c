#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void FIFO(char sequence[], int sequence_length, int num_frames) {
    char frames[num_frames];
    int next_frame_index = 0;
    bool present = false;
    printf("PAGE\tFRAMES\tFAULTS");
    for(int i = 0; i < sequence_length; i++) {
        for(int k = 0; k < num_frames; k++) {
            if(frames[k] == sequence[i]) {
                present = true;
                break;
            }
        }
        printf("\n%c\t", sequence[i]);
        if(!present) {
            frames[next_frame_index++] = sequence[i];
            printf("%s", frames);
            printf("\tPage Fault");
        }
        else {
            present = !present;
            printf("%s", frames);
            printf("\tPage Hit");
        }
        if(next_frame_index == num_frames)
            next_frame_index = 0;
    }
}

void LRU(char sequence[], char frames[], int sequence_length, int num_frames) {
	int i, j = 0, k, m, flag = 0, top = 0;
	printf("\nPAGE\tFRAMES\tFAULTS");
	for(i = 0; i < sequence_length; i++) {
		for(k = 0; k < num_frames; k++)
		if(frames[k] == sequence[i])
		flag = 1;
		printf("\n%c\t", sequence[i]);
		if(j != num_frames && flag != 1) {
			frames[top] = sequence[i];
			if(++j != num_frames)
			top++;
		}
		else
		{
			if(flag != 1) {
				for(k = 0; k < top; k++)
				frames[k] = frames[k + 1];
				frames[top] = sequence[i];
			}
			else
			{
				for(m = k; m < top; m++)
				frames[m] = frames[m + 1];
				frames[top] = sequence[i];
			}
		}
		printf("%s", frames);
		if(flag == 0)
		printf("\tPage Fault");
		else
		printf("\tPage Hit");
		flag = 0;
	}
}

int main() {
    static int sequence_length = 5;
    static int num_frames = 3;
    static char frames[10];
    static char sequence[25] = "hello";

    printf("PAGE REPLACEMENT ALGORITHMS\n");
    printf("\nFIFO Algorithm:\n");
    FIFO(sequence, sequence_length, num_frames);

    printf("\n\nLRU Algorithm:\n");
    for (int i = 0; i < num_frames; i++) //NEEDED!
    	frames[i] = -1;
    LRU(sequence, frames, sequence_length, num_frames);

    return 0;
}
