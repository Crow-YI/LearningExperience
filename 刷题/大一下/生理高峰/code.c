#include<stdio.h>
int main()
{
    int res[10];
    int T;
    scanf("%d", &T);
    for(int j = 0; j < T; j++)
    {
        int p, e, i, d;
        scanf("%d %d %d %d", &p, &e, &i, &d);
        while(p != e || p != i)
        {
            int *k = &p;
            int addition = 23;
            if(e < *(k))
            {
                k = &e;
                addition = 28;
            }
            if(i < *(k))
            {
                k = &i;
                addition = 33;
            }
            *(k) += addition;
        }
        int day = p - d;
        if(day < 0)
            day += 21252;
        res[j] = day;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("the next triple peak occurs in %d days.\n", res[i]);
    }
    return 0;
}