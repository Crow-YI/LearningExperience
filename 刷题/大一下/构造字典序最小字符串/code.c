#include<stdio.h>
int determineSide(char *str, int left, int right)
{
    char l = str[left];
    char r = str[right];
    if(left == right)
        return 1;
    else if(l == r)
        return determineSide(str, left + 1, right - 1);
    else if(l < r)
        return 1;
    else 
        return -1;
}
int main()
{
    char res[10][501];
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        char *p = res[i];
        char S[501];
        int N;
        scanf("%d", &N);
        scanf("%s", S);
        int left = 0;
        int right = N - 1;
        int count = 0;
        while(left <= right)
        {
            if(S[left] < S[right])
            {
                p[count++] = S[left++];
            }
            else if(S[left] > S[right])
            {
                p[count++] = S[right--];
            }
            else
            {
                if(left == right)
                {
                    p[count++] = S[left];
                    p[count] = '\0';
                    break;
                }
                int smallSide = determineSide(S, left + 1, right - 1);
                if(smallSide == 1)
                    p[count++] = S[left++];
                else
                    p[count++] = S[right--];
            }
        }
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%s\n", res[i]);
    }
    return 0;
}