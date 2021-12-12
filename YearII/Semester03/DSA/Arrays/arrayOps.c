#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "funnyArrayOps.h"
#define MAXSIZE 100

void main(void)
<%
	int choice;
	bool trues = 1;
	while (trues)
	<%
		printf("\t\tMenu\n\t1.CREATE\n\t2.DISPLAY\n\t3.INSERT\n\t4.DELETE\n\t5.EXIT\n\n\tENTER YOUR CHOICE:\t\n");
		scanf("%d", &choice);
		switch (choice)
		<%
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert();
			break;
		case 4:
			delete ();
			break;
		case 5:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("\nInvalid choice:\n");
			break;
		%>
	%>
%>