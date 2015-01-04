//#ifndef _LIST_LINK_H_HUMING_INCLUDE_
//#define _LIST_LINK_H_HUMING_INCLUDE_
//#define maxlen 100
//template <class T>
//class node
//{
//public:
//    T data;
//    int next;
//};
//template <class T>
//class link
//{
//public :
//    void link();
//    int GetNode();
//    void FreeNode(int q);
//    void Insert(T x, int p);
//    void Delete(int  p);
//private :
//    node<T> space[maxlen];
//    int avail;
//};
//template <class T>
//void link<T>::link()
//{
//    for(int j=0; j<maxlen-1; j++)
//        space[j].next=j+1;
//    space[j]=-1;//最后一个为空
//    avail=0;//表示线性表
//}
//template <class T>
//int link<T>::GetNode() //q=new spacestr;
//{
//    int p;
//    if (space[avail].next ==-1)
//        p=-1;
//    else
//    {
//        p= space[avail].next ;
//        space[avail].next =space[p].next ;
//    }
//    return p;
//}
//template <class T>
//void link<T>::FreeNode(int  q) //delete q;
//{
//    space[q].next =space[avail].next ;
//    space[avail].next=q ;
//} /* 放回池中*/
//template <class T>
//void link<T>::Insert(T x, int p)
//{
//    int q ;
//    q=GetNode( ) ;
//    space[q].data = x ;
//    space[q].next=space[p].next ;
//    space[p].next = q ;
//}
//template <class T>
//void link<T>::Delete(int  p)
//{
//    int  q ;
//    if (space[p].next != -1 )
//    {
//        q=space[p].next ;
//        space[p].next = space[q].next ;
//        FreeNode(q) ;
//    }
//}
//#endif
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define maxlength 10000
template<typename T>
class list
{
public:
    list();
    ~list(){};//???
    void Insert(int position,T value);
    void Delete(int position);
    void Swap(int x,int y);
    int Size();
    int Locate(T value);
    int Previous(int position);
    int Next(int position);
    int First();
    int End();
    T Retrieve(int position);
    bool Empty();
    bool Judge(int position,bool sign);
private:
    int GetNode();
    void FreeNode(int position);
    bool Full();
    int Unused();
    struct spacestr
    {
        T data;
        int next;
    };
    spacestr *SPACE;
    int avail;
    int head;//表头结点的编号
};
//可用空间初始化
template<typename T>
list<T>::list()
{
    SPACE=new spacestr[maxlength];
    int i;
    for(i=0; i<maxlength-1; i++)
        SPACE[i].next=i+1;
    SPACE[i].next=-1;
    avail=0;
    head=GetNode();
    SPACE[head].next=-1;
}
////析构函数
//template<typename T>
//list<T>::~list()
//{
//    delete []SPACE;
//}
//可用空间的分配操作
//返回可用节点的编号
//没有可用的结点返回-1
//编号为avail(0)的结点始终不存储元素
template<typename T>
int list<T>::GetNode()
{
    if(SPACE[avail].next==-1)
        return -1;
    else
    {
        int p=SPACE[avail].next;
        SPACE[avail].next=SPACE[p].next;
        return p;
    }
}
//可用空间的回收操作
template<typename T>
void list<T>::FreeNode(int position)
{
    SPACE[position].next=SPACE[avail].next;
    SPACE[avail].next=position;
}
//将元素插入到p位置上
template<typename T>
void list<T>::Insert(int position,T value)
{
    if(Judge(position,true))
    {
        int p=head,temp;
        position--;
        while(position--)
          p=SPACE[p].next;
        temp=GetNode();
        SPACE[temp].data=value;
        SPACE[temp].next=SPACE[p].next;
        SPACE[p].next=temp;
    }
    else return;
}
//删除p位置上的元素
template<typename T>
void list<T>::Delete(int position)
{
    if(Judge(position,false))
    {
        int p=head,temp;
        position--;
        while(position--)
          p=SPACE[p].next;
        temp=SPACE[p].next;
        SPACE[p].next=SPACE[temp].next;
        FreeNode(temp);
    }
    else return;
}
template<typename T>
bool list<T>::Empty()
{
    if(SPACE[head].next==-1)
        return true;
    else return false;
}
template<typename T>
bool list<T>::Full()
{
    if(SPACE[avail].next==-1)
        return true;
    else return false;
}
//返回第一个元素的位置编号
//在执行插入操作时，使用First()作为位置参数，表示将元素插入到第一个位置
template<typename T>
int list<T>::First()
{
    return 1;
}
//返回最后一个元素后面一个位置的位置编号
//在执行插入操作时，使用End()作为位置参数，表示将元素插入到表尾
template<typename T>
int list<T>::End()
{
    if(Size()<maxlength-2)
      return Size()+1;
    else return -1;
}
//返回线性表中元素的个数
template<typename T>
int list<T>::Size()
{
    if(!Empty())
    {
        int count=0;
        int p=SPACE[head].next;
        while(p!=-1)
        {
            p=SPACE[p].next;
            count++;
        }
        return count;
    }
    else return 0;

}
//返回线性表中可利用的剩余空间的个数
template<typename T>
int list<T>::Unused()
{
    return maxlength-2-Size();
}
template<typename T>
T list<T>::Retrieve(int position)
{
    if(Judge(position,false))
    {
        int p=head;
        while(position--)
        {
            p=SPACE[p].next;
        }
        return SPACE[p].data;
    }
}
//定位
template<typename T>
int list<T>::Locate(T value)
{
    if(!Empty())
    {
        int p=SPACE[head].next;
        int count=1;
        while(p!=-1&&SPACE[p].data!=value)
        {
            p=SPACE[p].next;
            count++;
        }
        if(p==-1) return -1;
        return count;
    }
    else return -1;
}
template<typename T>
int list<T>::Previous(int position)
{
    if(Judge(position,false))
        return position-1;
    else return -1;
}
template<typename T>
int list<T>::Next(int position)
{
    if(Judge(position,false))
        return position+1;
    else return -1;
}
//判断位置position的合理性
//对于空表删除没有合理的位置
//对于空表插入position只能是1
template<typename T>
bool list<T>::Judge(int position,bool sign)
{
    if(sign)
    {
        if(position>=1&&position<=Size()+1)
            return true;
        else return false;
    }
    else
    {
        if(position>=1&&position<=Size())
            return true;
        else return false;
    }
}
//交换两个结点的元素，其中一个结点的编号为x另一个编号为y  AC
template<typename T>
void list<T>::Swap(int x,int y)
{
    int p=head;
    int q=head;
    while(x--)
     p=SPACE[p].next;
    while(y--)
     q=SPACE[q].next;
    T temp;
    temp=SPACE[p].data;
    SPACE[p].data=SPACE[q].data;
    SPACE[q].data=temp;
}
#endif // LIST_H_INCLUDED

