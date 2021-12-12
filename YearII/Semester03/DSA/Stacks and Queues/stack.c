#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include "stackFun.h"

int main()
{
	int choice;
	printf("\t\t1.Push\n");
	printf("\t\t2.Pop\n");
	printf("\t\t3.Palindrome\n");
	printf("\t\t4.Display\n");
	printf("\t\t5.Exit\n");
	printf(" ");
	for(;;)
	{
		printf("\tEnter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			if (flag)
				printf("\t\nThe poped element: %d\t", item);
			temp = top;
			break;
		case 3:
			pali();
			top = temp;
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\t\t\nInvalid choice:\n");
			break;
		}
	}
	return 0;
}