//file :list_link.h
#ifndef _LIST_LINK_H_HUMING_INCLUDE_
#define _LIST_LINK_H_HUMING_INCLUDE_
#include<cstdio>
template <class T>
class  node
{
public:
    T data;
    node<T>* next;
    node():next(NULL) {}; //No-arg constructor
    node(T p)//Constructor
    {
        this->data=p;//"this" means "class node"
        next=NULL;
    };
};
//node definatio
template <class T>
class link
{
public :
    link();
    void Insert(T x,node<T>* p);
    void Delete(node<T>* p);
    node<T>* Locate(T x);
    node<T>* First();
    T Retrieve(node<T>* p);
    node<T>* Previous(node<T>* p);
    node<T>* Next(node<T>* p);
    node<T>* End();
    void Swap(node<T>* p,node<T>*q);
private :
    node<T>* L;
};
//link defination
template <class T>
link<T>::link()
{
    L=new node<T>;
    L->next=NULL;
};
template <class T>
node<T>* link<T>::First()
{
  return L;
}
template <class T>
void link<T>::Insert(T x,node<T>* p)
{
    node<T>* q=new node<T>;
    q->data=x;
    q->next=p->next;
    p->next=q;
}
template <class T>
void link<T>::Delete(node<T>* p)//delete p next node<T>* data
{
    node<T>* q;
    if(p->next!=NULL)
        {
           q=p->next;
           p->next=p->next;
        }
        delete q;
}
template <class T>
node<T>* link<T>::Locate(T x)
{
   node<T>* p;
   p=L;
   while(p->next!=NULL)
    {
      if(p->next->data==x)  return p;
     else p=p->next;
    }
    return p;
}
template <class T>
T link<T>::Retrieve(node<T>* p)
{
  return (p->next->data);//show p node<T>* next element!,注意啊，不然实现的时候会抽的！
}
template <class T>
node<T>* link<T>::Previous(node<T>* p)
{
   node<T>* q;
   if(p=L->next)
       return NULL;
    else
        {
           q=L;
           while(q->next!=p) q=q->next;
           return q;//q->next==p
        }
}
template <class T>
node<T>* link<T>::Next(node<T>* p)
{
  if(p->next==NULL)  return NULL;
  else  return p->next;
}
template <class T>
node<T>*  link<T>::End()
{
  node<T>*  p;
  p=L;
  while(p->next!=NULL)p=p->next;
  return p;
}
template <class T>
void link<T>::Swap(node<T>* p,node<T>*q)
{
    T temp;
    temp=p->data;
    p->data=q->data;
    q->data=temp;
}
#endif

























