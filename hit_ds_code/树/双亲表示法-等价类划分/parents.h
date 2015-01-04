#ifndef _PARENTS_H_HITHUMING_INCLUDE_
#define _PARENTS_H_HITHUMING_INCLUDE_
#include<iostream>
#include<cstring>
#define maxlen 100
using namespace std;
template <class T>
class MFSET;
template <class T>
class node
{
public:
    friend class MFSET<T>;
private:
    T data;
    int father;
    int count;
};
template <class T>
class MFSET
{
public:
    void Create();
    int Find(int x);
    void Union(int A,int B);
    void Equivalence();
    void Print();
private:
    node<T> element[maxlen];
    int size;
};
template <class T>
void MFSET<T>::Print()
{
    bool a[maxlen];
    memset(a,true,sizeof(a));
    for(int i=1; i<=size;i++)
    {
        if(a[i]==false) continue;
        cout << "(";
        int temp=Find(i);
        cout << element[i].data;
        for(int j=i+1;j<=size; j++)
            if(Find(j)==temp&&a[j]==true)
            {
                cout <<  ","<<element[j].data;
                a[j]=false;
            }
            cout << ")" << endl;
    }
}
template <class T>
void MFSET<T>::Union(int A,int B)
{
    if(element[A].count > element[B].count)
    {
        element[B].father = A;
        element[A].count += element[B].count;
    }
    else
    {
        element[A].father = B;
        element[B].count += element[A].count;
    }
}
template <class T>
int MFSET<T>::Find(int x)
{
    int temp=x;
    while(element[temp].father!=0)
    {
        temp=element[temp].father;
    }
    return temp;
}
template <class T>
void  MFSET<T>::Create()
{
    cin >> size;
    for(int i=1; i<=size; i++)
    {
        element[i].data=i;
        element[i].father=0;
        element[i].count=1;
    }
}
template <class T>
void  MFSET<T>::Equivalence ()
{
    int i,j,k,m;

    while( cin>>i>>j&&!(i==0&&j==0))
    {
        k=Find(i);
        m=Find(j);
        if(k!=m)
            Union(i,j);
    }
}
#endif
