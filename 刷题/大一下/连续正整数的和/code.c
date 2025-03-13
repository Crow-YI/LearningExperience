#include<stdio.h>
int main()
{
    int res[10];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int z = 0;
        int num;
        scanf("%d", &num);
        for(int m = 1; m <= (num / 2); m++)
        {
            int sum = 0;
            int n = m;
            while(sum < num)
            {
                sum += n;
                n++;
            }
            if(sum == num)
                z++;
        }
        res[i] = z;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%d\n", res[i]);
    }
    return 0;
}