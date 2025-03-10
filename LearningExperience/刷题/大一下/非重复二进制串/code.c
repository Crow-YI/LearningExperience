#include<stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    int res[10];
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        int maxCount = 0;
        int l = -1;
        int count = 0;
        while(n > 0)
        {
            int k = n & 1;
            if(k == l)
            {
                if(count > maxCount)
                {
                    maxCount = count;
                }
                count = 1;
            }
            else
            {
                count++;
                l = k;
            }
            n >>= 1;
        }
        if(count > maxCount)
        {
            maxCount = count;
        }
        res[i] = maxCount;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n%d\n", i, res[i]);
    }
    return 0;
}