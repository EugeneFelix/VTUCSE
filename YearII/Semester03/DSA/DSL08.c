#include "stdio.h"
#include "stdlib.h"
#include "string.h"

signed int MAX = 4, count;

struct node
{
	int ssn;
	char name[20];
	char dept[10];
	char design[10];
	int sal;
	char phno[10];
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE; //NODE data type...

int countnodes(NODE first)
{
	NODE temp;
	count = 0;
	temp = first;
	while (temp != NULL)
	{
		count++;
		temp = temp->rlink;
	}
	return count;
}
NODE getnode()
{
	NODE temp;
	temp = malloc(sizeof(struct node));
	temp->rlink = NULL;
	temp->llink = NULL;
	printf("enter SSN\n");
	scanf("%d", &temp->ssn);
	printf("enter name\n");
	scanf("%s", temp->name);
	printf("enter dept\n");
	scanf("%s", temp->dept);
	printf("enter designation\n");
	scanf("%s", temp->design);
	printf("enter salary\n");
	scanf("%d", &temp->sal);
	printf("enter phno\n");
	scanf("%s", temp->phno);
	return temp;
}
void display(NODE first)
{
	NODE temp;
	if (first == NULL)
	{
		printf("No employee data\n");
	}
	else
	{
		temp = first;
		printf("employee data\n");
		printf("SSN\t Name\t Department\t Designation\t Salary\t Phone no\n");
		while (temp != NULL)
		{
			printf("\n%d\t%s\t%s\t%s\t%d\t%s", temp->ssn, temp->name, temp->dept, temp->design, temp->sal, temp->phno);
			temp = temp->rlink;
		}
		printf("\n the no.of nodes is %d\n", countnodes(first));
	}
}

NODE create(NODE first)
{
	NODE temp, cur;
	if (first == NULL)
	{
		temp = getnode();
		first = temp;
		return first;
	}
	else
	{
		temp = getnode();
		cur = first;
		while (cur->rlink != NULL)
		{
			cur = cur->rlink;
		}
		cur->rlink = temp;
		temp->llink = cur;
	}
	return first;
}

NODE insert_front(NODE first)
{
	NODE temp;
	if (countnodes(first) == MAX)
	{
		printf("List is full/overflow\n");
	}
	else
	{
		if (first == NULL)
		{
			temp = getnode();
			first = temp;
		}
		else
		{
			temp = getnode();
			temp->rlink = first;
			first->llink = temp;
			first = temp;
		}
	}
	return first;
}
NODE insert_rear(NODE first)
{
	if (countnodes(first) == MAX)
	{
		printf("list is full/overflow\n");
	}
	else
	{
		first = create(first);
	}
	return first;
}

NODE insertnode(NODE first)
{
	int ch;
	while (1)
	{
		printf("\n1.insert front\n 2.insert rear\n 3.exit\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = insert_front(first);
			display(first);
			break;
		case 2:
			first = insert_rear(first);
			display(first);
			break;
		case 3:
			return first;
		}
	}
	return first;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if (first == NULL)
	{
		printf("list is empty/underflow\n");
	}
	else if (first->rlink == NULL)
	{
		free(first);
		printf("first node deleted\n");
		first = NULL;
		return first;
	}
	else
	{
		temp = first;
		first = first->rlink;
		first->llink = NULL;
		free(temp);
		printf("first node is deleted\n");
	}
	return first;
}

NODE delete_rear(NODE first)
{
	NODE cur, prev;
	if (first == NULL)
	{
		printf("list is empty/underflow\n");
	}
	else if (first->rlink == NULL)
	{
		free(first);
		printf("last node deleted\n");
		first = NULL;
		return first;
	}
	else
	{
		cur = first;
		prev = NULL;
		while (cur->rlink != NULL)
		{
			prev = cur;
			cur = cur->rlink;
		}
		prev->rlink = NULL;
		free(cur);
		printf("last node deleted\n");
	}
	return first;
}

NODE deletenode(NODE first)
{
	int ch;
	while (1)
	{
		printf("1.delete front\n 2.delete rear\n 3.exit\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = delete_front(first);
			display(first);
			break;
		case 2:
			first = delete_rear(first);
			display(first);
			break;
		case 3:
			return first;
		}
	}
	return first;
}

NODE dequeue(NODE first)
{
	int ch;
	while (1)
	{
		printf("1.insert rear\n 2.insert front\n 3.delete rear\n 4.delete front\n 5:exit\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = insert_rear(first);
			display(first);
			break;
		case 2:
			first = insert_front(first);
			display(first);
			break;
		case 3:
			first = delete_rear(first);
			display(first);
			break;
		case 4:
			first = delete_front(first);
			display(first);
			break;
		case 5:
			return first;
		}
	}
	return first;
}

int main()
{
	int ch, i, n;
	NODE first = NULL;
	printf("\n-_-_-_-_-_-_-_-_-_-_Employee Database-_-_-_-_-_-_-_-_-_\n");
	while (1)
	{
		printf("\n\t 1.Create\n\t 2.Display\n\t 3.Insert\n\t 4.Delete\n\t 5.Dequeue\n\t 6.Exit\n");
		printf("\t\t  Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("How many employees do you want to create\n");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				first = create(first);
			}
			break;
		case 2:
			display(first);
			break;
		case 3:
			first = insertnode(first);
			break;
		case 4:
			first = deletenode(first);
			break;
		case 5:
			first = dequeue(first);
			break;
		case 6:
			exit(0);
		default:
			printf("Invalid choice! Please try agai!\n");
		}
	}
	return 0;
}
