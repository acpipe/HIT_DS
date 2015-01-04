//file:queue.h
#ifndef _Queue_H_INCLUDE_
#define _Queue_H_INCLUDE_
#define N 10002
#include<cstdio>
template <class T>
class Queue
{
public:
    Queue():frount(1),rear(1) {}
    void push(T t);
    void pop();
    T front();
    bool empty();
private:
    int frount,rear;
    T Q[N];
};
template <class T>
bool Queue<T>::empty()
{
   if(frount==rear) return true;
   else return false;
}
template <class T>
T Queue<T>::front()
{
    if (!empty())    return Q[frount];
    else   {printf("Empty!\n");}
}
template <class T>
void Queue<T>::pop()
{
   if(!empty())  frount++;
    else printf("Empty!\n");
}
template <class T>
void Queue<T>::push(T t)
{
   Q[rear]=t;
   rear++;
}
#endif // _STACK_H_INCLUDE_
