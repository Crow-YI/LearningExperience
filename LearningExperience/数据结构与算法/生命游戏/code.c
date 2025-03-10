#include<stdio.h>
typedef struct 
{
    int alive;
    int round;
}life;
void initialize(life arr[22][62])
{
    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 62; j++)
        {
            arr[i][j].alive = 0;
            arr[i][j].round = 0;
        }
    }
}
void lifeChange(life arr[22][62])
{
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 60; j++)
        {
            arr[i][j].round = arr[i - 1][j - 1].alive + arr[i - 1][j].alive + arr[i - 1][j + 1].alive
                            + arr[i][j - 1].alive + arr[i][j + 1].alive 
                            + arr[i + 1][j - 1].alive + arr[i + 1][j].alive + arr[i + 1][j + 1].alive;
        }
    }
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 60; j++)
        {
            if(arr[i][j].round <= 1)
                arr[i][j].alive = 0;
            else if(arr[i][j].round >= 4)
                arr[i][j].alive = 0;
            else if(arr[i][j].round == 3)
                arr[i][j].alive = 1;
        }
    }
}
void lifePrint(life arr[22][62])
{
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 60; j++)
        {
            if(arr[i][j].alive == 1)
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }
}
int main()
{
    life arr[22][62];
    initialize(arr);
    int line, row;
    while((scanf("%d %d", &line, &row)) == 2)
    {
        arr[line][row].alive = 1;
        if(line == -1 && row == -1)
            break;
    }
    int turn;
    scanf("%d", &turn);
    for(int i = 0; i < turn; i++)
        lifeChange(arr);
    lifePrint(arr);
    return 0;
}