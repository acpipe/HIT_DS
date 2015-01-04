//迷宫求解
#include <iostream>
#include<cstdio>
#include "mystack.h"
#define maxlen 102
using namespace std;
int mat[maxlen][maxlen];
int dir[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};//移动的方向
struct node
{
    int x,y;
    int x1,y1;
};
void path(int m,int n)
{
    Stack<node> s;
    node ol,ne;
    mat[0][0]=1;
    ol.x=0,ol.y=0;
    ol.x1=0;
    ol.y1=0;
    while(!s.empty())
    {
        s.pop();
    }
    s.push(ol);
    while(!s.empty())
    {
        ol=s.top();
        if(ol.x==m-1&&ol.y==n-1)
        {
            break;
        }//终点
        int flag=0;
        for(int l=0; l<4; l++)
        {
            ne.x=ol.x+dir[l][0];
            ne.y=ol.y+dir[l][1];
            if(ne.x<0||ne.y<0||ne.x>m-1||ne.y>n-1||mat[ne.x][ne.y])    //边界条件判断
            {
                flag++;
                if(flag==4)
                {
                    s.pop();    //四个方向都不行
                }
                else continue;
            }
            else if(mat[ne.x][ne.y]==0)
            {
                ne.x1=ol.x;
                ne.y1=ol.y;
                s.push(ne);
                mat[ne.x][ne.y]=2;
            }
        }
    }
    node f,f1;
    Stack<node>s1;
//    int x2,y2;
//    x2 = m-1,y2 = n-1;
    f = s.top();
    s1.push(f);
    s.pop();
    while (!s.empty())
    {
        f1 = s.top();
        while (f.x1 != f1.x || f.y1 != f1.y)
        {
            s.pop();
            f1 = s.top();
        }
        f = f1;
        s1.push(f1);
        s.pop();
    }
    while(!s1.empty())
    {
        f=s1.top();
        printf("(%d,%d)\n",f.x,f.y);
        s1.pop();
    }
}
int main()
{
    int m,n,i,j;
    cin >> m >> n;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            cin >> mat[i][j];
    path(m,n);
    return 0;
}




