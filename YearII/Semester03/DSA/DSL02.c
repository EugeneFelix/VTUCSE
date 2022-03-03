#include <stdio.h> #include<stdlib.h>
char str[100], pat[100], rep[100], ans[100];
int i, j, c, m, k, flag = 0;
void stringmatch()
{
	i = m = j = k = c = 0;
	while (str[c] != '\0')
	{
		if (str[m] == pat[i])
		{
			i++;
			m++;
			if (pat[i] == '\0')
			{
				flag = 1;
				for (k = 0; rep[k] != '\0'; k++)
				{
					ans[j] = rep[k];
					j++;
				}
				i = 0;
				c = m;
			}
		}
		else
		{
			ans[j] = str[c];
			j++;
			c++;
			m = c;
			i = 0;
		}
	}
	ans[j] = '\0';
}
int main()
{
	printf("enter a main string\n");
	gets(str);
	printf("enter the pattern;\n");
	gets(pat);
	printf("enter a replace string\n");
	gets(rep);
	stringmatch();
	if (flag == 1)
	{
		printf("the resultant string is %s\n", ans);
	}
	else
	{
		printf("pattern string not found!!\n");
	}
	return 0;
}