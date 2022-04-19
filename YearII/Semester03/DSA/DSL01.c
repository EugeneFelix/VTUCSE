#include <stdio.h>
#include <stdlib.h>

int n, a[99];

void create()
{
	int i;
	printf("\n\t\tEnter the elements of array\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}
void display()
{
	int i;
	for (i = 0; i < n; i++)
		printf("\t\t%d\n", a[i]);
}
void insert(ele, pos)
{
	int j = n - 1;
	while (j >= pos)
	{
		a[j + 1] = a[j];
		j--;
	}
	a[pos] = ele;
	n++;
}
void deleteElem(pos)
{
	int j, item;
	item = a[pos];
	printf("The Deleted Element is %d\n", item);
	for (j = pos; j < n - 1; j++)
		a[j] = a[j + 1];
	n--;
	if (n == 0)
		printf("\t\tThe array is empty!\n");
}
int main()
{
	int ch, ele, pos;
	while (1)
	{
		printf("\t\tEnter your choice\n\t\t1. Create a new Array\n\t\t2. Display contents of Array.\n\t\t3. Insert a new element.\n\t\t4. deleteElem an existing element.\n\t\t5. EXIT!\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n enter the size of an array\n");
			scanf("%d", &n);
			create(n);
			break;
		case 2:
			display();
			break;
		case 3:
			printf("enter the element to be inserted\n");
			scanf("%d", &ele);
		label:
			printf("\n\t\tEnter the position to be inserted\n");
			scanf("%d", &pos);
			if (pos >= 0 && pos < n)
			{
				insert(ele, pos);
			}
			else
			{
				goto label;
			}
			break;
		case 4:
		label2:
			printf("\n\t\tEnter the position\n");
			scanf("%d", &pos);
			if ((pos >= 0) && (pos < n))
			{
				deleteElem(pos);
			}
			else
			{
				goto label2;
			}
			break;
		default:
			exit(0);
		}
	}
	return 0;
}