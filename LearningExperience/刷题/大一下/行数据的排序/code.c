#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int arrNum[50];
	int count;
}line;

int compare(line* p1, line* p2)
{
	int n = 0;
	while(1)
	{
		if((p1->arrNum[n] == 0) && (p2->arrNum[n] == 0))
			return 0;
		int k = p2->arrNum[n] - p1->arrNum[n];
		if(k != 0)
			return k;
		n++;
	}
}
int main()
{
	line arr[10][1000] = {0};
	int arrData[10] = {0};
	int numProblem;
	scanf("%d", &numProblem);
	for(int i = 0; i < numProblem; i++)
	{
		int numData;
		scanf("%d", &numData);
		int count = 0;
		while(count < numData)
		{
			int num;
			int numCount = 0;
			while(scanf("%d", &num))
			{
				if(num == -1)
				{
					arr[i][count].count = numCount;
					break;
				}
				arr[i][count].arrNum[numCount] = num;
				numCount++;
			}
			count++;
		}
		arrData[i] = numData;
		qsort(arr[i], count, sizeof(line), compare);
	}
	for(int i = 0; i < numProblem; i++)
	{
		for(int j = 0; j < arrData[i]; j++)
		{
			int count = arr[i][j].count;
			for(int k = 0; k < count; k++)
			{
				printf("%d ", arr[i][j].arrNum[k]);
			}
			printf("\n");
		}
	}
	return 0;
}