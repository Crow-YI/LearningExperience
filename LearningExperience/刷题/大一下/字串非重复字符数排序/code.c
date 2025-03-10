#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(char *p1, char *p2)
{
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	int arr1[26] = {0};
	int arr2[26] = {0};
	for(int i = 0; i < len1; i++)
	{
		int n = *(p1 + i) - 'A';
		arr1[n]++;
	}
	int num1 = 0;
	for(int i = 0; i < 26; i++)
	{
		if(arr1[i] != 0)
			num1++;
	}
	for(int i = 0; i < len2; i++)
	{
		int n = *(p2 + i) - 'A';
		arr2[n]++;
	}
	int num2 = 0;
	for(int i = 0; i < 26; i++)
	{
		if(arr2[i] != 0)
			num2++;
	}
	int k = num2 - num1;
	if(k != 0)
		return k;
	for(int i = 0; i < len1 || i < len2; i++)
	{
		int m = *(p1 + i) - *(p2 + i);
		if(m != 0)
			return m;
	}
	return 0;
}
int main()
{
	char arr[10][100][21];
	int arrCount[10];
	int numProblem;
	scanf("%d", &numProblem);
	for(int i = 0; i < numProblem; i++)
	{
		int count;
		scanf("%d", &count);
		arrCount[i] = count;
		for(int j = 0; j < count; j++)
		{
			scanf("%s", arr[i][j]);
		}
		int size = sizeof(arr[0][0]);
		qsort(arr[i], count, size, compare);
	}
	for(int i = 0; i < numProblem; i++)
	{
		printf("case #%d:\n", i);
		int count = arrCount[i];
		for(int j = 0; j < count; j++)
		{
			printf("%s\n", arr[i][j]);
		}
	}
	return 0;
}