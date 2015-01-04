#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100+50
#define MAXM 1000000
using namespace std;
int N,R;
int p[MAXN],r[MAXM];
int u[MAXM],v[MAXM],w[MAXM];
bool cmp(const int i,const int j) {return w[i] < w[j];}
int find(int x) { return p[x] == x? x : p[x] = find(p[x]); }  //这个优化就是直接把要找的叶子连接在该树的树根上，就因为多了一个” p[i] = “. 优化到几乎为常熟
void kruskal()
{
    int ans = 0;
    int i,j=0;
    for(i=0; i<MAXN; i++)   p[i] = i;    // 初始化空树，就是初始化代表元
    for(i=0; i<MAXM; i++)   r[i] = i;    //初始化间接排序下标
    sort(r,r+R,cmp);    //使用间接排序，把由小到大的w[i]的下标 ,存在r[i] 数组中。
    for(i=0; i<R; i++)     //就是大大的for 循环
    {

        int e = r[i];      //把该下标取出来，就是从i=0开始去r[i]，对应的e就是从小到大的w[i] 的下标。
        int x = find(u[e]);int y = find(v[e]);     //并查集的应用。有优化
        if(x != y) { j++; ans += w[e]; p[x] = y; }
        if(j == N-1) break;                    //这也是对时间的优化，判断是否已经加入了N-1 条边，是的化直接跳出
    }
    printf("%d\n",ans);
}

int main()
{
    int i,n;
    while(cin >>n &&n)
    {
        scanf("%d",&R);
        for(i=0; i<R; i++)
           cin >>  u[i] >>v[i] >> w[i];
        kruskal();
    }
    return 0;
}
