#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
	int coeff, expx, expy, expz, flag;
	struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	return x;
}

NODE insert_rear(int coeff, int expx, int expy, int expz, NODE head)
{
	NODE temp, cur;
	temp = getnode();
	temp->coeff = coeff;
	temp->expx = expx;
	temp->expy = expy;
	temp->expz = expz;
	temp->link = NULL;
	cur = head->link;
	while (cur->link != head)
	{
		cur = cur->link;
	}
	cur->link = temp;
	temp->link = head;
	return head;
}


NODE read_poly(NODE head)
{
	int expx, expy, expz, coeff, ch = 1;
	while (ch != 0)
	{
		printf("\tEnter the coeff\n");
		scanf("%d", &coeff);
		printf("\tEnter power ofx\n");
		scanf("%d", &expx);
		printf("\tEnter the power y\n");
		scanf("%d", &expy);
		printf("\tEnter the power z\n");
		scanf("%d", &expz);
		head = insert_rear(coeff, expx, expy, expz, head);
		printf("\tPess 1 to enter one more item or 0 to end\n");
		scanf("%d", &ch);
	}
	return head;
}

void display(NODE head)
{
	NODE temp;
	if (head->link == head)
	{
		printf("\t\tPolynomial doesn't exist!\n");
	}
	else
	{
		temp = head->link;
		while (temp != head)
		{
			printf("\t\t%dx^%dy^%dz^%d", temp->coeff, temp->expx, temp->expy, temp->expz);
			if (temp->link != head)
			{
				printf("+");
			}
			temp = temp->link;
		}
		printf("\n");
	}
}
NODE add_poly(NODE head1, NODE head2, NODE head3)
{
	NODE temp1, temp2;
	int x1, x2, y1, y2, z1, z2, coeff1, coeff2, coeff;
	temp1 = head1->link;
	while (temp1 != head1)
	{
		x1 = temp1->expx;
		y1 = temp1->expy;
		z1 = temp1->expz;
		coeff1 = temp1->coeff;
		temp2 = head2->link;
		while (temp2 != head2)
		{
			x2 = temp2->expx;
			y2 = temp2->expy;
			z2 = temp2->expz;
			coeff2 = temp2->coeff;
			if (x1 == x2 && y1 == y2 && z1 == z2)
				break;
			temp2 = temp2->link;
		}
		if (temp2 != head2)
		{
			coeff = coeff1 + coeff2;
			temp2->flag = 1;
			if (coeff != 0)
				head3 = insert_rear(coeff, x1, y1, z1, head3);
		}
		else
			head3 = insert_rear(coeff1, x1, y1, z1, head3);
		temp1 = temp1->link;
	}
	temp2 = head2->link;
	while (temp2 != head2)
	{
		if (temp2->flag == 0)
		{
			head3 = insert_rear(temp2->coeff, temp2->expx, temp2->expy, temp2->expz, head3);
		}
		temp2 = temp2->link;
	}
	return head3;
}


void evaluate(NODE head)
{
	NODE temp;
	int x, y, z;
	double result = 0;
	printf("\tEnter x,y,z values\n");
	scanf("%d%d%d", &x, &y, &z);
	temp = head->link;
	while (temp != head)
	{
		result = result + (temp->coeff * pow(x, temp->expx) * pow(y, temp->expy) * pow(z, temp->expz));
		temp = temp->link;
	}
	printf("Polynomial evaluated result is %f\n", result);
}



int main()
{
	NODE head, head1, head2, head3;
	int ch;
	head = getnode();
	head1 = getnode();
	head2 = getnode();
	head3 = getnode();
	head->link = head;
	head1->link = head1;
	head2->link = head2;
	head3->link = head3;
	while (1)
	{
		printf("\tMENU\n\t1.Evaluate polynomial\n\t2.Polynomial addition\n\t3.Exit\n");
		printf("\tEnter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\tEnter polynomial to evaluate\n");
			head = read_poly(head);
			display(head);
			evaluate(head);
			break;
		case 2:
			printf("\tEnter the first polynomial\n");
			head1 = read_poly(head1);
			printf("\tEter the second polynomial\n");
			head2 = read_poly(head2);
			
			head3 = add_poly(head1, head2, head3);
			printf("\tThe first polynomial is\n");
			display(head1);
			printf("\The second polynomial is\n");
			display(head2);
			printf("\The sum of 2 polynomials is\n");
			display(head3);
			break;
		case 3:
			exit(0);
		default:
			printf("\t\tInvalid choice\n");
		}
	}
	return 0;
}