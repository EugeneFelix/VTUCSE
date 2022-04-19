#include "stdio.h"
#include "stdlib.h"
int MAX = 4, count;
struct student
{
	char usn[10];
	char name[30];
	char branch[5];
	int sem;
	char phno[10];
	struct student *link;
};
typedef struct student *NODE;

int countnodes(NODE first)
{
	NODE temp;
	count = 0;
	temp = first;
	while(temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}
NODE getnode(NODE first)
{
	NODE temp;
	temp = malloc(sizeof(struct student));
	printf("enter usn:\n");
	scanf("%s", temp->usn);
	printf("enter the name\n");
	scanf("%s", temp->name);
	printf("enter the branch\n");
	scanf("%s", temp->branch);
	printf("enter the sem\n");
	scanf("%d", &temp->sem);
	printf("enter the phno:\n");
	scanf("%s", temp->phno);
	temp->link = NULL;
	first = temp;
	return first;
}
void display(NODE first)
{
	NODE temp;
	if (first == NULL)
		printf("\t\tNo student data\n");
	else
	{
		temp = first;
		printf("\r...STUDENT DATA..\n");
		printf("\rUSN\t NAME\t BRANCH\t SEM\t PHNO\n");
		while (temp != NULL)
		{
			printf("\n%s\t %s\t %s\t %d\t %s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
			temp = temp->link;
		}
		printf("the number of nodes in list is %d\n", countnodes(first));
	}
}
NODE create(NODE first)
{
	NODE temp;
	if (first == NULL) // first node to be inserted i,e, List is Empty!!
	{
		temp = getnode(first);
		first = temp;
	}
	else
	{ //Only front insertion!
		temp = getnode(first);
		temp->link = first;
		first = temp;
	}
	return first;
}

NODE insert_front(NODE first)
{
	if (countnodes(first) == MAX)
		printf("\t\tList is full/overflow!!\n");
	else
		first = create(first);
	return first;
}

NODE insert_rear(NODE first)
{
	NODE temp, cur;
	cur = first;
	if (countnodes(first) == MAX)
		printf("\n\tList is full!");
	else
	{
		if (first == NULL)
		{
			temp = getnode(first);
			first = temp;
		}
		else
		{
			temp = getnode(first);
			while (cur->link != NULL)
			{
				cur = cur->link;
			}
			cur->link = temp;
		}
	}
	return first;
}

NODE insert_node(NODE first)
{
	int ch;
	while (1)
	{
		printf("\n\tMenu\n 1:insert@front\n 2:insert@rear\n 3:exit\n");
		printf("\tEnter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = insert_front(first);
			break;
		case 2:
			first = insert_rear(first);
			break;
		case 3:
			return first;
		}
		display(first);
	}
	return first;
}

NODE delete_front(NODE first)
{
	NODE temp;
	if (first == NULL)
		printf("\tList is empty/underflow!!\n");
	else
	{
		temp = first;
		first = first->link;
		free(temp);
		printf("\tFront node is deleted\n");
	}
	return first;
}
NODE delete_rear(NODE first)
{
	NODE prev, cur;
	cur = first;
	prev = NULL;
	if (first == NULL)
	{
		printf("\tList is empty/underflow!!\n");
		return first;
	}
	if (first->link == NULL)
	{
		free(first);
		printf("\tLast node deleted\n");
		return NULL;
	}
	else
	{
		while (cur->link != NULL)
		{
			prev = cur;
			cur = cur->link;
		}
		prev->link = NULL;
		free(cur);
		printf("last node is deleted\n");
	}
	return first;
}
NODE deletenode(NODE first)
{
	int ch;
	while (1)
	{
		printf("\n 1:delete from front\n 2:delete from rear\n 3:Exit \n");
		printf("enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = delete_front(first);
			break;
		case 2:
			first = delete_rear(first);
			break;
		case 3:
			return first;
		}
		display(first);
	}
	return first;
}
NODE stack(NODE first)
{
	int ch;
	while (1)
	{
		printf("SLL used as stack");
		printf("\n 1.PUSH\t 2.POP\t 3.EXIT\n");
		printf("enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = insert_front(first);
			break;
		case 2:
			first = delete_front(first);
			break;
		case 3:
			return first;
		}
		display(first);
	}
	return first;
}
NODE queue(NODE first)
{
	int ch;
	while (1)
	{
		printf("\nSLL used as queue\n");
		printf("\n 1.insert\t 2.delete\t 3.exit\n");
		printf("enter the choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			first = insert_rear(first);
			break;
		case 2:
			first = delete_front(first);
			break;
		case 3:
			return first;
		}
		display(first);
	}
	return first;
}
int main()
{
	int ch, i, n;
	NODE first;
	first = NULL;
	printf("...STUDENT DATABASE...");
	while (1)
	{
		printf("\n 1.create\n 2.display\n 3.insert\n 4.delete\n 5.stack\n 6.queue\n 7.exit\n");
		printf("enter your choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("how many students database you want to create\n");
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
			first = insert_node(first);
			break;
		case 4:
			first = deletenode(first);
			break;
		case 5:
			first = stack(first);
			break;
		case 6:
			first = queue(first);
			break;
		case 7:
			exit(0);
		default:
			printf("invalid option\n");
		}
	}
	return 0;
}