#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
template <typename T>
class queue
{
public:
    queue();
    ~queue();
    void Enqueue(T value);
    void Dequeue();
    T Front();
    bool Empty();
private:
    struct node
    {
        T data;
        node *next;
    };
    typedef node * QUEUE;
    QUEUE rear,front;
};
template <typename T>
queue<T>::queue()
{
    front=new node;
    front->next=NULL;
    rear=front;
}
template <typename T>
queue<T>::~queue()
{
    QUEUE P=front,temp;
    while(P!=NULL)
    {
        temp=P->next;
        delete P;
        P=temp;
    }
}
template <typename T>
void queue<T>::Enqueue(T value)
{
    rear->next=new node;
    rear=rear->next;
    rear->data=value;
    rear->next=NULL;
}
template <typename T>
void queue<T>::Dequeue()
{
    if(!Empty())
    {
        QUEUE  tmp;
        tmp=front->next;
        front->next=tmp->next;
        delete tmp;
        if(front->next==NULL) rear=front;
    }
}
template <typename T>
T queue<T>::Front()
{
    if(!Empty())
        return front->next->data;
}
template <typename T>
bool queue<T>::Empty()
{
    if(front==rear)
        return true;
    else return false;
}
#endif // QUEUE_H_INCLUDED
