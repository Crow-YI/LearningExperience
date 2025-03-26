#include<stdio.h>
#include<math.h>
int add(int n)
{
    if(n < 3)
        return 0;
    else if(n == 3)
        return 1;
    else if(n == 4)
        return 4;
    else 
        return add(n - 1) * 2 + pow(2, n - 3) - add(n - 2) + add(n - 3);
}
int main()
{
    int res[100];
    int count = 0;
    int num;
    while(scanf("%d", &num))
    {
        if(num == -1)
            break;
        res[count++] = pow(2, num) - add(num);
    }
    for(int i = 0; i < count; i++)
        printf("%d\n", res[i]);
    return 0;
}