//file :threemat.h
#ifndef _THREEMAT_H_HUMING_INCLUDE_
#define _THREEMAT_H_HUMING_INCLUDE_
#include<iostream>
using namespace std;
#define maxlen 100
template <class T>
class  triple
{
public:
    int i,j;
    T v;
};
template <class T>
class TSMatrix
{
public:
    void turn();
    void show();
    triple<T> data[maxlen+1];
    int row,col,unzero;
};
template <class T>
void TSMatrix<T>::turn()
{
    int temp;
    for(int l=0; l<unzero; l++)
    {
        temp=data[l].i;
        data[l].i=data[l].j;
        data[l].j=temp;
    }
}

template <class T>
void TSMatrix<T>::show()
{
    int temp;
    T t;
    for(int m=0; m<unzero-1; m++)
    {
        for(int n=m+1; n<unzero; n++)
        {
            if(data[m].i>data[n].i)
            {
                temp=data[m].i;
                data[m].i=data[n].i;
                data[n].i=temp;
                temp=data[m].j;
                data[m].j=data[n].j;
                data[n].j=temp;
                  t=data[m].v;
                    data[m].v=data[n].v;
                    data[n].v=t;
            }
            else  if(data[m].i==data[n].i)
            {
                if(data[m].j>data[n].j)
                {
                    temp=data[m].i;
                    data[m].i=data[n].i;
                    data[n].i=temp;
                    temp=data[m].j;
                    data[m].j=data[n].j;
                    data[n].j=temp;
                     t=data[m].v;
                    data[m].v=data[n].v;
                    data[n].v=t;
                }
            }
            else ;
        }
    }//木有研究什么算法，就是把转置之后按行列的从小到大排序，然后扫描输出，很傻逼的代码，呜呜呜！
    int x=0;
    for(int m=0; m<col; m++)
    {
        for(int n=0; n<row; n++)
            if(data[x].i==m&&data[x].j==n)
            {
                cout << data[x].v  << " ";
                x++;
            }
            else   cout << 0 << " ";
        cout << endl;
    }
}
#endif
