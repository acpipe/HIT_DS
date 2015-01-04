//file:"array_list.h"
#ifndef _ARRAYLIST_H_INCLUDE_
#define _ARRAYLIST_H_INCLUDE_
#include<cstdio>
#define maxlen 1000
template<typename Type>
class  List
{
public:
    List():list_last(0) {}//构造函数，线性表的开始长度为0
    void Insert(int p,Type x)
    {
        if(list_last>=maxlen-1)  printf("list is full!\n");
        else if((p>list_last+1)||(p<1))
        {
           printf("position is not exist!\n");
        }
        else
        {
            for(int i=list_last; i>=p; i--)
            {
                element[i+1]=element[i];
            }
            element[p]=x;
            list_last++;
        }
    }
    void Delete(int p)
    {
      if((p>list_last)||(p<1))   printf("position is not exist!\n");
      else
        {
            list_last--;
            for(int i=p;i<=list_last;i++)  element[i]=element[i+1];
        }
    }
    int Locate(Type x)
    {
       for(int i=1;i<=list_last;i++)
           if(element[i]==x)   return i;
       return (list_last+1);
    }
    Type Retrieve(int p)
    {
      if(p>list_last)  printf("position is not exist!\n");
      else   return element[p];
    }
    Type Previous(int p)
    {
       if((p<=1)||(p>list_last))  printf("Previous element is not exist!\n");
       else return element[p-1];
    }
    Type Next(int p)
    {
      if((p<1)||(p>=list_last))  printf("Next element is not exist!\n");
      else return element[p+1];
    }
    int End()
    {
       return (list_last+1);
    }
private:
    int list_last;
    Type element[maxlen];
};
#endif
