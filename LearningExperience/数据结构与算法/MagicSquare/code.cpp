#include<stdio.h>
class Square
{
private:
    int square[102][102];
    int x;
    int y;
    int row;
    int n;

public:
    Square(int num)
    {
        x = (num + 1) / 2;
        y = 1;
        row = num;
        Initialize(num);
        n = 1;
        square[y][x] = (n++);
    }
    void Update()
    {
        x++;
        y--;
        CheckXY();
        while(CheckSquare()){; }
        square[y][x] = (n++);
    }
    void PrintSquare()
    {
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= row; j++)
            {
                if(j == row)
                    printf("%d\n", square[i][j]);
                else
                    printf("%d  ", square[i][j]);
            }
        }
    }

private:
    void Initialize(int num)
    {
        for(int i = 1; i <= num; i++)
        {
            for(int j = 1; j <= num; j++)
                square[i][j] = 0;
        }
    }
    void CheckXY()
    {
        if(x > row)
            x -= row;
        else if(x < 1)
            x += row;
        if(y < 1)
            y += row;
        else if(y > row)
            y -= row;
    }
    int CheckSquare()
    {
        if(square[y][x] != 0)
        {
            x--;
            y += 2;
            CheckXY();
            return 1;
        }
        return 0;
    }
};
int main()
{
    int row;
    scanf("%d", &row);
    Square s(row);
    int count = row * row - 1;
    for(int i = 0; i < count; i++)
    {
        s.Update();
    }
    s.PrintSquare();
    return 0;
}