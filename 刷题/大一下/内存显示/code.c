#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
	double KL;
	int num;
}data;
int compare(data* p1, data* p2)
{
	double kl = p1->KL - p2->KL;
	if(kl > 0)
		return 1;
	else if(kl < 0)
		return -1;
	else
		return (p1->num - p2->num);
}
int main()
{
	int arrInt[10][201][10];
	double arrDistribution[10][201][10];
	data arrKL[10][200];
	int arrNumY[10];
	int numProble;
	scanf("%d", &numProble);
	for(int i = 0; i < numProble; i++)
	{
		double numVar;
		int numY;
		scanf("%lf %d", &numVar, &numY);
		arrNumY[i] = numY;
		for(int j = 0; j < (numY + 1); j++)
		{
			int sum = 0;
			for(int z = 0; z < numVar; z++)
			{
				scanf("%d", &arrInt[i][j][z]);
				sum += arrInt[i][j][z];
			}
			for(int z = 0; z < numVar; z++)
			{
				double d = (arrInt[i][j][z] + (1 / numVar)) / (sum + 1);
				arrDistribution[i][j][z] = d;
			}
		}
		for(int j = 0; j < numY; j++)
		{
			double kl = 0;
			for(int z = 0; z < numVar; z++)
			{
				double ln = log(arrDistribution[i][0][z] / arrDistribution[i][j + 1][z]);
				double feb = arrDistribution[i][0][z] * ln;
				kl += feb;
			}
			if(kl < 1e-7)
				kl = 0;
			arrKL[i][j].KL = kl;
			arrKL[i][j].num = j + 1;
		}
		int size = sizeof(data);
		qsort(arrKL[i], numY, size, compare);
	}
	for(int i = 0; i < numProble; i++)
	{
		printf("case #%d:\n", i);
		int numY = arrNumY[i];
		for(int j = 0; j < numY; j++)
		{
			printf("%d %.4lf\n", arrKL[i][j].num, arrKL[i][j].KL);
		}
	}
	return 0;
}