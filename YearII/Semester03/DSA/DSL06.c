#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4
int front = 0, rear = -1, count = 0;
char q[MAXSIZE], item;
void insert(int item)
{
	if (count == MAXSIZE)
		printf("\n Queue is full");
	else
	{
		rear = (rear + 1) % MAXSIZE;
		q[rear] = item;
		count++;
	}
}
void delete ()
{
	if (count == 0)
		printf("\n\t\tQueue is empty \n");
	else
	{
		item = q[front];
		printf("\n\t\tDeleted item is %d", item);
		front = (front + 1) % MAXSIZE;
		count--;
	}
}
void display()
{
	int i, j;
	if (count == 0)
		printf("\n\t\tQueue is Empty");
	else
	{
		j = front;
		printf("\n\t\tContent of Queue is \n");
		for (i = 1; i <= count; i++)
		{
			printf("%d\t", q[j]);
			j = (j + 1) % MAXSIZE;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n\t\t1. Insert\nt\t\t2. Delete \n\t\t3. Display \n\t\t4. Exit \n");
		printf("\t\tEnter the Choice:\t");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\t\tEnter the items to be inserted:\t");
			scanf("%d", &item);
			insert(item);
			break;
		case 2:
			delete ();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	return 0;
}