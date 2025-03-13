#include<stdio.h>
#include<stdlib.h>
enum ElementType
{
    None, Int, Float, Char
};
struct Element
{
    ElementType type;
    int integer;
    double floating;
    char character;
};

typedef char StackType;
const int maxStackNum = 100;
enum errorCode
{
    success, overflow, empty
};
class MyStack
{
private:
    StackType stack[maxStackNum];
    int point;

public:
    MyStack()
    {
        point = 0;
    }
    errorCode Push(StackType n)
    {
        if(point >= maxStackNum)
            return overflow;
        stack[point++] = n;
        return success;
    }
    errorCode Pop(StackType &n)
    {
        if(point == 0)
            return empty;
        n = stack[--point];
        return success;
    }
    errorCode ShowTop(StackType &n)
    {
        if(point == 0)
            return empty;
        n = stack[point - 1];
        return success;
    }
    int Size()
    {
        return point;
    }
    bool IsEmpty()
    {
        if(point == 0)
            return true;
        else
            return false;
    }
    bool IsFull()
    {
        if(point == maxStackNum)
            return true;
        else
            return false;
    }
};

class Num
{
private:
    char num[100];
    int count;

public:
    Num()
    {
        count = 0;
    }
    void Add(char c)
    {
        num[count++] = c;
    }
    void End()
    {
        num[count] = '\0';
    }
    int OutputInt()
    {
        return atoi(num);
    }
    double OutputFloat()
    {
        return atof(num);
    }
    void Clear()
    {
        for(int i = 0; i < count; i++)
        {
            num[i] = '\0';
        }
        count = 0;
    }
};

// MyStack s;
// char get()
// {
//     if(s.IsEmpty())
//         return getchar();
//     else
//     {
//         char c;
//         s.Pop(c);
//         return c;
//     }
// }
void Calculate(Element *arr, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i].type == Char)
        {
            char c = arr[i].character;
            if(c == '*' || c == '/')
            {
                int isFloat1 = 0;
                int isFloat2 = 0;
                int head = i - 1;
                int behind = i + 1;
                while(arr[head].type == None)
                    head--;
                if(arr[head].type == Float)
                {
                    isFloat1 = 1;
                }
                while(arr[behind].type == None)
                    behind++;
                if(arr[behind].type == Float)
                {
                    isFloat2 = 1;
                }
                if(c == '*')
                {
                    if(isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating * arr[behind].floating;
                    }
                    else if(isFloat1 && !isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating * arr[behind].integer;
                    }
                    else if (!isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].integer * arr[behind].floating;
                    }
                    else
                    {
                        arr[head].type = Int;
                        arr[head].integer = arr[head].integer * arr[behind].integer;
                    }
                }
                else
                {
                    if(isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating / arr[behind].floating;
                    }
                    else if(isFloat1 && !isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating / arr[behind].integer;
                    }
                    else if (!isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].integer / arr[behind].floating;
                    }
                    else
                    {
                        arr[head].type = Int;
                        arr[head].integer = arr[head].integer / arr[behind].integer;
                    }
                }
                arr[i].type = None;
                arr[behind].type = None;
            }
        }
    }
    for(int i = start; i <= end; i++)
    {
        if(arr[i].type == Char)
        {
            char c = arr[i].character;
            if(c == '+' || c == '-')
            {
                int isFloat1 = 0;
                int isFloat2 = 0;
                int head = i - 1;
                int behind = i + 1;
                while(arr[head].type == None)
                    head--;
                if(arr[head].type == Float)
                {
                    isFloat1 = 1;
                }
                while(arr[behind].type == None)
                    head++;
                if(arr[behind].type == Float)
                {
                    isFloat2 = 1;
                }
                if(c == '+')
                {
                    if(isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating + arr[behind].floating;
                    }
                    else if(isFloat1 && !isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating + arr[behind].integer;
                    }
                    else if (!isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].integer + arr[behind].floating;
                    }
                    else
                    {
                        arr[head].type = Int;
                        arr[head].integer = arr[head].integer + arr[behind].integer;
                    }
                }
                else
                {
                    if(isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating - arr[behind].floating;
                    }
                    else if(isFloat1 && !isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].floating - arr[behind].integer;
                    }
                    else if (!isFloat1 && isFloat2)
                    {
                        arr[head].type = Float;
                        arr[head].floating = arr[head].integer - arr[behind].floating;
                    }
                    else
                    {
                        arr[head].type = Int;
                        arr[head].integer = arr[head].integer - arr[behind].integer;
                    }
                }
                arr[i].type = None;
                arr[behind].type = None;
            }
        }
    }
}

int main()
{
    Element arr[100];
    int count = 0;
    Num numStr;
    bool resFloat = false;
    int c;
    bool isNum = false;
    while((c = getchar()) != '\n' && c != EOF)
    {
        if((c > 47 && c < 58) || c == '.')
        {
            if(c == '.')
                resFloat = true;
            numStr.Add(c);
            isNum = true;
        }
        else
        {
            if(isNum)
            {
                if(resFloat)
                {
                    arr[count].type = Float;
                    arr[count].floating = numStr.OutputFloat();
                    numStr.Clear();
                    count++;
                    resFloat = false;
                }
                else
                {
                    arr[count].type = Int;
                    arr[count].integer = numStr.OutputInt();
                    numStr.Clear();
                    count++;
                }
            }
            arr[count].type = Char;
            arr[count].character = c;
            count++;
            isNum = false;
        }
    }
    if(isNum)
    {
        if(resFloat)
        {
            arr[count].type = Float;
            arr[count].floating = numStr.OutputFloat();
            numStr.Clear();
            count++;
            resFloat = false;
        }
        else
        {
            arr[count].type = Int;
            arr[count].integer = numStr.OutputInt();
            numStr.Clear();
            count++;
        }
    }

    bool isContinue = true;
    while(isContinue)
    {
        int start = 0;
        int end = 0;
        for(int i = 0; i < count; i++)
        {
            if(arr[i].type == Char && arr[i].character == '(')
                start = i;
            else if(arr[i].type == Char && arr[i].character == ')')
            {
                end = i;
                break;
            }
        }
        if(start == end)
            isContinue = false;
        else
        {
            arr[start].type = None;
            arr[end].type = None;
            Calculate(arr, start + 1, end - 1);
        }
    }
    Calculate(arr, 0, count - 1);
    for(int i = 0; i < count; i++)
    {
        if(arr[i].type == Int)
        {
            printf("%d\n", arr[i].integer);
            break;
        }
        else if(arr[i].type == Float)
        {
            printf("%.3lf\n", arr[i].floating);
            break;
        }
    }
    return 0;
}
