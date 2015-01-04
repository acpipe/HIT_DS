//Topsort And AOE
#include <iostream>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
struct link
{
    int v;//事件编号
    int count;//活动的编号
    int weight;//活动的时间
    link * next;
};
struct node
{
    int indegree;//入度
    char element;//事件
    struct link* firstedge;
};//头结点
struct Adgraph
{
    int n,e;
    struct node Ad[101];
};//邻接表
void Create_AOE(struct Adgraph* G)
{
    int k,i,j,t;
    cin >> G->n >> G->e;//节点和边
    for (k=1; k<=G->n; k++)
    {
        cin >> G->Ad[k].element;
        G->Ad[k].firstedge=NULL;
        G->Ad[k].indegree=0;
    }//头结点的初始化
    printf("输入两个顶点(事件编号),边的权值(活动时间)\n");
    for(k=1; k<=G->e; k++)
    {
        cin >> j >> i >> t;
        G->Ad[i].indegree++;
        link* p=new link;
        p->v=i;
        p->weight=t;
        p->next=G->Ad[j].firstedge;
        G->Ad[j].firstedge=p;//在表头插入
    }
    printf("AOE网络构建完成\n-----人家是华丽丽的分割线-----\n打印邻接表：\n");
    for(i=1; i<=G->n; i++)
    {
        cout << G->Ad[i].element;
        link *m=G->Ad[i].firstedge;
        while(m!=NULL)
        {
            printf("->%c,%d",G->Ad[m->v].element,m->weight);
            m=m->next;
        }
        printf("->^\n");
    }//邻接表打印
    printf("\n");
}
void Criticalpath(Adgraph* G)//G为带权值的邻接表
{
    queue<int> Q;
    stack<int> S;
    int i,j,k,count=0,ve[101],vl[101],ae,al;
    //时间的最早发生时间和最晚发生时间，活动的最早发生时间和最晚发生时间
    //m用来计数,判断是否有回路
    for(i=1; i<=G->n; i++)ve[i]=0; //首先每个事件的最早发生时间都为0
    for(i=1; i<=G->n; i++)
        if(G->Ad[i].indegree==0) Q.push(i);
    //将入度为0的顶点入队
    printf("Topsort:");
    while(!Q.empty())
    {
        j=Q.front();
        Q.pop();
        count++;
        cout << G->Ad[j].element;
//               cout << j ;
        S.push(j);//把正序的拓扑序下标列入栈
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            G->Ad[k].indegree--;
            if(ve[j] + p->weight > ve[k])
                ve[k] = ve[j] + p->weight;
            if(G->Ad[k].indegree==0) Q.push(k) ;
            p=p->next;
        }
    }//用topsort求最早的发生时间
    printf("\n");
    if(count<G->n)
    {
        printf("有环路！\n");
        return;
    }
    for(i=1; i<=G->n; i++) //为各事件v(i)的最迟发生时间vl[i]置初值
        vl[i]=ve[G->n];
    printf("Opp_Topsort:");
    while(!S.empty())//按拓扑序列的逆序取顶点
    {
        j=S.top();
        S.pop();//出栈
        cout << G->Ad[j].element;
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            if((vl[k] - p->weight)<vl[j])
                vl[j]=vl[k]-p->weight;  //修改vl[j]
            p=p->next;
        }
    }
    printf("\nActivity<EnventA->EnventB>      AE     AL    Share time  Is Criticalpath?:\n");
    for(j=1; j<=G->n; j++) //扫描顶点表
    {
        link *p=G->Ad[j].firstedge;
        while(p!=NULL)
        {
            k=p->v;
            ae=ve[j];
            al=vl[k]-p->weight;
            printf("<事件%c,事件%c>\t\t\t%d\t%d\t%d    \t",G->Ad[j].element,G->Ad[k].element,ae,al,al-ae);
            if(al==ae)//关键活动
                printf("Yes");
                else printf("No");
            printf("\n");
            p=p->next;
        }
    }
}
int main()
{
    struct Adgraph G;
    Create_AOE(&G);
    Criticalpath(&G);
    return 0;
}

