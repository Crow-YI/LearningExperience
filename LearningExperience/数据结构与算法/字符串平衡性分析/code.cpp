#include<stdio.h>
typedef char CirQueueType;
const int maxQueueNum = 500;
enum ErrorCode
{
    overflow, empty, success
};
class MyCirQueue
{
private:
    int head;
    int rear;
    CirQueueType queue[maxQueueNum];
    int order;
public:
    MyCirQueue()
    {
        head = 0;
        rear = 0;
        order = 1;
    }
    ErrorCode Enqueue(CirQueueType num)
    {
        if((rear + order) % maxQueueNum == head || (rear + order + maxQueueNum) == head)
            return overflow;
        queue[rear] = num;
        rear += order;
        if(rear >= maxQueueNum || rear < 0)
            rear -= (order * maxQueueNum);
        return success;
    }
    void ForcedEnqueue(CirQueueType num)
    {
        if((rear + order) % maxQueueNum == head || (rear + order + maxQueueNum) == head)
        {
            CirQueueType n;
            Dequeue(n);
            Enqueue(num);
        }
        else
            Enqueue(num);
    }
    ErrorCode Dequeue(CirQueueType &num)
    {
        if(rear == head)
            return empty;
        num = queue[head];
        head += order;
        if(head >= maxQueueNum || head < 0)
            head -= (order * maxQueueNum);
        return success;
    }
    bool IsFull()
    {
        if((rear + order) % maxQueueNum == head || (rear + order + maxQueueNum) == head)
            return true;
        else
            return false;
    }
    bool IsEmpty()
    {
        if(rear == head)
            return true;
        else
            return false;
    }
    ErrorCode Front(CirQueueType &num)
    {
        if(rear == head)
            return empty;
        num = queue[head];
        return success;
    }
    ErrorCode Rear(CirQueueType &num)
    {
        if(rear == head)
            return empty;
        num = queue[rear];
        return success;
    }
    int Size()
    {
        if(order == 1)
        {
            if(head > rear)
                return rear + maxQueueNum - rear;
            else
                return rear - head;
        }
        else
        {
            if(rear > head)
                return head + maxQueueNum - rear;
            else
                return head - rear;
        }
    }
    void ReverseQueue()
    {
        int temp = head;
        head = rear;
        rear = temp;
        order *= -1;
        head += order;
        if(head >= maxQueueNum || head < 0)
            head -= (order * maxQueueNum);
        rear += order;
        if(rear >= maxQueueNum || rear < 0)
            rear -= (order * maxQueueNum);
    }
    void Clean()
    {
        head = 0;
        rear = 0;
        order = 1;
    }
};

int main()
{
    MyCirQueue l, r;
    char res[100];
    int n;
    scanf("%d", &n);
    getchar();
    bool haveColon = false;
    for(int i = 0; i < n; i++)
    {
        char c;
        while((c = getchar()) != ':' && c != '\n')
            l.Enqueue(c);
        if(c == ':')
        {
            haveColon = true;
            while((c = getchar()) != '\n')
                r.Enqueue(c);
        }
        if(!haveColon)
            res[i] = 'N';
        else
        {
            int lenLeft = l.Size();
            int lenRight = r.Size();
            if(lenLeft < lenRight)
                res[i] = 'R';
            else if(lenLeft > lenRight)
                res[i] = 'L';
            else
            {
                bool isDifferent = false;
                char cLeft;
                char cRight;
                for(int i = 0; i < lenLeft; i++)
                {
                    l.Dequeue(cLeft);
                    r.Dequeue(cRight);
                    if(cLeft != cRight)
                    {
                        isDifferent = true;
                        break;
                    }
                }
                if(isDifferent)
                    res[i] = 'D';
                else
                    res[i] = 'S';
            }
        }
        l.Clean();
        r.Clean();
    }
    for(int i = 0; i < n; i++)
    {
        printf("%c\n", res[i]);
    }
    return 0;
}