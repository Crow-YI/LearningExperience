#include<stdio.h>
int gcd(int n, int m)
{
	int k = m % n;
	while(k)
	{
		m = n;
		n = k;
		k = m % n;
	}
	return n;
}
int main()
{
	int res[10][2];
	int numProblem;
	scanf("%d", &numProblem);
	getchar();
	for(int i = 0; i < numProblem; i++)
	{
		int numOne = 0;
		int numZero = 0;
		char c;
		while((c = getchar()) != '\n')
		{
			for(int i = 0; i < 8; i++)
			{
				int k = (c >> i) & 1;
				if(k)
					numOne++;
				else
					numZero++;
			}
		}
		res[i][0] = numOne;
		res[i][1] = numOne + numZero;
	}
	for(int i = 0; i < numProblem; i++)
	{
		int n = res[i][0];
		int m = res[i][1];
		int k = gcd(n, m);
		printf("%d/%d\n", n / k, m / k);
	}
	return 0;
}