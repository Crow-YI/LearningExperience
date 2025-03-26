#include<stdio.h>
int fun(int m, int n)
{
    if(m < n)
        return 0;
    else if(m == n)
        return 1;
    else 
        return 2 * fun(m - 1, n) + (1 << (m - n - 1)) - fun(m - n - 1, n);
}
int main()
{
    int res[200];
    int count = 0;
    int m, n;
    while(scanf("%d %d", &n, &m))
    {
        if(m == -1 && n == -1)
            break;
        if(m == 1)
            res[count++] = (1 << n) - 1;
        else
            res[count++] = fun(n, m);
    }
    for(int i = 0; i < count; i++)
        printf("%d\n", res[i]);
    return 0;
}