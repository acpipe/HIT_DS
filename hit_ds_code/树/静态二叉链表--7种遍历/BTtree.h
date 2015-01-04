//file:BTtree.h
#ifndef _BTTREE_H_HUMING_INCLUDE_
#define _BTTREE_H_HUMING_INCLUDE_
#include<iostream>
#include<queue>
#include<stack>
#define maxlen 1002
using namespace std;
template <class T>
class treenode
{
public:
    treenode():lchild(-1),rchild(-1) {}; //构造函数
    ~treenode() {}; //析构函数
    T  data;
    int lchild,rchild;
};
template <class T>
class BTtree
{
public:
    BTtree():root(-1),nodenum(0) {}; //构造函数，树为空，开始的时候没有元素
    ~BTtree() {};//析构
    void pre_create();  //建立二叉树
    int Lchild(int  t);//返回右儿子位置
    int Rchild(int t);  //返回儿子位置
    T elements(int t);  //返回下标所对应元素
    bool Isempty();  //判空
    int return_root();  //返回根节点下标
    void pre_order(int t);//先序递归
    void in_order(int t);//中序递归
    void post_order(int t);//后序递归
    void nrec_pre_order(int t);//先序非递归
    void nrec_in_order(int t);//中序非递归
    void nrec_post_order(int t);//后序非递归
    void level_order(int t);//层序遍历
    //几个遍历函数@
private:
    treenode<T> element[maxlen];//二叉树的节点
    int root;//根节点的下标
    int nodenum;//存储所用空间
    int insert(); //用来插入
};
template <class T>
int BTtree<T>::Lchild(int t)
{
  return element[t].rchild;
}
template <class T>
int BTtree<T>::Rchild(int t)
{
    return element[t].lchild;
}
template<class T>
T BTtree<T>::elements(int t)
{
    return element[t].data;
}
template <class T>
int  BTtree<T>::return_root()
{
    return root;
}
template <class T>
void BTtree<T>::pre_create()
{
    root=insert();
}
template<class T>
int BTtree<T>::insert()
{
    T ch;
    cin >> ch;
    int t=nodenum;
    //把最后一个节点的下标赋给t，要知道每个节点都是一二叉树，这是建立二叉树的基础
    if(ch=='#') t=-1;
    else
    {
        nodenum++;//相当于链表中的开辟新的节点
        element[t].data=ch;
        element[t].lchild=insert();
        element[t].rchild=insert();
    }
    return t;//返回二叉树根节点的下标
}
template <class T>
void BTtree<T>::pre_order(int t)
{
    if(t!=-1)
    {
        cout << element[t].data;
        pre_order(element[t].lchild);
        pre_order(element[t].rchild);
    }
}

template <class T>
void BTtree<T>::in_order(int t)
{
    if(t!=-1)
    {
        in_order(element[t].lchild);
        cout << element[t].data;
        in_order(element[t].rchild);
    }
}
template <class T>
void BTtree<T>::post_order(int t)
{
    if(t!=-1)
    {
        post_order(element[t].lchild);
        post_order(element[t].rchild);
        cout << element[t].data;
    }
}
template <class T>
void BTtree<T>::nrec_pre_order(int t)
{
    stack<int> s;
    while(t!=-1||!s.empty())//循环到栈空而且树为空
    {
        while(t!=-1)//如果树不为空一直向下访问，左走一步
        {
            cout << element[t].data;
            s.push(t);
            t=element[t].lchild;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();//取栈顶并出栈
            t=element[t].rchild; //右走一步
        }
    }
}
template <class T>
void BTtree<T>::nrec_in_order(int t)
{
    stack<int> s;
    while(t!=-1||!s.empty())//循环到栈空而且树为空
    {
        if(t!=-1)//树不空压栈左走一步
        {
            s.push(t);
            t=element[t].lchild;
        }
        else//树空（这时候在左儿子上），出栈访问父节点，右走【中序】
        {
            t=s.top();
            s.pop();
            cout << element[t].data;
            t=element[t].rchild;
        }
    }
}
template <class T>
void BTtree<T>::nrec_post_order(int t)
{
    struct STACK
    {
        int  tree,flag;
    } S[maxlen];
    int top=maxlen;//设置一个倒过来的顺序栈（受书上影响，我喜欢倒着用，看个人习惯~~）
    int temp;
    temp=t;
    while(temp!=-1||top!=maxlen)//循环到栈空和树空
    {
        if(temp!=-1)//树不空，入栈并标记为第一次访问，左走
        {
            S[--top].tree=temp;
            S[top].flag=1;
            temp=element[temp].lchild;
        }
        else//树空
        {
            if(S[top].flag==2)//如果栈顶元素是已经两次访问过的，那么出栈访问输出
            {
                t=S[top++].tree;
                cout << element[t].data;
            }
            else//如果栈顶访问过一次，那么标记为第二次访问，右走
            {
                S[top].flag=2;
                temp=element[S[top].tree].rchild;
            }
        }
    }
}
template <class T>
void BTtree<T>::level_order(int  t)
{
    //层序有先进先出的特点
    queue<int> q;
    int p;
    if(t==-1)  return;
    q.push(t);
    while(!q.empty())//访问到队列空
    {
        p=q.front();
        cout << element[p].data;//出队访问
        if(element[p].lchild!=-1)
            q.push(element[p].lchild);//左树不空，入队
        if(element[p].rchild!=-1)
            q.push(element[p].rchild);//右树不空，入队
        q.pop();
    }
}
#endif
