#include <stdio.h> #include<stdlib.h>
int n, *a;
int count = 0;
void create()
{
	int i;
	a = (int *)malloc(n * sizeof(int));
	if (a == NULL)
	{
		printf("array not created\n");
		exit(0);
	}
	printf("\n array created successfully");
	printf("\n enter the elements of array\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}
void display()
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
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
void delete (pos)
{
	int j, item;
	item = a[pos];
	printf("the deleted item is %d\n", item);
	for (j = pos; j < n - 1; j++)
	{
		a[j] = a[j + 1];
	}
	n--;
	if (n == 0)
		printf("no element in the array\n");
}
int main()
{
	int ch, ele, pos;
	while (1)
	{
		printf("enter the choice\n1:createarray\n2:display array\n3:insertionitem\n5:exit\n");
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
			printf("\n enter the position to be inserted\n");
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
			printf("\n enter the position\n");
			scanf("%d", &pos);
			if ((pos >= 0) && (pos < n))
			{
				delete (pos);
			}
			else
			{
				goto label2;
			}
			break;
		default:
			exit(0);
		}}
		 return 0;
	}