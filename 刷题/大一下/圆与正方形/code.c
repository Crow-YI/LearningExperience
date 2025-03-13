#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
int main()
{
    double s = sqrt(2);
    double res[10];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N, K;
        scanf("%d %d", &N, &K);
        double l = N;
        double square = 0;
        for(int j = 0; j < K; j++)
        {
            square += (l * l) * (1 - PI * 0.25);
            l = l / s;
        }
        res[i] = square;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%.6lf\n", res[i]);
    }
    return 0;
}