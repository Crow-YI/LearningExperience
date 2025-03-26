#include<stdio.h>
int fun(long long *np)
{
    long long n = *np;
    int num = 10;
    int isTrue = 1;
    int count = 0;
    while(n > 0)
    {
        int temp = n % 10;
        if(temp > num)
        {
            isTrue = 0;
            break;
        }
        num = temp;
        n /= 10;
        count++;
    }
    if(isTrue)
        return 1;
    else
    {
        long long k = n - 1;
        for(int i = 0; i < count; i++)
        {
            k = k * 10 + 9;
        }
        *np = k;
        return 0;
    }
}
int main()
{
    long long res[100];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        long long num;
        scanf("%lld", &num);
        int isContinue = 1;
        while(isContinue)
        {
            isContinue = !fun(&num);
        }
        res[i] = num;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%lld\n", res[i]);
    }
    return 0;
}