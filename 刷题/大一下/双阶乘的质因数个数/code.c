#include<stdio.h>
int main()
{
    int res[10];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        int num = 0;
        while(N > 0)
        {
            int temp = N;
            while(temp % M == 0)
            {
                temp /= M;
                num++;
            }
            N -= 2;
        }
        res[i] = num;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%d\n", res[i]);
    }
    return 0;
}