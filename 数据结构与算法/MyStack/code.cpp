#include<stdio.h>
typedef int StackType;
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