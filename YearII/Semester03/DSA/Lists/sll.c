#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funnySLL.h"
void main()
{
	int choice;
	long long int ph;
	int sem;
	char name[20], usn[15], brnch[5];
	printf("--------MENU \n");
	printf("1.create\n2.Insert from head\n3.Insert from tail\n4.Delete from head\n5.Delete from tail\n6.display\n7.exit\n");
	printf("\n");
	for (;;)
	{
		printf("enter your choice\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("enter the name usn branch sem phno. of the student respectively\n");
			scanf("%s%s%s%d%lld", name, usn, brnch, &sem, &ph);			create(ph, sem, name, usn, brnch);
			break;
		case 2:
			printf("enter the name usn branch sem phno. of the student respectively\n");
			scanf("%s%s%s%d%lld", name, usn, brnch, &sem, &ph);
			insert_head(ph, sem, name, usn, brnch);
			break;
		case 3:
			printf("enter the name usn branch sem phno. of the student respectively\n");
			scanf("%s%s%s%d%lld", name, usn, brnch, &sem, &ph);
			insert_tail(ph, sem, name, usn, brnch);
			break;
		case 4:
			delete_head();
			break;
		case 5:
			delete_tail();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(0);
		default:
			printf("invalid option\n");
		}
	}
}