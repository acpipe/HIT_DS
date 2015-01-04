//file :HEAPSORT.h
#ifndef _HEAPSORT_H_HUMING_INCLUDE_
#define _HEAPSORT_H_HUMING_INCLUDE_
#include<iostream>
#define maxlen 10000
using namespace std;
template <class T>
class array_BTtree
{
public:
    void setup(T a[],int n);
    void order();
    void swap(int i,int j);
    int  size();
    void heapsort();
    T see(int i);
    void pushdown(int first,int last);
private :
    T data[maxlen];
    int MAX;
};
template <class T>
void array_BTtree<T>::heapsort()
{
    int i;
    for(i=size()/2; i>=1; i--)
        pushdown(i,size());
//     整理堆，把最大的压在下面，小的不断向上
    for(i=size(); i>=2; i--)
    {
        swap(1,i);
        pushdown(1,i-1);
    }//最小的在最上面，然后和最后一个交换就可以得到一个降序的序列
}
template<class T>
void array_BTtree<T>::pushdown(int first,int last)
{
    int r=first;
    while(r<=last/2)
    {
        if(last/2==r&&last%2==0)//只有左儿子
        {
            if(see(r)>see(2*r))
                swap(r,2*r);
            r=last;
        }
        else if(see(r)>see(2*r)&&see(2*r)<=see(2*r+1))
        {
            swap(r,2*r);
            r*=2;
        }
        else if(see(r)>see(2*r)&&see(2*r+1)<see(2*r))
        {
            swap(r,2*r+1);
            r=2*r+1;
        }
       //  根节点与其中较小者交换（若、右儿子相等，则与其左儿子交换）
        else  r=last;
    }
}
template <class T>
void  array_BTtree<T>::swap(int i,int j)
{
    T temp;
    temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}
template <class T>
void array_BTtree<T>::setup(T a[],int n)
{
    for(int i=1; i<=n; i++)
        data[i]=a[i];
    MAX=n;
}
template <class T>
void array_BTtree<T>::order()
{
    for(int i=1; i<=MAX; i++)
        cout << data[i]<< " ";
}
template <class T>
int array_BTtree<T>::size()
{
    return MAX;
}
template<class T>
T array_BTtree<T>::see(int i)
{
    return data[i];
}
#endif
