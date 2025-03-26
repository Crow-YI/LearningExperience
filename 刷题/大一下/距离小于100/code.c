#include<stdio.h>
#include<math.h>
#define MAX 1000
#define DIS 10000
typedef struct 
{
    int x, y, z;
} Point;

int NearPoints(Point *p, int n) 
{
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        Point temp = p[i];
        if(temp.x > 100 || temp.x < -100 || temp.y > 100 || temp.y < -100 || temp.z > 100 || temp.z < -100)
        {
            continue;
        }
        else
        {
            if(temp.x * temp.x + temp.y * temp.y + temp.z * temp.z >= DIS)
                continue;
            else
                ret++;
        }
    }
    return ret;
}

int main() 
{
    int n, i;
    Point p[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    printf("%d\n", NearPoints(p, n));
    return 0;
}