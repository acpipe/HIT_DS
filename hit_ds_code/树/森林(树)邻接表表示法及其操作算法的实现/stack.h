#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
template<typename T>
class stack
{
public:
    stack();
    ~stack();
    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
private:
    struct node
    {
        T data;
        node *next;
    };
    typedef node * STACK;
    STACK S;
};
template <typename T>
stack<T>::stack()
{
    S=new node;
    S->next=NULL;
}
template <typename T>
stack<T>::~stack()
{
    STACK P=S,temp;
    while(P!=NULL)
    {
        temp=P->next;
        delete P;
        P=temp;
    }
}
template <typename T>
void stack<T>::push(T value)
{
    STACK tmp;
    tmp=new node;
    tmp->data=value;
    tmp->next=S->next;
    S->next=tmp;
}
template <typename T>
void stack<T>::pop()
{
    if(!empty())
    {
        STACK tmp;
        tmp=S->next;
        S->next=tmp->next;
        delete tmp;
    }
    else return;
}
template <typename T>
T stack<T>::top()
{
    if(!empty())
    {
        return S->next->data;
    }
}
template <typename T>
bool stack<T>::empty()
{
    if(S->next==NULL)
        return true;
    else return false;
}
template <typename T>
int stack<T>::size()
{
    int count=0;
    STACK tmp=S->next;
    while(tmp!=NULL)
    {
        count++;
        tmp=tmp->next;
    }
    return count;
}

#endif // STACK_H_INCLUDED
