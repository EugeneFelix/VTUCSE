#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char input[25], stack[55];
char shift[] = "SHIFT->";
char reduce[] = "REDUCE";
void check2() {
	for(z=0; z < strlen(input); z++) 
		if(stack[z]=='i' && stack[z+1]=='d') {
			stack[z]='E';
			stack[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stack, input, reduce);
			j++;
		}
	for(z=0; z < strlen(input); z++)
		if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='E') {
			stack[z]='E';
			stack[z+1]='\0';
			stack[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stack, input, reduce);
			i -= 2;
		} 
		for(z=0; z < strlen(input); z++)
			if(stack[z]=='E' && stack[z+1]=='*' && stack[z+2]=='E') {
				stack[z]='E'; stack[z+1]='\0';
				stack[z+1]='\0';
				printf("\n$%s\t%s$\t%s",stack, input, reduce);
				i -= 2;
			}
	for(z=0; z < strlen(input); z++)
		if(stack[z]=='(' && stack[z+1]=='E' && stack[z+2]==')') {
			stack[z]='E';
			stack[z+1]='\0'; 
			stack[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stack, input, reduce);
			i -= 2;
		}
}
void check()
{
	for(z=0;z<strlen(input);z++)
		if(stack[z]=='(' && stack[z+1]=='E'&& stack[z+2]==')') {
			stack[z]='F';
			stack[z+1]='\0';
			stack[z+2]='\0';
			printf("\n$%s\t%s$\t%s by F->(E)",stack,input, reduce);
			i=i-2;
		}
	for(z=0;z < strlen(input);z++)
		if(stack[z]=='i' && stack[z+1]=='d') {
			stack[z]='F';
			stack[z+1]='\0';
			printf("\n$%s\t%s$\t%s by F->id",stack,input, reduce);
			j++;
		}
	for(z=0;z < strlen(input);z++) {
		if(stack[z]=='T' && stack[z+1]=='*' && stack[z+2]=='F') {
			stack[z]='T';
			stack[z+1]='\0';
			stack[z+2]='\0';
			printf("\n$%s\t%s$\t%s by T->T*F",stack,input, reduce);
			i=i-2;
		}
		else if(stack[z] == 'F') {
			stack[z] = 'T';
			printf("\n$%s\t%s$\t%s by T->F",stack,input, reduce);
		}
	}
	for(z = 0; z < strlen(input); z++) {
		if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='T' && stack[z+3]=='*')
			break;
		if(stack[z]=='E' && stack[z+1]=='+' && stack[z+2]=='T')
			if(input[j+1]=='*')
				break;
			else {
				stack[z]='E';
				stack[z+1]='\0';
				stack[z+2]='\0';
				printf("\n$%s\t%s$\t%s by E->E+T",stack,input, reduce);
				i=i-2;
			}
			else if(stack[z]=='T') {
                if(stack[z+1]=='*'|| input[j+1]=='*')
                        break;
				stack[z]='E';
				printf("\n$%s\t%s$\t%s by E->T",stack,input, reduce);
			}
		}
}

int main() {
	printf("Grammar: \n E->E+T|T \n T->T*F|F \n F->(E)|id\n");
	printf("Enter the input string\n");
	scanf("%s",input);
	printf("Stack \t Input \t\t action\n");
	printf("$\t %s$", input);
	for(int i = 0, j = 0, k = 0; j < strlen(input); i++, j++, k++) {
		if(input[j]=='i' && input[j+1]=='d') {
			stack[i]=input[j];
			stack[i+1]=input[j+1];
			stack[i+2]='\0';
			input[j]=' ';
			input[j+1]=' ';
			printf("\n$%s\t%s$\t%s id", stack, input, shift);
			check2();
		} else {
			stack[i]=input[j];
			stack[i+1]='\0';
			input[j]=' ';
			printf("\n$%s\t%s$\t%s symbol",stack,input, shift);
			check2();
		}
	}
	return 0;
}