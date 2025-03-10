#include<stdio.h>
int main()
{
    char arr[10][1001];
    int T;
    scanf("%d", &T);
    getchar();
    for(int i = 0; i < T; i++)
    {
        char* p = arr[i];
        int count = 0;
        char c;
        while((c = getchar()) != '\n')
        {
            if(c >= 'A' && c <= 'Z')
            {
                c = (c - 'A' + 13) % 26 + 'A';
            }
            else if(c >= 'a' && c <= 'z')
            {
                c = (c - 'a' + 13) % 26 + 'a';
            }
            *(p + count) = c;
            count++;
        }
        *(p + count) = '\0';
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n%s\n", i, arr[i]);
    }
    return 0;
}