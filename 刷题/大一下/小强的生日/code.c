#include<stdio.h>
int main()
{
    int arrYear[93];
    int count = 0;
    while(scanf("%d", &arrYear[count]) != EOF)
        count++;
    for(int i = 0; i < count; i++)
    {
        int year = arrYear[i];
        int day[5][7] = {0};
        int distance_year = year - 2008;
        int leap_num;
        if(distance_year % 4 == 0)
            leap_num = distance_year / 4;
        else
            leap_num = distance_year / 4 + 1;
        int commom_num = distance_year - leap_num;
        int day_num = leap_num * 366 + commom_num * 365;
        int vacant_day = (5 + day_num) % 7;
        int total_day;
        if(year % 4 == 0 && year != 2100)
            total_day = 29;
        else
            total_day = 28;
        for(int i = 1; i <= total_day; i++)
        {
            int line = (vacant_day + i - 1) / 7;
            int row = (vacant_day + i - 1) - line * 7;
            day[line][row] = i;
        }
        printf(" SU MO TU WE TH FR SA\n");
        for(int m = 0; m < 5; m++)
        {
            for(int n = 0; n < 7; n++)
            {
                int num = day[m][n];
                if(num == 0)
                    printf("   ");
                else
                    printf(" %2d", num);
            }
            printf("\n");
        }
        if(day[4][0] != 0)
            printf("\n");
    }
    return 0;
}