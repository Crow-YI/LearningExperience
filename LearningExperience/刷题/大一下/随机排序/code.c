#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data
{
	char str[100][21];
	int num;
}data;
char order[27];
int fun(char c)
{
	if(c >= 'a' && c <= 'z')
	{
		c = c - 'a' + 'A';
	}
	int i;
	for(i = 0; i < 26; i++)
	{
		if(c == order[i])
			break;
	}
	return (i + 1);
}
int compare(char* pa, char* pb)
{
	int lena = strlen(pa);
	int lenb = strlen(pb);
	int numa = 0;
	int numb = 0;
	int na, nb;
	while(numa < lena || numb < lenb)
	{
		if(numa >= lena)
			na = 0;
		else
			na = fun(*(pa + numa));
		if(numb >= lenb)
			nb = 0;
		else
			nb = fun(*(pb + numb));
		numa++;
		numb++;
		int n = na - nb;
		if(n != 0)
			return n;
	}
	return 0;
}
int main()
{
	data arr[100];
	int n = 0;
	while((scanf("%s", order)) != EOF)
	{
		int count = 0;
		int c;
		char (*pa)[21] = arr[n].str;
		while(scanf("%s", (pa[count++])))
		{
			if((c = getchar()) == '\n')
				break;
		}
		arr[n++].num = count;
		qsort(pa, count, sizeof(*pa), compare);
	}
	for(int i = 0; i < n; i++)
	{
		int a = arr[i].num;
		char (*pa)[21] = arr[i].str;
		for(int j = 0; j < a; j++)
		{
			printf("%s ", pa[j]);
		}
		printf("\n");
	}
	return 0;
}