#include<stdio.h>
int a[100001] = {0};
int b[100001] = {0};
int c[200000] = {0};
int d[200000] = {0};
int main()
{
    int num = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        num += a[x];
        a[x]++;
        num += b[y];
        b[y]++;
        int n1 = x + y - 2;
        num += c[n1];
        c[n1]++;
        int n2 = x - y - 1 + n;
        num += d[n2];
        d[n2]++;
    }
    printf("%d\n", num);
    return 0;
}