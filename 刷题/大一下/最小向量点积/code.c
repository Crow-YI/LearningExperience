#include<stdio.h>
#include<stdlib.h>
int compare(int *n1, int *n2)
{
    return *(n2) - *(n1);
}
int _compare(int *n1, int *n2)
{
    return *(n1) - *(n2);
}
int main()
{
    int res[10];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n;
        int arr1[1000];
        int arr2[1000];
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", (arr1 + i));
        for(int i = 0; i < n; i++)
            scanf("%d", (arr2 + i));
        qsort(arr1, n, 4, compare);
        qsort(arr2, n, 4, _compare);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr1[i] * arr2[i];
        }
        res[i] = sum;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%d\n", res[i]);
    }
    return 0;
}