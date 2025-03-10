#include<stdio.h>
#include<string.h>
struct Node
{
    int team;
    int index;
    Node* next;

    Node(int t, int i)
    {
        team = t;
        index = i;
        next = nullptr;
    }
};

Node* FindTeam(Node* p, int t)
{
    while(p->team != t)
    {
        if(p->next == nullptr)
            return p;
        else
            p = p->next;
    }
    return p;
}
void AddNode(Node* p, int t, int i)
{
    while(p->next != nullptr && p->next->team == t)
        p = p->next;
    Node* temp = new Node(t, i);
    temp->next = p->next;
    p->next = temp;
}
Node* Dequeue(int &n, Node* root)
{
    n = root->index;
    Node* temp = root->next;
    delete root;
    return temp;
}
void Clean(Node* p)
{
    if(p->next == nullptr)
        delete p;
    else
    {
        Clean(p->next);
        delete p;
    }
}

int main()
{
    int teamNum;
    int res[10][100];
    int arrCount[10];
    int problemNum = 0;
    while(scanf("%d", &teamNum))
    {
        if(teamNum == 0)
            break;
        int count = 0;
        int nodeNum = 0;
        Node* root;
        char instruction[8];
        while(scanf("%s", instruction))
        {
            if(strcmp(instruction, "ENQUEUE") == 0)
            {
                int team, index;
                scanf("%d %d", &team, &index);
                if(nodeNum == 0)
                    root = new Node(team, index);
                else
                {
                    Node* temp = FindTeam(root, team);
                    AddNode(temp, team, index);
                }
                nodeNum++;
            }
            else if(strcmp(instruction, "DEQUEUE") == 0)
            {
                int num;
                root = Dequeue(num, root);
                res[problemNum][count++] = num;
                nodeNum--;
            }
            else
            {
                arrCount[problemNum] = count;
                problemNum++;
                if(nodeNum > 0)
                    Clean(root);
                break;
            }
        }
    }
    for(int i = 0; i < problemNum; i++)
    {
        printf("Scenario #%d\n", i + 1);
        int count = arrCount[i];
        for(int j = 0; j < count; j++)
        {
            printf("%d\n", res[i][j]);
        }
    }
    return 0;
}