#include<stdio.h>
#include<stdlib.h>

void fifoPageReplacement(int pages[], int page_count, int frame_count) {
    int frame[frame_count];
    int front = 0, rear = 0;
    int page_faults = 0;

    for (int i = 0; i < page_count; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < frame_count; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (rear < frame_count) {
                frame[rear++] = page;
            } else {
                printf("Page Fault - Replace %d\n", frame[front]);
                frame[front++] = page;
                if (front == frame_count)
                    front = 0;
            }

            page_faults++;
            printf("Page %d -> ", page);
            printf("Frame: ");
            for (int j = 0; j < frame_count; j++) {
                printf("%d ", frame[j]);
            }
            printf("  Fault\n");
        } else {
            printf("Page %d -> ", page);
            printf("Frame: ");
            for (int j = 0; j < frame_count; j++) {
                printf("%d ", frame[j]);
            }
            printf("  Hit\n");
        }
    }

    printf("Total page faults: %d\n", page_faults);
}

void LRU(char sequence[], char frames[], int sequence_length, int num_frames) {
	int i,
	j = 0,
	k,
	m,
	flag = 0,
	top = 0;
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
	static int sequence_length = 10;
	static int num_frames = 3;
	static int frames[10];
	static int sequence[25] = {1, 2, 4, 5, 4, 6, 7, 3, 6, 2};

	printf("PAGE REPLACEMENT ALGORITHMS\n");
	printf("\nFIFO Algorithm:\n");
	fifoPageReplacement(sequence, sequence_length, num_frames);
	
	return 0;
}