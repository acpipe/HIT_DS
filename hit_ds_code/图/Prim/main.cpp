#include <iostream>
#include<cstring>
#include<cstdio>
#define inf 1000
using namespace std;
struct graph
{
    int n,e;
    int mat[101][101];
};
struct graph  C;
void setgraph()
{
    int m,n,x;
    cin >> C.n >> C.e;
    for(int i=1; i<=C.n; i++)
        for(int j=1; j<=C.n; j++)
            C.mat[i][j]= inf;
    for(int i=1; i<=C.e; i++)
    {
        cin >> m >> n >> x;
        C.mat[m][n]=x;
        C.mat[n][m]=x;
    }//无向图
}
int prim()
{
    bool  visited[101];//标记是否访问过
    int  p,i,j,ans=0,minw;//p用于标记当前最小的权值出现的位置,ans为权值,minw为当前最小的权值
    int low[101];//到每个点的最小权值
    memset(visited,false,sizeof(visited));
    visited[1]=true,p=1;
    for(i=2; i<=C.n; i++)
        low[i]=C.mat[p][i];
    //开始的时候选中第一个顶点，最小权值设为第一个顶点到其他顶点的距离
    for(i=1; i<C.n; i++)
    {
        minw=inf;
        for(j=1; j<=C.n; j++)
            if(!visited[j]&&minw>low[j])
            {
                minw=low[j];
                p=j;
            }//找出最小权值的点
        visited[p]=true;//标记这个点
        ans+=minw;
        for(j=1; j<=C.n; j++)
            if(!visited[j]&&low[j]>C.mat[p][j])
                low[j]=C.mat[p][j];
    }
    //进行n-1次更新，而不是n次
    return ans;
}
int main()
{
    setgraph();
    cout << prim() << endl;
    return 0;
}


