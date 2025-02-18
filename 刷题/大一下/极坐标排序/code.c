#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int compare(double* p1, double* p2)
{
	double k = *(p1 + 1) - *(p2 + 1);
	if(k > 0)
		return 1;
	else if(k < 0)
		return -1;
	else
	{
		k = *(p1) - *(p2);
		if(k > 0)
			return -1;
		else if(k < 0)
			return 1;
		else
			return 0;
	}

}
int main()
{
	double arr[10][1000][2];
	int pro;
	int count[10];
	scanf("%d", &pro);
	for(int i = 0; i < pro; i++)
	{
		scanf("%d", &count[i]);
		for(int j = 0; j < count[i]; j++)
		{
			double a, b;
			scanf("%lf %lf", &a, &b);
			double n, m = 0;
			if(b < 0)
			{
				b = -b;
				m += 3.141592;
			}
			n = sqrt(a * a + b * b);
			m += atan2(b, a);
			arr[i][j][0] = n;
			arr[i][j][1] = m;
		}
		qsort(arr[i], count[i], sizeof(arr[0][0]),compare);
	}
	for(int i = 0; i < pro; i++)
	{
		printf("case #%d:\n", i);
		for(int j = 0; j < count[i]; j++)
		{
			printf("(%.4lf,%.4lf)\n", arr[i][j][0], arr[i][j][1]);
		}
	}
	return 0;
}