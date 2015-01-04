#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
struct graph
{
    int n,e;
    int mat[101][101];
};
int d[101];
struct graph  C;
bool s[101];
//    d[] 最短的
//    s[] 是否在图中
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
    }
}
void Dijkstra()
{
    for(int i=1; i<=C.n; i++)
    {
        d[i]=C.mat[1][i];
        s[i]=false;
    }
    s[1]=true;
    for(int i=1; i<=C.n; i++)
    {
        int temp=inf,w=2,sum;
        for (int i=2; i<=C.n; i++)
            if (s[i]==false&&d[i]<temp)
            {
                temp = d[i];
                w=i ;
            }
        //找最小得到
        s[w]=true;//将最小的在s中
        for(int v=2; v<=C.n; v++)
            if(s[v]==false)//不在s中
            {
                sum=d[w]+C.mat[w][v];
                if(sum<d[v])  d[v]=sum;
            }
        for(int j=2; j<=C.n; j++)
            cout << d[j] << " " ;
        cout << endl;
    }
}
int main()
{
    setgraph();
    Dijkstra();
    return 0;
}

