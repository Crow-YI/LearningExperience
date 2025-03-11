#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double frequence[26];
int compare(char *p1, char *p2)
{
	char c1 = *p1;
	char c2 = *p2;
	if(c1 >= 'A' && c1 <= 'Z')
		c1 = c1 - 'A' + 'a';
	if(c2 >= 'A' && c2 <= 'Z')
		c2 = c2 - 'A' + 'a';
	double d1 = frequence[c1 - 'a'];
	double d2 = frequence[c2 - 'a'];
	double d = d2 - d1;
	if(d > 0)
		return 1;
	else if(d < 0)
		return -1;
	else
	{
		if(c1 == c2)
			return *(p2) - *(p1);
		else
			return c1 - c2;
	}
}
int main()
{
	char line[10][101];
	int numProblem;
	scanf("%d", &numProblem);
	for(int i = 0; i < numProblem; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			scanf("%lf", (frequence + j));
		}
		scanf("%s", line[i]);
		int len = strlen(line[i]);
		qsort(line[i], len, sizeof(char), compare);
	}
	for(int i = 0; i < numProblem; i++)
	{
		printf("case #%d:\n", i);
		printf("%s\n", line[i]);
	}
	return 0;
}