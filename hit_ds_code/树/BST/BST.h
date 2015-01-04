//file：BST.h
#ifndef _BST_H_HITHUMING_INCLUDE_
#define _BST_H_HITHUMING_INCLUDE_
#include <iostream>
#include<cstring>
using namespace std;
// 添加BST模板的前置声明，否则node中无法声明BST<T>为友元类
template <class T>
class BST;
template<class T>
class node
{
public:
    node():lchild(NULL),rchild(NULL) {};
    node(T p)
    {
        this->data=p;
        lchild=NULL;
        rchild=NULL;
    };
    ~node()
    {
        delete this;
    };
    T return_data()
    {
        return data;
    };
    // 这里不需要判断，因为lchild和rchild都有合理默认值的(构造函数)
    node<T>* return_lc()
    {
        return lchild;
    };
    node<T>* return_rc()
    {
        return rchild;
    };
    //  friend class BST;//声明啦友元类，为什么下面还不能访问？
    // 那是因为仅仅写BST还不够
    friend class BST<T>;
private:
    T data;
    // 这里又错了，这样写rchild不是指针，而是node<T>类型
    // node<T>* lchild,rchild;
    node<T> *lchild, *rchild;
};
template <class T>
class BST
{
public:
    void CreateBST();//返回父节点的指针
    void InsertBST(T key,node<T>* &t);//插入的类型，还有插入的位置
    node<T>* SearchBST(T key,node<T>* F);//查找
    void Delete(T k,node<T>* &t);
    void in_order(node<T>* t);
    T de_lete(node<T>* &t);
    node<T>* return_rt()
    {
        return root;
    }
private:
    node<T>* root;
};
template <class T>
void BST<T>::CreateBST()
{
    node<T> *F=NULL;
    T m;
    while(cin >> m&&m!=0)
    {
        InsertBST(m,F);
    }//利用不断的插入来建立
    root=F;
}
template <class T>
void BST<T>::InsertBST(T key,node<T>* &t)
//注意：这里是修改内容，所以要传地址，而遍历那些只用访问就行！所以不用传地址
//还是鸣神厉害，一眼就帮我看出来啦！
{
    // 这里t是指针，怎么能.呢？
    if(t==NULL)
    {
        t=new node<T>;
        t->data=key;
        t->lchild=NULL;
        t->rchild=NULL;
    }
    else if (key < t->data)
        InsertBST(key,t->lchild);
    else if (key > t->data)
        InsertBST(key,t->rchild);
    else ;
    //这个过程其实是在查找，插入的一定是查找失败的最后一个节点的左儿子或者右儿子
}
template <class T>
node<T>* BST<T>::SearchBST(T k,node<T>* F)
{
    node<T>* p =F;
    if (p== NULL || k == p->data)  //递归终止条件
        return p;
    if ( k < p->data)
        return (SearchBST (k,p->lchild)); // 查找左子树
    else
        return (SearchBST(k,p->rchild)) ; // 查找右子树
}
template <class T>
void BST<T>::in_order(node<T>* t)
{
    if(t!=NULL)
    {
        in_order(t->lchild);
        cout << t->data << " ";
        in_order(t->rchild);
    }
}
template <class T>
T BST<T>::de_lete(node<T>* &t)
{
    T temp ;
    node<T> *p ;
    if ( t->lchild == NULL )
    {
        p = t ;
        temp = t->data ;
        t = t->rchild ;
        delete p ;
        return temp ;
    }
    else
        return(de_lete(t->lchild));
}
template <class T>
void BST<T>::Delete(T k,node<T>* &t)
{
    if(t!=NULL)
    {
        if(k<t->data)  Delete(k,t->lchild);
        else if(k>t->data) Delete(k,t->rchild);
        else
        {
            if(t->lchild==NULL) t=t->rchild;
            else if(t->rchild==NULL) t=t->lchild;
            else
            {
                t->data=de_lete(t->rchild);
            }
        }
    }
}
//有点复杂哈，我是晕啦~
//1. 若结点p是叶子，则直接删除结点p；
//2. 若结点p只有左子树，则只需重接p的左子树；
//若结点p只有右子树，则只需重接p的右子树；
//3. 若结点p的左右子树均不空，则
//3.1 查找结点p的右子树上的最左下结点s及其双亲结点par；
//3.2 将结点s数据域替换到被删结点p的数据域；
//3.3 若结点p的右孩子无左子树，
//则将s的右子树接到par的右子树上；
//否则，将s的右子树接到结点par的左子树上；
//3.4 删除结点s；
#endif




