#include<stdio.h>
#include<string.h>
int i = 0, j = 0;
char stack[50];
char reduce[] = "REDUCE TO E";
char shift[] = "SHIFT->";
char input[] = "id+id*id";

void check(int buflen) {
  for (int z = 0; z < buflen; z++)
    if (stack[z] == 'i' && stack[z + 1] == 'd') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      j++;
    }
  for (int z = 0; z < buflen; z++)
    if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 2] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      i = i - 2;
    } for (int z = 0; z < buflen; z++)
    if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E') {
      stack[z] = 'E';
      stack[z + 1] = '\0';
      stack[z + 1] = '\0';
      printf("\n$%s\t%s$\t%s", stack, input, reduce);
      i = i - 2;
    } for (int z = 0; z < buflen; z++)
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
  puts("STACK \t INPUT \t ACTION");
  int buflen = strlen(input);
  for (int k = 0, i = 0; j < buflen; k++, i++, j++) {
    if (input[j] == 'i' && input[j + 1] == 'd') {
      stack[i] = input[j];
      stack[i + 1] = input[j + 1];
      stack[i + 2] = '\0';
      input[j] = ' ';
      input[j + 1] = ' ';
      printf("\n$%s\t%s$\t%sid", stack, input, shift);
      check(buflen);
    } else {
      stack[i] = input[j];
      stack[i + 1] = '\0';
      input[j] = ' ';
      printf("\n$%s\t%s$\t%ssymbols", stack, input, shift);
      check(buflen);
    }
  }
  return 0;
}
