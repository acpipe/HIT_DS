//file:BTtree.h
#ifndef _BTTREE_H_HUMING_INCLUDE_
#define _BTTREE_H_HUMING_INCLUDE_
#include<iostream>
#include<queue>
#include<stack>
#define maxlen 100
using namespace std;
template <class T>
class treenode
{
public:
    treenode():lchild(NULL),rchild(NULL) {};
    treenode(const T &v,treenode<T> *left,treenode<T> *right):data(v),lchild(left),rchild(right) {};
    ~treenode()
    {
        delete lchild;
        delete rchild;
    }
    treenode<T> *lchild,*rchild;
    T data;
};
template <class T>
class BTtree
{
public:
    BTtree():root(NULL) {};
    ~BTtree();
    void pre_create();
    bool Isempty();
    treenode<T>* Lchild(treenode<T>* t);
    treenode<T>* Rchild(treenode<T>* t);
    T element(treenode<T>* t);
    treenode<T>* return_root();
    void pre_order(treenode<T>* t);
    void in_order(treenode<T>* t);
    void post_order(treenode<T>* t);
    void nrec_pre_order(treenode<T>* t);
    void nrec_in_order(treenode<T>* t);
    void nrec_post_order(treenode<T>* t);
    void level_order(treenode<T>* t);
private:
    treenode<T> *root;
    void clear(treenode<T>* t);
    treenode<T>*insert();
};

template<class T>
BTtree<T>::~BTtree()
{
    clear(root);
    delete root;
}
template <class T>
void BTtree<T>::clear(treenode<T>* t)
{
    if(t==NULL) return;
    else
    {
        clear(t->lchild);
        clear(t->rchild);
        t=NULL;
    }
}
template <class T>
void BTtree<T>::pre_create()
{
    root=insert();
}
template<class T>
treenode<T>* BTtree<T>::insert()
{
    T ch;
    treenode<T> *t;
    cin >> ch;
    if(ch=='#')  t=NULL;
    else
    {
        t=new treenode<T>;
        t->data=ch;
        t->lchild=insert();
        t->rchild=insert();
    }
    return t;
}
template<class T>
bool BTtree<T>::Isempty()
{
    return root?false:true;
}
template <class T>
treenode<T>* BTtree<T>::Lchild(treenode<T>* t)
{
    return t->lchild?t->lchild:NULL;
}
template <class T>
treenode<T>* BTtree<T>::Rchild(treenode<T>* t)
{
    return t->rchild?t->rchild:NULL;
}
template <class T>
T BTtree<T>::element(treenode<T>* t)
{
    return t->data;;
}
template <class T>
void BTtree<T>::pre_order(treenode<T>* t)
{
    if(t!=NULL)
    {
        cout << t->data;
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}
template <class T>
treenode<T>* BTtree<T>::return_root()
{
    return root;
}
template <class T>
void BTtree<T>::in_order(treenode<T>* t)
{
    if(t!=NULL)
    {
        in_order(t->lchild);
        cout << t->data;
        in_order(t->rchild);
    }
}
template <class T>
void BTtree<T>::post_order(treenode<T>* t)
{
    if(t!=NULL)
    {
        post_order(t->lchild);
        post_order(t->rchild);
        cout << t->data;
    }
}
template <class T>
void BTtree<T>::nrec_pre_order(treenode<T>* t)
{
    stack<treenode<T>*> s;
    while(t!=NULL||!s.empty())
    {
        while(t!=NULL)
        {
            cout << t->data;
            s.push(t);
            t=t->lchild;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();
            t=t->rchild;
        }
    }
}
template <class T>
void BTtree<T>::nrec_in_order(treenode<T>* t)
{
    stack<treenode<T>*> s;
    while(t!=NULL||!s.empty())
    {
        if(t!=NULL)
        {
            s.push(t);
            t=t->lchild;
        }
        else
        {
            t=s.top();
            s.pop();
            cout << t->data;
            t=t->rchild;
        }
    }
}
template <class T>
void BTtree<T>::nrec_post_order(treenode<T>* t)
{
//    struct ND
//    {
//        treenode<T>* x;
//        int flag;
//    };
//    ND temp;
//    stack <ND> s;
//    temp.x=t;
//    while(temp.x!=NULL||!s.empty())
//    {
//        if(temp.x!=NULL)
//        {
//            temp.flag=1;
//            s.push(temp);
//            temp.x=temp.x->lchild;
//        }
//        else
//        {
//            if(s.top().flag==2)
//            {
//                s.pop();
//                cout << s.top().x->data;
//            }
//            else
//            {
//                s.top().flag=2;
//                temp.x=s.top().x->rchild;
//            }
//        }
//    }//不知道为什么用STL这段不行！
    struct STACK
    {
        treenode<T>*  tree;
        int  flag;
    } S[maxlen];
    int top=maxlen;
    treenode<T>* temp;
    temp=t;
    while(temp!=NULL||top!=maxlen)
    {
        if(temp!=NULL)
        {
            S[--top].tree=temp;
            S[top].flag=1;
            temp=temp->lchild;
        }
        else
        {
            if(S[top].flag==2)
            {
                t=S[top++].tree;
                cout << t->data;
            }
            else
            {
                S[top].flag=2;
                temp=S[top].tree->rchild;
            }
        }
    }
}
template <class T>
void BTtree<T>::level_order(treenode<T>* t)
{
    queue<treenode<T>*> q;
    treenode<T>* p;
    if(t==NULL)  return ;
    q.push(t);
    while(!q.empty())
    {
        p=q.front();
      cout << p->data;
      if(p->lchild)
          q.push(p->lchild);
      if(p->rchild)
        q.push(p->rchild);
      q.pop();
    }
}
#endif














