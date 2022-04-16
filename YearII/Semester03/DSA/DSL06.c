#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4
int ch, front = 0, rear = -1, count = 0;
char q[MAXSIZE], item;
void insert()
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
		printf("\n\t\tDeleted item is %c", item);
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
			printf("%c\t", q[j]);
			j = (j + 1) % MAXSIZE;
		}
	}
}
int main()
{
	do
	{
		printf("\n\t\t1. Insert\nt\t\t2. Delete \n\t\t3. Display \n\t\t4. Exit \n");
		printf("\t\tEnter the Choice:\t");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\t\tEnter the items to be inserted:\t");
			scanf("%c", &item);
			insert();
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
	} while (ch != 4);
	return 0;
}