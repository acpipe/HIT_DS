#ifndef FOREST_H_INCLUDED
#define FOREST_H_INCLUDED
#define maxlength 10000
#include "stack.h"
#include "queue.h"
//#include<queue>
//#include<stack>
#include <iostream>
using namespace std;
template<typename T>//孩子链表中的每个结点
class CTNode
{
public:
    CTNode()
    {
        next=0;
        child=0;
    }
    CTNode(int tmp)
    {
        next=0;
        child=tmp;
    }
    int child;//孩子结点的编号
    T data;//(备用)孩子结点的信息
    CTNode *next;
};
template<typename T>//线性表中的每个结点
class CTBox
{
public:
    CTBox()
    {
        flag=false;
        count=0;
        firstchild=NULL;
    }
    T data;//每个结点的信息
    int count;//每个结点孩子的个数
    bool flag;//在森林转换为二叉树时用到flag变量
    CTNode<T> *firstchild;//指向第一个孩子结点的指针
};
template<typename T>//二叉树中的每个结点
class BTNode
{
public:
    BTNode()
    {
        firstchild=0;
        rightsib=0;
        rank=0;
    }
    BTNode(T value)
    {
        data=value;
        firstchild=0;
        rightsib=0;
        rank=0;
    }
    T data;
    BTNode<T> *firstchild,*rightsib;
    int rank;//表示二叉树所对应的森林中该结点按层序的编号
};
template<typename T>
class forest
{
public:
    forest();
    ~forest();
    void Number();
    void ClearBT(BTNode<T> *p);
    void CreateForest();//建立森林的邻接表存储结构
    void CreateBT();//建立森林的二叉链表存储结构
    void TransformBTtoForest();//将二叉树转换为森林
    void TransformForesttoBT();//将森林转换为二叉树
    void Print();//打印森林的邻接表存储结构
    void Insert(int i,int j);//将编号为j的结点插入到编号为i的结点的孩子链表的尾部
    void Delete(CTNode<T>* p);//删除p所指结点后面的一个结点
    int Count(BTNode<T>* p);//返回以p为根结点的二叉树的结点个数
    void PreOrder(BTNode<T> *p);
    void InOrder(BTNode<T> *p);
    void PostOrder(BTNode<T> *p);
private:
    int n;//树的个数
    BTNode<T> *BT;//二叉树的根结点
    int root[maxlength],num[maxlength];
    BTNode<T> *S[maxlength];
    CTBox<T> *Tree;
};
template<typename T>
forest<T>::forest()
{
    Tree=new CTBox<T> [maxlength];
    BT=NULL;
}
template<typename T>
forest<T>::~forest()
{
    delete []Tree;
    delete []root;
    delete []num;
    delete []S;
    ClearBT(BT);
}
template<typename T>//建立森林的邻接表存储结构
void forest<T>::CreateForest()
{
    delete []Tree;
    Tree=new CTBox<T> [maxlength];
    int a,b;
    T temp;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin.ignore(80,'\n');
        cin>>root[i]>>num[i];
        for(int j=1; j<=num[i]; j++)
        {
            cin.ignore(80,'\n');
            cin>>a>>temp;
            Tree[a].data=temp;
            while(cin>>b&&b)
                Insert(a,b);
        }
    }
}
template<typename T>//建立森林的二叉链表存储结构
void forest<T>::CreateBT()
{
    BTNode<T> *p;
    int i;
    T temp;
    while(cin>>i>>temp&&i)
    {
        p=new BTNode<T>(temp);
        S[i]=p;
        if(i==1) BT=p;
        else if(i%2==0) S[i/2]->firstchild=p;
        else S[i/2]->rightsib=p;
    }
}
template<typename T>//打印森林的邻接表存储结构
void forest<T>::Print()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
        {
            cout<<j<<"."<<Tree[j].data<<"->";
            for(CTNode<T> *p=Tree[j].firstchild; p!=NULL; p=p->next)
                cout<<p->child<<"->";
            cout<<"^"<<endl;
        }
    }
}
template<typename T>
int forest<T>::Count(BTNode<T> *p)
{
    if(p)
    {
        int m=Count(p->firstchild);
        int n=Count(p->rightsib);
        return m+n+1;
    }
    else return 0;
}
template<typename T>
void forest<T>::Insert(int i,int j)//将编号为j的结点加入到编号为i的孩子链表的尾部
{
    if(!Tree[i].count)  Tree[i].firstchild=new CTNode<T>(j);
    else
    {
        CTNode<T>* tmp=Tree[i].firstchild;
        while(tmp->next)
            tmp=tmp->next;
        tmp->next=new CTNode<T>(j);
    }
    (Tree[i].count)++;
}
template<typename T>//将森林转换为二叉树
void forest<T>::TransformForesttoBT()
{
    for(int i=1; i<=n; i++)
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
            S[j]=new BTNode<T>(Tree[j].data);
    for(int i=1; i<=n; i++)
    {
        if(i>1)S[root[i-1]]->rightsib=S[root[i]];
        for(int j=root[i]; j<=root[i]+num[i]-1; j++)
        {
            if(Tree[j].count>0)
            {
                S[j]->firstchild=S[Tree[j].firstchild->child];
                for(CTNode<T> *p=Tree[j].firstchild; p->next!=NULL; p=p->next)
                    S[p->child]->rightsib=S[p->next->child];
            }
        }
    }
    BT=S[1];
    PreOrder(BT);
    cout<<endl;
    InOrder(BT);
    cout<<endl;
}
template<typename T>//对结点进行编号
void forest<T>::Number()
{
    BTNode<T> *p=BT,*q;
    queue<BTNode<T>*> u;
    int tmp=0;
    while(p)
    {
        u.Enqueue(p);
        while(!u.Empty())
        {
            q=u.Front();
            q->rank=(++tmp);
            Tree[tmp].data=q->data;
            u.Dequeue();
            for(q=q->firstchild; q!=NULL; q=q->rightsib)
                u.Enqueue(q);
        }
        p=p->rightsib;
    }
}
template<typename T>//将二叉树转换为森林
void forest<T>::TransformBTtoForest()
{
    delete []Tree;
    Tree=new CTBox<T> [maxlength];
    Number();
    BTNode<T> *p=BT,*pp;
    stack<BTNode<T>*> v;
    while(p||!v.empty())
    {
        if(p)
        {
            v.push(p);
            pp=p;
            for(p=p->firstchild; p!=NULL; p=p->rightsib)
                Insert(pp->rank,p->rank);
            p=pp->firstchild;
        }
        else
        {
            p=v.top()->rightsib;
            v.pop();
        }
    }
    n=0;
    for(p=BT; p!=NULL; p=p->rightsib)
    {
        root[++n]=p->rank;
        num[n]=Count(p->firstchild)+1;
    }
}
template<typename T>//删除二叉树
void forest<T>::ClearBT(BTNode<T>* tmp)
{
    if(tmp)
    {
        ClearBT(tmp->firstchild);
        ClearBT(tmp->rightsib);
        delete tmp;
    }
    else return;
}
template<typename T>
void forest<T>::PreOrder(BTNode<T> *p)
{
    if(p)
    {
        cout<<p->data;
        PreOrder(p->firstchild);
        PreOrder(p->rightsib);
    }
    else return;
}
template<typename T>
void forest<T>::InOrder(BTNode<T> *p)
{
    if(p)
    {
        InOrder(p->firstchild);
        cout<<p->data;
        InOrder(p->rightsib);
    }
    else return;
}
template<typename T>
void forest<T>::PostOrder(BTNode<T> *p)
{
    if(p)
    {
        PostOrder(p->firstchild);
        PostOrder(p->rightsib);
        cout<<p->data;
    }
    else return;
}
#endif // FOREST_H_INCLUDED
