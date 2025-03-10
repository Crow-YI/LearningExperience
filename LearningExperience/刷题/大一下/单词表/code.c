#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void my_strcpy(char* dest, char* sour)
{
    int len = strlen(sour) + 1;
    for(int i = 0; i < len; i++)
    {
        dest[i] = sour[i];
    }
}
char dictionary[10][500][500];
int main()
{
    int arrNum[10];
    int T;
    scanf("%d", &T);
    getchar();
    for(int i = 0; i < T; i++)
    {
        int num = 0;
        char word[500];
        int wordCount = 0;
        int isSpace = 0;
        char c;
        while(c = getchar())
        {
            if(c >= 'a' && c <= 'z')
            {
                word[wordCount++] = c;
                isSpace = 0;
            }
            else
            {
                if(isSpace)
                {
                    if(c == '\n')
                        break;
                }
                else
                {
                    isSpace = 1;
                    word[wordCount] = '\0';
                    if(num == 0)
                        strcpy(dictionary[i][num++], word);
                    else
                    {
                        int isSame = 0;
                        for(int j = 0; j < num; j++)
                        {
                            if(strcmp(dictionary[i][j], word) == 0)
                            {
                                isSame = 1;
                                break;
                            }
                        }
                        if(!isSame)
                            my_strcpy(dictionary[i][num++], word);
                    }
                    wordCount = 0;
                    if(c == '\n')
                        break;
                }
            }
        }
        int size = sizeof(dictionary[0][0]);
        qsort(dictionary[i], num, size, strcmp);
        arrNum[i] = num;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        int num = arrNum[i];
        for(int j = 0; j < num; j++)
        {
            if(j == 0)
                printf("%s", dictionary[i][0]);
            else
                printf(" %s", dictionary[i][j]);
        }
        printf("\n");
    }
    return 0;
}