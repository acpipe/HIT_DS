//ŒË∞ÈŒ Ã‚
#include<iostream>
#include "queue.h"
using namespace std;
struct node
{
    char name[20];
    char sex;
};
int main()
{
    Queue<node> m,w;
    int n;
    struct node x;
    cin >> n;
    while(n--)
    {
        cin >> x.name;
        cin >> x.sex;
        if(x.sex=='w')  w.push(x);
        else if(x.sex=='m') m.push(x);
        else ;
    }
    while(!w.empty()&&!m.empty())
    {
        cout << w.front().name << "--" << m.front().name << endl;
        w.pop();
        m.pop();
    }
    if(w.empty()&&!m.empty())
    {
        printf("There are men still waiting!\n");
    }
    else if(m.empty()&&!w.empty())
    {
        printf("There are women still waiting!\n");
    }
    else printf("There is no person waiting!\n");
    return 0;
}
