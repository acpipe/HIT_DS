#ifndef _LISTTREE_H_HUMING_INCLUDE_
#define _LISTTREE_H_HUMING_INCLUDE_
#include <iostream>
#include<cstring>
using namespace std;
template <class T>
class Listtree;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL),ltag(0),rtag(0) {};
    ~node()
    {
        delete this;
    };
    T return_data()
    {
        return data;
    };
    node<T>* return_lc()
    {
        return lchild;
    };
    node<T>* return_rc()
    {
        return rchild;
    };
    friend class Listtree<T>;
private:
    T data;
    node<T> *lchild,*rchild;
    int ltag,rtag;
};//节点类
template <class T>
class Listtree
{
public:
    node<T>* return_hd()
    {
        return head;
    };
    node<T>* return_rt()
    {
        return root;
    };
    void Create();//先序建立普通二叉树
    void to_list();//线索化
    void pre_order();//遍历
    void In_order();
    void Post_order();
    node<T>* InNext(node<T>* p);
    node<T>* parent(node<T>* t);
private:
    node<T> *root,*pre,*head;
    void To_list_tree(node<T>* p,node<T>* &pre);
    node<T>* Insert();
};
template <class T>
node<T>* Listtree<T>::parent(node<T>* t)
{
    node<T>* p;
    if(t==root) return NULL;//没有父节点
    else
    {
        for(p=t; p->ltag==1; p=p->lchild);
        if(p->lchild!=head)
            for(p=p->lchild; p!=head&&p->lchild!=t&&p->rchild!=t; p=p->rchild);
        if((p==head||p->lchild==head))
        {
            for(p=t; p->rtag==1; p=p->rchild);
            for(p=p->rchild; p!=head&&p->lchild!=t&&p->rchild!=t; p=p->lchild);
        }
    }
    return p;
}
template <class T>
void Listtree<T>::Post_order()
{
    node<T> *t=root,*p;
    while(t->ltag==1||t->rtag==1)//一直找到后序遍历的第一个节点位置
    {
        if(t->ltag==1) t=t->lchild;
        else if(t->rtag==1) t=t->rchild;
        else;
    }
    cout << t->data;
    while((p=parent(t))!=NULL)
    {
        if((p->rchild==t||p->rtag==0))
            //如果当前节点是父节点的右儿子，或者虽然是左儿子，但是这个父节点没有右儿子
            t=p;
        else//如果不是的话在右子树上重复上面的操作(刚才是找左子树上面的)，找出右子树上面的后序遍历第一个节点
        {
            t=p->rchild;
                while(t->ltag==1||t->rtag==1)//一直找到右子树后序遍历的第一个节点位置
                {
                    if(t->ltag==1) t=t->lchild;
                    else if(t->rtag==1) t=t->rchild;
                    else;
                }
        }
        cout << t->data;
    }
}
template <class T>
void Listtree<T>::pre_order()
{
    node<T>* t=root;
    while(t!=NULL&&t!=head)
    {
//            和二叉树的先序遍历类似：
//    循环到树空和再次访问到head节点
        cout << t->data;
        if(t->ltag==1) t=t->lchild;
        else if(t->rtag==1)t=t->rchild;
//        有左右儿子
        else
        {
//            没有左右儿子，那么沿着中序线索树找到第一个有右儿子的节点，就是当前节点的先序遍历的后继节点
            while(t->rtag==0&&t!=head)
            {
                t=t->rchild;
            }
            if(t!=head) t=t->rchild;
            //注意判断一下结束的标识是t再一次走到head节点（见图中）
        }
    }
}
template<class T>
node<T>* Listtree<T>::Insert()
{
    T ch;
    node<T> *t;
    cin >> ch;
    if(ch=='#')  t=NULL;
    else
    {
        t=new node<T>;
        t->data=ch;
        t->lchild=Insert();
        t->rchild=Insert();
    }
    return t;
}
template <class T>
void Listtree<T>::Create()
{
    root=Insert();
    head= new node<T>;
    if(root!=NULL)
    {
        head->lchild =root;
        head->ltag =1;
    }
    else
    {
        head->lchild=head;
        head->ltag =0;
    }
    head->rchild =head;
    head->rtag =1;
};
template <class T>
void Listtree<T>::to_list()
{
    pre=head;
    To_list_tree(root,pre);
    pre->rchild=head;
    pre->rtag=0;
}
template <class T>
void Listtree<T>::To_list_tree(node<T>* p,node<T>* &pre)//将普通的二叉树转变为线索二叉树
{
    if(p)
    {
        //p 非空时，当前访问的结点是p
        To_list_tree(p->lchild,pre); //左子树线索化
        p->ltag=( p->lchild )? 1:0; //左(右)孩子非空
        p->rtag=( p->rchild )? 1:0; //时,标志1,否: 0
        if (pre)   //若*p 的前驱*pre 存在
        {
            if ( pre->rtag ==0) // *p的前驱右标志为线索
                pre->rchild=p; // 令*pre 的右线索指向中序后继
            if ( p->ltag ==0) // *p的左标志为线索
                p->lchild=pre; //令*p的左线索指向中序前驱
        }
        pre = p; // 令pre 是下一个访问的中序前驱
        To_list_tree(p->rchild,pre); //右子树线索化
    }
}
template<class T>
node<T>* Listtree<T>::InNext(node<T>* p)
{
    node<T>* Q ;
    Q=p->rchild ;
    if (p->rtag ==1 )
        while( Q->ltag == 1 )
            Q = Q->lchild ;
    return (Q);
}
template <class T>
void Listtree<T>::In_order()
{
    node<T>* tmp;
    tmp=head;
    do
    {
        tmp = InNext ( tmp ) ;
        if (tmp!=head)
            cout << tmp->data;
    }
    while (tmp !=head) ;
}
#endif
