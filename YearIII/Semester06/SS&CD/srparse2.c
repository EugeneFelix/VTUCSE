#include<stdio.h>
#include<string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char input[25], stack[50];
char reduce[] = "SHIFT->";
char shift[] = "REDUCE TO E";

void check() {
  for (z = 0; z < c; z++)
    if (stack[z] == 'i' && stack[z + 1] == 'd') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      j++;
    }
  for (z = 0; z < c; z++)
    if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 2] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      i = i - 2;
    } for (z = 0; z < c; z++)
    if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      i = i - 2;
    } for (z = 0; z < c; z++)
    if (stack[z] == '(' && stack[z + 1] == 'E' && stack[z + 2] == ')') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      i = i - 2;
    }
}

int main() {
  puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
  puts("Enter Input String");
  scanf("%s", input);
  c = strlen(input);
  puts("stack \t input \t action");
  for (k = 0, i = 0; j < c; k++, i++, j++) {
    if (stack[j] == 'i' && stack[j + 1] == 'd') {
      stack[i] = stack[j];
      stack[i + 1] = stack[j + 1];
      stack[i + 2] = '\0';
      stack[j] = ' ';
      stack[j + 1] = ' ';
      printf("\n$%s\t%s$\t%sid", stack, input, shift);
      check();
    } else {
      stack[i] = stack[j];
      stack[i + 1] = '\0';
      stack[j] = ' ';
      printf("\n$%s\t%s$\t%ssymbols", stack, input, shift);
      check();
    }
  }
  return 0;
}