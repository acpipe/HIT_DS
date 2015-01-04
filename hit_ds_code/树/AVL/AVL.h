//file：AVL.h
#ifndef _BST_H_HITHUMING_INCLUDE_
#define _BST_H_HITHUMING_INCLUDE_
#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
template <class T>
class AVL;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL){};
    node(T p)
    {
        this->data=p;
        lchild=NULL;
        rchild=NULL;
    };
    ~node(){delete this;};
    T return_data(){return data;};
    node<T>* return_lc(){ return lchild;};
    node<T>* return_rc(){ return rchild;};
    friend class AVL<T>;//友元~~
private:
    T data;
    int bf;//节点的平衡因子
    node<T> *lchild, *rchild;
};
template <class T>
class AVL
{
public:
    AVL():flag(false),root(NULL) {};
    ~AVL() {};
    void Create();
    void Insert(node<T>* &t,T key);
    void Leftrotation(node<T>* &t);
    void Rightrotation(node<T>* &t);
    node<T>* return_rt(){return root;}
    void level_order(node<T>* t);
    void in_order(node<T>* t);
private:
    bool flag;
//标记树是否长高啦！工大的孩纸小心啊，
//书上那个不对！我看啦网上一篇博客才知道这种思路要标记的是树是否长高啦！
//但是工大书上这种思路挺节省空间的，还有的算法是又求高度算平衡因子，
//还有的是又用啦一个父节点，不知道鸟，我觉得这种思路还是很好理解的！
    node<T>* root;
};
template <class T>
void AVL<T>::in_order(node<T>* t)
{
    if(t!=NULL)
        {
           in_order(t->lchild);
           cout <<t->data << " ";
           in_order(t->rchild);
        }
}
template <class T>
void AVL<T>::level_order(node<T>* t)
{
    queue<node<T>*> q;
    node<T>* p;
    if(t==NULL)  return ;
    q.push(t);
    while(!q.empty())
    {
        p=q.front();
      cout << p->data << " " ;
      if(p->lchild)
          q.push(p->lchild);
      if(p->rchild)
        q.push(p->rchild);
      q.pop();
    }
}
template <class T>
void AVL<T>::Create()
{
    node<T>* F=NULL;
    T m;
    while(cin >> m&&m!=0)
    {
        flag=false;
        Insert(F,m);
    }//利用不断的插入来建立
    root=F;
}
template <class T>
void AVL<T>::Insert(node<T>* &t,T key)
{
    if(t==NULL)
    {
        t=new node<T>;
        t->data=key;
        t->lchild= t->rchild=NULL;
        t->bf=0;//空二叉树，这个节点的平衡因子为0
    }
    else if(key<t->data)
    {
        Insert(t->lchild,key);//和前面普通BST对应，插入
        if(flag)//树长高啦有可能需要平衡化处理
        {
            switch(t->bf)
            {
            case 1:
                Leftrotation(t);
                //插入前左边的树高，对应书上LL(左子树的左子树上插入),LR(左子树的右子树上),进行旋转平衡
                flag=false;
                break;
            case 0:
                //插入之前左右两边相等
                t->bf=1;//t的平衡因子+1，但是其他节点的平衡因子是不变的！
                flag=true;
                break;
            case -1:
                //插入之前右边比左边高
                t->bf=0;
                flag=false;
                break;
            }
        }
    }
    else if(key>t->data)
    {
        Insert(t->rchild,key);//和前面普通BST对应，插入
        if(flag)//树长高啦有可能需要平衡化处理
        {
            switch(t->bf)
            {
            case 1:
//                      原来左边比右边高，现在一样啦~
                t->bf=0;
                flag=false;
                break;
            case 0:
                //插入之前左右两边相等
                t->bf=-1;//t的平衡因子-1，但是其他节点的平衡因子是不变的！
                flag=true;
                break;
            case -1:
                //插入之前右边比左边高,对应RL,RR两种情况！右转！
                Rightrotation(t);
                flag=false;
                break;
            }
        }
    }
    else flag=false;//相等，BST中是不允许出现的！
}
template <class T>
void AVL<T>::Leftrotation(node<T>* &t)
{
    node<T> *lc,*gc;
    lc=t->lchild;
    if(lc->bf==1)//LL
    {
        t->lchild=lc->rchild;
        lc->lchild=t;
        t->bf=0;
        t=lc;
    }
    else//LR
    {
        gc=lc->rchild;
        lc->rchild=gc->lchild;
        gc->lchild=lc;
        t->lchild=gc->rchild;
        gc->rchild=t;
        switch(gc->bf)
        {
        case 1:
            t->bf=-1;
            lc->bf=0;
            break;
        case -1:
            t->bf=0;
            lc->bf=1;
            break;
        case 0:
            t->bf=lc->bf=0;
            break;
        }
        t=gc;
    }
    t->bf=0;
    flag=false;
}
template <class T>
void AVL<T>::Rightrotation(node<T>* &t)
{
    node<T> *rc,*gc;
    rc=t->rchild;
    if(rc->bf==-1)//RR
    {
       t->rchild=rc->lchild;
       rc->lchild=t;
       t->bf=0;
       t=rc;
    }
    else//RL
    {
        gc=rc->lchild;
        rc->lchild=gc->rchild;
        gc->rchild=rc;
        t->rchild=gc->lchild;
        gc->lchild=t;
        switch(gc->bf)
        {
        case 1:
            t->bf=0;
            rc->bf=-1;
            break;
        case -1:
            t->bf=1;
            rc->bf=0;
            break;
        case 0:
            t->bf=rc->bf=0;
            break;
        }
        t=gc;
    }
    t->bf=0;
    flag=false;
}
#endif




