#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 5
typedef struct employee
{
	int id;
	char name[20];
} EMPLOYEE;
void initial_hashtable(EMPLOYEE a[])
{
	int i;
	for (i = 0; i < HASH_SIZE; i++)
	{
		a[i].id = 0;
	}
}
int H(int k)
{
	return k % HASH_SIZE;
}
int insert_hashtable(int id, char name[], EMPLOYEE a[])
{
	int i, index, hvalue;
	hvalue = H(id);
	for (i = 0; i < HASH_SIZE; i++)
	{
		index = (hvalue + i) % HASH_SIZE;
		if (a[index].id == 0)
		{
			a[index].id = id;
			strcpy(a[index].name, name);
			break;
		}
	}
	if (i == HASH_SIZE)
	{
		return 0;
	}
	return 0;
}
int search_hashtable(int key, EMPLOYEE a[])
{
	int i, index, hvalue;
	hvalue = H(key);
	for (i = 0; i < HASH_SIZE; i++)
	{
		index = (hvalue + i) % HASH_SIZE;
		if (key == a[index].id)
			return 1;
		if (a[index].id == 0)
			return 0;
	}
}
void display_hashtable(EMPLOYEE a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("a[%d]=%d %s\n", i, a[i].id, a[i].name);
}
int main()
{
	EMPLOYEE a[10];
	char name[20];
	int key, id, i, ch, flag, n;
	initial_hashtable(a);
	while (1)
	{
		printf("\n\t-_-_-_-_-_-_-_-_-_-_MENU-_-_-_-_-_-_-_-_-_-_\n\t1.Insert\n\t2.Search\n\t3.Display\n\t4.Exit\n");
		printf("\tEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the no. of emps: ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("Enter emp id: ");
				scanf("%d", &id);
				printf("Enter name: ");
				scanf("%s", name);
				insert_hashtable(id, name, a);
			}
			break;
		case 2:
			printf("Enter the emp id: ");
			scanf("%d", &key);
			flag = search_hashtable(key, a);
			if (flag == 0)
				printf("Key not found\n");
			else
				display_hashtable(a, HASH_SIZE);
			printf("\n");
			break;
		case 3:
			printf("Contents of hash table\n");
			display_hashtable(a, HASH_SIZE);
			printf("\n");
			break;
		case 4:
			exit(0);
		default:
			printf("Invalid choice\n");
		}
	}
	return 0;
}