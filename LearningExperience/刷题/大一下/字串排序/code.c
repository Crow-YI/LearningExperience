#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data
{
    char str[31];
    char num[9];
}data;
int compare(data* p1, data* p2)
{
    int num1, num2;
    if(*(p1->num) == '\0')
        num1 = -1;
    else
        num1 = atoi(p1->num);
    if(*(p2->num) == '\0')
        num2 = -1;
    else
        num2 = atoi(p2->num);
    int numCompare = num1 - num2;
    if(numCompare != 0)
        return numCompare;
    return strcmp(p1->str, p2->str);
}
int main()
{
    data arr[100];
    int arrCount = 0;
    int strCount = 0;
    int numCount = 0;
    data* p = arr;
    int c;
    int isContinue = 1;
    while(isContinue)
    {
        c = getchar();
        if(c == ' ')
        {
            p->num[numCount] = '\0';
            p->str[strCount] = '\0';
            numCount = 0;
            strCount = 0;
            p += 1;
            arrCount++;
        }
        else if(c >= '0' && c <= '9')
        {
            p->num[numCount++] = c;
            p->str[strCount++] = c;
        }
        else if(c == '\n' || c == EOF)
        {
            p->num[numCount] = '\0';
            p->str[strCount] = '\0';
            arrCount++;
            isContinue = 0;
        }
        else
        {
            p->str[strCount++] = c;
        }
    }
    int size = sizeof(data);
    qsort(arr, arrCount, size, compare);
    for(int i = 0; i < arrCount; i++)
    {
        printf("%s ", arr[i].str);
    }
    printf("\n");
    return 0;
}