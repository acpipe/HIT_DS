#ifndef _QUEUE_LINK_H_HUMING_INCLUDE_
#define _QUEUE_LINK_H_HUMING_INCLUDE_
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
//node defination
template <class T>
class queue
{
public:
    queue();
    ~queue();// to avoid memory leak, a destructor is needed.
    bool empty();
    void pop();
    void push(T x);
    T front();
private:
    node<T> *head,*tail;
};
template <class T>
void queue<T>::push(T x)
{
    node<T> *q=new node<T>;
    q->data=x;
    q->next=NULL;
    tail->next=q;
    tail=q;
}
template <class T>
queue<T>::queue()
{
    head=new node<T>;
    head->next=NULL;
    tail=head;
}
template <class T>
bool queue<T>::empty()
{
    return (tail==head);//这个写法简单！
}
template <class T>
void queue<T>::pop()
{
    if(!empty())
    {
        node<T>* x;
        x=head->next;
        head->next=x->next;
        if(x->next==NULL) tail=head;
        delete x;
    }
}
template <class T>
T queue<T>::front()
{
    return (head->next->data);
}//不用判断空，调用之前写一下判断一下就行
template <class T>
queue<T>::~queue()//delete all nodes including "head".
{
    node<T>* x;
	while(head)
	{
	        x=head;
	        head=head->next;
	        delete x;
	}
}
#endif
