#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	long long arrNum[10000];
	int count;
}data;
int compare(long long* p1, long long* p2)
{
	unsigned long long n1 = (unsigned long long)*(p1);
	unsigned long long n2 = (unsigned long long)*(p2);
	int k1 = 0;
	int k2 = 0;
	while(n1 != 0)
	{
		if(n1 & 1 == 1)
			k1++;
		n1 >>= 1;
	}
	while(n2 != 0)
	{
		if(n2 & 1 == 1)
			k2++;
		n2 >>= 1;
	}
	int k = k2 - k1;
	if(k != 0)
		return k;
	return *(p1) - *(p2);
}
int main()
{
	data arr[10];
	int numProblem;
	scanf("%d", &numProblem);
	for(int i = 0; i < numProblem; i++)
	{
		int count;
		scanf("%d", &count);
		arr[i].count = count;
		for(int j = 0; j < count; j++)
		{
			scanf("%lld", &arr[i].arrNum[j]);
		}
		int size = sizeof(long long);
		qsort(arr[i].arrNum, count, size, compare);
	}
	for(int i = 0; i < numProblem; i++)
	{
		printf("case #%d:\n", i);
		int count = arr[i].count;
		for(int j = 0; j < count; j++)
		{
			printf("%lld ", arr[i].arrNum[j]);
		}
		printf("\n");
	}
	return 0;
}