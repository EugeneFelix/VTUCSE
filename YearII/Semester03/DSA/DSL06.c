#include <stdio.h> #include<stdlib.h>
#define MAXSIZE 4
int ch, front = 0, rear = -1, count = 0;
char q[MAXSIZE], item;
void insert()
{
	if (count == MAXSIZE)
	{
		printf("\n Queue is full");
	}
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
	{
		printf("\n Queue is empty \n");
	}
	else
	{
		item = q[front];
		printf("\n Deleted item if %c", item);
		front = (front + 1) % MAXSIZE;
		count--;
	}
}
void display()
{
	int i, j;
	if (count == 0)
	{
		printf("\n Queue is Empty"); }
else {
j=front;
printf("\n Content of Queue is \n"); for(i=1; i<=count; i++) {
printf(" %c\t",q[j]); j=(j+1)%MAXSIZE;
} } }
int main() {
do {
printf("\n 1. Insert \n2. Delete \n3.Display \n4.Exit \n");
printf("Enter the Choice :"); scanf("%d",&ch); switch(ch) {
case 1: printf("Enter the items to be inserted :");
scanf(" %c",&item); insert(); break;
case 2:
delete(); break;
case 3:
display(); break;
case 4:
exit(0); break;
} }
while(ch!=4); return 0;
}