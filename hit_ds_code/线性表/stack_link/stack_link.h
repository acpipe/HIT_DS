//file:stack_link.h
#ifndef STACK_LINK_H_INCLUDED
#define STACK_LINK_H_INCLUDED
template <class T>
class node
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
template <class T>
class stack
{
public:
    stack();
    bool empty();
    void push(T x);
    void pop();
    T top();
private:
    node<T>* L;
};
template <class T>
stack<T>::stack()
{
    L=new node<T>;
    L->next=NULL;
};
template <class T>
bool stack<T>::empty()
{
      if(L->next==NULL)return true;
      else return false;
}
template <class T>
void stack<T>::push(T x)
{
   node<T>* s=new node<T>;
   s->data=x;
   s->next=L->next;
   L->next=s;
}
template <class T>
void stack<T>::pop()
{
  node<T>* s=L->next;
  if(!empty())
    {
       L->next=s->next;
       delete s;
    }
}
template <class T>
T stack<T>::top()
{
  if(L->next) return L->next->data;
  else ;
}
#endif

