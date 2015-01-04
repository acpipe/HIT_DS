#include<iostream>
#include  "queue_link.h"
#include<cstring>
#define maxlen 22
#include<cstdio>
int mat[maxlen][maxlen],black,white;
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
using namespace std;
struct ND
{
    int x,y;
};
void BFS(ND s,int n)
{
    int f1=0,f2=0,count=0;
    queue<ND> q;
    ND  ol,ne;
    while(!q.empty())
    {
        q.pop();
    }
    q.push(s);
    mat[s.x][s.y]=3;
    while(!q.empty())
    {
        ol=q.front();
        q.pop();
        count++;
        //出队之后count再更新，入队不更新
        for(int i=0; i<4; i++)
        {
            ne.x=ol.x+dir[i][0];
            ne.y=ol.y+dir[i][1];
            if(ne.x>=1&&ne.x<=n&&ne.y>=1&&ne.y<=n)
            {
                if(mat[ne.x][ne.y]==0)
                {
                    mat[ne.x][ne.y]=3;
                          q.push(ne);
                }
                else if(mat[ne.x][ne.y]==1)
                    f1=1;
                else if(mat[ne.x][ne.y]==2)
                    f2=1;
            }
        }
    }
    if(f1+f2!=2)//只要遇到两个都有这种情况，那么就说明这种情况是黑白棋包围
    {
        if(f2)
            black+=count;
        if(f1)
            white+=count;
    }
}
int main()
{
    int n,b,w,i,j;
    ND s;
    while(cin >> n&& n)
    {
        black=0,white=0;
        memset(mat,0,sizeof(mat));
        cin >> b >> w;
        while(b--)
        {
            cin >> i >> j;
            mat[i][j]=2;//b
        }
        while(w--)
        {
            cin >> i >> j;
            mat[i][j]=1;//w
        }
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(mat[i][j]==0)
                {
                    s.x=i;
                    s.y=j;
                    BFS(s,n);
                }
            }
        if(black>white)printf("Black wins by %d\n",black-white);
        else if(white>black) printf("White wins by %d\n",white-black);
        else printf("Draw\n");
    }
    return 0;
}

