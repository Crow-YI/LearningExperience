#include<stdio.h>
#include<string.h>
void reverse(char *str)
{
    int len =  strlen(str);
    int i = 0;
    int j = len - 1;
    while(i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
void d2b_step(char *str, int *remain)
{
    int len = strlen(str);
    char num[101];
    strcpy(num, str);
    int carry = 0;
    int bias = 0;
    for(int i = 0; i < len; i++)
    {
        int n = 10 * carry + num[i] - '0';
        char m = n / 2 + '0';
        carry = n % 2;
        if(i == 0 && m == '0')
            bias = 1;
        else
            str[i - bias] = m;
    }
    *remain = carry;
    str[len - bias] = '\0';
}
void d2b(char *d, char *b)
{
    if((strcmp(d, "0")) == 0)
    {
        strcpy(b, "0");
        return;
    }

    char current[101];
    strcpy(current, d);
    int remain;
    int count = 0;
    while(current[0] != 0)
    {
        d2b_step(current, &remain);
        b[count++] = remain + '0';
    }
    b[count] = '\0';
}
void b2d_step(char *str, int num, int *len)
{
    int l = *len;
    int carry = num;
    for(int i = 0; i < l; i++)
    {
        str[i] = str[i] * 2 + carry;
        carry = 0;
        if(str[i] > 9)
        {
            str[i] -= 10;
            carry = 1;
        }
    }
    if(carry)
    {
        str[l] = 1;
        *len += 1;
    }
}
void b2d(char *b, char *d)
{
    int lenD = strlen(b);
    int lenB = 1;
    for(int i = 0; i < lenD; i++)
    {
        int num = b[i] - '0';
        b2d_step(d, num, &lenB);
    }
    for(int i = 0; i < lenB; i++)
    {
        d[i] += '0';
    }
}
int main()
{
    char res[10][101] = {0};
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        char binary[335] = {0};
        char decimal[101];
        scanf("%s", decimal);
        d2b(decimal, binary);
        b2d(binary, res[i]);
        reverse(res[i]);
    }
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%s\n", res[i]);
    }
    return 0;
}