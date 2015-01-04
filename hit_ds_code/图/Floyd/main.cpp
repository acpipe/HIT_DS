//注意Floyd要求不能有负数权值和回路，还必须是有向边
#include <iostream>
using namespace std;
#define inf 0x3f3f3f3f
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
    }
}
void Floyd()
{
    int d[101][101];
    for(int i=1; i<=C.n; i++)
        for(int j=1; j<=C.n; j++)
            d[i][j]=C.mat[i][j];
    for(int k=1; k<=C.n; k++)
        for(int i=1; i<=C.n; i++)
            for(int j=1; j<=C.n; j++)
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
     //floyd
    for(int i=1; i<=C.n; i++)
    {
        for(int j=1; j<=C.n; j++)
           {
               if(d[i][j]==inf)  cout << "∞" << " ";
               else  cout <<  d[i][j] << " ";
           }
        cout << endl;
    }//print
}
int main()
{
    setgraph();
    Floyd();
    return 0;
}

