#include<stdio.h>
#include<math.h>
int find(char* arr, int count, char c)
{
    if(count == 0)
        return 0;
    else
    {
        for(int i = 0; i < count; i++)
        {
            if(c == *(arr + i))
                return i;
        }
        return -1;
    }
}
long long justify(char c, int count, char *arr, int w)
{
    int i;
    for(i = 0; i < count; i++)
    {
        if(*(arr + i) == c)
            break;
    }
    if(i == 0)
    {
        long long n = 1 * (long long)pow(count, w);
        return n;
    }
    else if(i == 1)
    {
        return 0;
    }
    else
    {
        long long n = i * (long long)pow(count, w);
        return n;
    }
}
int main()
{
    int numProblem;
    scanf("%d", &numProblem);
    getchar();
    long long arrNum[10];
    for(int i = 0; i < numProblem; i++)
    {
        char c;
        int count = 0;
        char arrChar[60];
        char str[60];
        int strCount = 0;
        int zeroNum = 1;
        while((c = getchar()) != '\n')
        {
            str[strCount++] = c;
            int index = find(arrChar, count, c);
            if(index == -1)
            {
                arrChar[count++] = c;
            }
            else if(index == 0)
            {
                if(zeroNum)
                {
                    arrChar[count] = c;
                    count++;
                    zeroNum = 0;
                }
            }
        }
        long long sum = 0;
        int w = 0;
        for(int j = strCount - 1; j >= 0; j--)
        {
            sum += justify(str[j], count, arrChar, w++);
        }
        arrNum[i] = sum;
    }
    for(int i = 0; i < numProblem; i++)
    {
        printf("case #%d:\n", i);
        printf("%lld\n", arrNum[i]);
    }
    return 0;
}