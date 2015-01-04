#include<iostream>
#include<queue>
using namespace std;
template <class T>
class tree;
template <class T>
class node
{
public:
    node():lchild(NULL),brother(NULL) {};
    ~node()
    {
        delete lchild;
        delete brother;
    };
    friend class tree<T>;
private:
    T data;
    node<T> *lchild,*brother;
};
template <class T>
class tree
{
public:
    void Create();
    node<T>* return_rt();
    void pre_order(node<T> *P);
    void post_order(node <T>*p);
    void level_order(node<T>*p);
private:
    node<T>* root;
    node<T>* Insert();
};
template <class T>
void tree<T>::level_order(node<T> *t)
{
    queue<node<T>*> Q;
    node<T>* q;
    if(t==NULL) return;
    else Q.push(t);
    while(!Q.empty())
    {
        t=Q.front();
        Q.pop();
        cout << t->data;
        for(q=t->lchild;q!=NULL;q=q->brother)
            Q.push(q);
    }
}

template <class T>
void tree<T>::post_order(node<T>* p)
{
    node<T>* q;
    if(p!=NULL)
    {
        for(q=p->lchild; q!=NULL; q=q->brother)
            post_order(q);
        cout << p->data;
    }
}
template <class T>
void tree<T>::pre_order(node<T> *p)
{
    if(p!=NULL)
    {
        cout << p->data;
        for(p=p->lchild; p!=NULL; p=p->brother)
            pre_order(p);
    }
}
template <class T>
node<T>* tree<T>::return_rt()
{
    return root;
}
template <class T>
void tree<T>::Create()
{
    root=Insert();
}
template <class T>
node<T>* tree<T>::Insert()
{
    T m;
    node<T> *t;
    cin >> m;
    if(m=='#')  return NULL;
    else
    {
        t=new node<T>;
        t->data=m;
        t->lchild=Insert();
        t->brother=Insert();
    }
    return t;
}
