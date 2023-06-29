#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char productions[3][10] = {
	"A->aBa",
	"B->bB",
	"B->@"
};

char inputString[10], stack[25];
int top = -1, inputIndex = 0;

void pop() {
	--top;
}

void pushProduction(char nonTerminal) {
	int productionIndex = (nonTerminal == 'A') ? 0 : 1;
	pop(); // top--
	for (int i = strlen(productions[productionIndex]) - 1; i >= 3; i--)
		stack[++top] = productions[productionIndex][i];
}

void validateInputString() {
	for (int i = 0; inputString[i] != '\0'; i++) {
		if (inputString[i] != 'a' && inputString[i] != 'b' && inputString[i] != '$') {
			printf("Invalid string");
			exit(0);
		}
	}
	if (inputString[strlen(inputString) - 1] != '$') {
		printf("\n\nInput string entered without end marker $\n");
		exit(0);
	}
}

void checkValidity() {
	if (stack[top] == '$' && inputString[inputIndex] == '$')
		printf("\n$\t$\nValid string Accepted\n");
	else
		printf("\nInvalid string rejected\n");
}

int main() {
	printf("First(A) = {a}\t");
	printf("Follow(A) = {$}\n");
	printf("First(B) = {b,@}\t");
	printf("Follow(B) = {a}\n\n");
	printf("\t a \t b \t $ \n");
	printf("A\t%s\n", productions[0]);
	printf("B\t%s\t%s\n", productions[2], productions[1]);
	strcpy(inputString, "abba$");
	validateInputString();

	stack[++top] = '$';
	stack[++top] = 'A';

	printf("\n\nstack\tInput\taction\n\n----------\n");

	while (inputIndex != strlen(inputString) && stack[top] != '$') {
		printf("\n");
		for (int j = top; j >= 0; j--)
			printf("%c", stack[j]);
		printf("\t");
		for (int j = inputIndex; j < strlen(inputString); j++)
			printf("%c", inputString[j]);
		printf("\t");

		if (stack[top] == 'A') {
			printf("A->aBa");
			pushProduction('A');
		} else if (stack[top] == 'B') {
			if (inputString[inputIndex] == 'b') {
				printf("B->bB");
				pushProduction('B');
			} else {
				printf("B->@\tMatched @");
				pop();
			}
		} else {
			if (stack[top] == inputString[inputIndex]) {
				printf("POP %c\tMatched %c", inputString[inputIndex], inputString[inputIndex]);
				pop();
				inputIndex++;
			} else
				break;
		}
	}

	checkValidity();
	return 0;
}
