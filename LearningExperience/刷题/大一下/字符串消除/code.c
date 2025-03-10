#include<stdio.h>
#include<string.h>
void my_copy(char* source, char* destination, int num)
{
    for(int i = 0; i < num; i++)
    {
        *(destination + i) = *(source + i);
    }
}
int delete(char *str)
{
    int isContinue = 1;
    int num = 0;
    int len = strlen(str) + 1;
    while(isContinue)
    {
        int boolDelete[101] = {0};
        int count = 1;
        int isDelete = 0;
        int IsDelete = 0;
        int deleteNum = 1;
        int deletePosition;
        char c = str[0];
        while(count < len)
        {
            char temp = str[count];
            if(temp == c)
            {
                if(!isDelete)
                    deletePosition = count - 1;
                isDelete = 1;
                deleteNum++;
                IsDelete = 1;
            }
            else if(temp != c && isDelete)
            {
                for(int i = 0; i < deleteNum; i++)
                {
                    boolDelete[deletePosition + i] = 1;
                }
                isDelete = 0;
                deleteNum = 1;
            }
            c = temp;
            count++;
        }
        if(IsDelete)
        {
            int deleteCount = 0;
            int count = 0;
            char tempStr[101];
            strcpy(tempStr, str);
            for(int i = 0; i < len; i++)
            {
                if(boolDelete[i] == 0)
                {
                    str[count++] = tempStr[i];
                }
                else
                    deleteCount++;
            }
            len -= deleteCount;
            num += deleteCount;
        }
        else
            isContinue = 0;
    }
    return num;
}
int main()
{
    int res[10];
    int T;
    scanf("%d", &T);
    // for(int i = 0; i < T; i++)
    // {
    //     int deleteNum = 0;
    //     char str[101];
    //     scanf("%s", str);
    //     deleteNum += delete(str);
    //     int len = strlen(str);
    //     int tempNum = 0;
    //     if(len == 0)
    //         tempNum = 1;
    //     else
    //     {
    //         for(int i = 0; i < len; i++)
    //         {
    //             char tempStr[101];
    //             strcpy(tempStr, str);
    //             my_copy(tempStr + i + 1, tempStr + i, len - i);
    //             int num = delete(tempStr) + 2;
    //             if(num > tempNum)
    //                 tempNum = num;
    //         }
    //     }
    //     res[i] = deleteNum + tempNum;
    // }
    for(int i = 0; i < T; i++)
    {
        char str[101];
        int num = 0;
        scanf("%s", str);
        int len = strlen(str);
        for(int j = 0; j < len + 1; j++)
        {
            for(int c = 'A'; c < 'D'; c++)
            {
                char temp[102];
                temp[j] = c;
                my_copy(str, temp, j);
                my_copy(str + j, temp + j + 1, len - j + 1);
                int tempNum = delete(temp);
                if(tempNum > num)
                    num = tempNum;
            }
        }
        res[i] = num;
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%d\n", res[i]);
    }
    return 0; 
} 