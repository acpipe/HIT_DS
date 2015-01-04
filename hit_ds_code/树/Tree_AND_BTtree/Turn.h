#ifndef _PARENTS_H_INCLUDE_
#define _PARENTS_H_INCLUDE_
#include<iostream>
#define maxlen 100
using namespace std;
template <class T>
class BTtree<T>;
template <class T>
class head;
template <class T>
class Tree;
template <class T>
class BTnode
{
public:
    BTnode():lchild(NULL),brother(NULL) {};
    ~BTnode()
    {
        delete lchild;
        delete brother;
    };
    friend class BTtree<T>;
    friend class tree<T>;
private:
    T data;
    BTnode<T> *lchild,*brother;
};
template <class T>
class BTtree
{
public:
//    void Create();
//    node<T>* return_rt();
//    void pre_order(node<T> *P);
//    void post_order(node <T>*p);
//    void level_order(node<T>*p);
private:
    BTnode<T>* root;
//    BTnode<T>* Insert();
};
template <class T>
class node
{
public:
    node():next(NULL) {};
    ~node()
    {
        delete next;
    };
    friend class head<T>;
    friend class Tree<T>;
private:
    int v;
    node<T> *next;
};//节点
template <class T>
class head
{
public:
    friend class Tree<T>;
    head():firstchild(NULL),num(0) {};
    ~head()
    {
        delete firstchild;
    };
private:
    T data;
    node<T>* firstchild;
    int num;//儿子的个数
};//表头
template <class T>
class Tree
{
public:
    Tree():n(0) {};
    void Create();
    void tree_to_bt();
private:
    head<T> nodes[maxlen];
    int n;//顶点数和边树
};//树
template <class T>
void Tree<T>::Create()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int m;
        cin >> nodes[i].data;
        while(cin >> m&&m!=0)
        {
            node<T> *s=new node<T>;
            s->v=m;
            s->next=nodes[i].firstchild;
            nodes[i].firstchild=s;
            nodes[i].num++;
        }//注意输入节点的时候右边先输入，这样建立的第一个就是第一个左儿子
    }
    node<T> *l;
    for(int i=1; i<=n; i++)
    {
        l=nodes[i].firstchild;
        cout << nodes[i].data;
        while(l!=NULL)
        {
            cout << "->" << nodes[l->v].data;
            l=l->next;
        }
        cout << "->^" << endl;
    }
}
template <class T>
BTnode<T>* Tree<T>::tree_to_bt()
{
    BTnode<T>* t=new BTnode<T>;
    t->data=nodes[1].data;
    for(int i=1; i<=n; i++)
    {
        BTnode<T>* x=new BTnode<T>;
        if(nodes[i].num > 1)
        {
            node<T> *m;
            m=nodes[i].firstchild->next;
//            while(m!=NULL)
//            {
//                m=m->next;
//                t->brother->data=nodes[m->v];
//                t=t->brother;
//            }
            x->data=nodes[m->v].data;
            t->lchild=x;
            while(m!=NULL)
            {

                m=m->next
            }

        }
          else if(nodes[i].num==1)
        {
//            t->lchild->data=

        }
    }
}
#endif
