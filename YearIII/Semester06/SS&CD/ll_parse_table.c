#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char
    prod[3][10] = {"A->aBa","B->bB","B->@"}, input[10], stack[25];
int
    top = -1; int k, l;

void push(char item) {
	stack[++top]=item;
}

void pop() {
	--top;
}

void display() {
	for(int i = top; i >= 0; i--)
		printf("%c", stack[i]);
}

void stackpush(char p) {
	if(p=='A') {
		pop();
		for(int i = strlen(prod[0])-1; i >= 3; i--)
			push(prod[0][i]);
	} else {
		pop();
		for(int i = strlen(prod[1])-1; i >= 3; i--)
			push(prod[1][i]);
	}
}
void incorrect_input() {
	int i;
	for(i=0;input[i]!='\0';i++) {
		if((input[i]!='a')&&(input[i]!='b')&&(input[i]!='$')) {
			printf("Invalid string");
			exit(0);
		}
	}
	if(input[i - 1] != '$') {
		printf("\n\nInput string entered without end marker $");
		exit(0);
	}
}


void check_valid(int i) {
	if(stack[top]=='$' && input[i]=='$') {
		printf("\n$\t$");
		printf("\nValid string Accepted\n");
	}
	else
		printf("\nInvalid string rejected\n"); 
}
int main() {
	printf("first(A)={a}\t");
	printf("follow(A)={$}\n");
	printf("first(B)={b,@}\t");
	printf("follow(B)={a}\n\n");
	printf("\t a \t b \t $ \n");
	printf("A\t%s\n",prod[0]);
	printf("B\t%s\t%s\n",prod[2],prod[1]);
	printf("Enter the input string terminated with $ to parse:-");
	scanf("%s",input);
	incorrect_input();
	push('$');
	push('A');
	int i = 0;
	printf("\n\n");
	printf("stack\tInput\taction");
	printf("\n---------\n");
	while(i!=strlen(input)&&stack[top]!='$') {
		printf("\n");
		for(l=top;l>=0;l--)
			printf("%c",stack[l]);
		printf("\t");
		for(l=i;l<strlen(input);l++)
			printf("%c",input[l]);
		printf("\t");
		if(stack[top]=='A') {
			printf("A->aBa");
			stackpush('A');
		} else if(stack[top]=='B') {
			if(input[i]!='b') {
				printf("B->@");
				printf("\t matched @");
				pop();
			} else {
				printf("B->bB");
				stackpush('B');
			}
		}
		else {
			if(stack[top]==input[i]) {
				printf("pop%c",input[i]);
				printf("\tmatched %c",input[i]);
				pop();
				i++;
			}
			else
				break;
		}
	}
	check_valid(i);
    return 0;
}