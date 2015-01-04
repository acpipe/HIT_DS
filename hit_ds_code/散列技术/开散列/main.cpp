#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define B 10000
using namespace std;
struct records
{
    int key;
    char other;
};
struct celltype
{
    records data;
    celltype *next;
};
typedef celltype *cellptr;
typedef cellptr HASH[B];
inline int Hash(int k)
{
    return k%B;
}
cellptr Search(int k, HASH F);
void Delete(int k,HASH F);
void Insert(records R, HASH F);
void Init(HASH info);
int main()
{
    bool f=true;
    int n;
    records r;
    HASH info;
    Init(info);
    printf("1---Insert\n2---Delete\n3---Search\n5---Return\n");
    while(f&&cin >> n)
    {
        switch(n)
        {
        case 1:
            cin >> r.key;
            Insert(r,info);
            break;
        case 2:
            cin >> r.key;
            Delete(r.key,info);
            break;
        case 3:
            cin >> r.key;
            cout << Search(r.key,info)->data.key<< endl;
            break;
        default:
            f=false;
            break;
        }
    }
    return 0;
}
void Init(HASH info)
{
    for(int i=0; i<B; i++)
        info[i]=NULL;
}
cellptr Search(int k, HASH F)
{
    cellptr p=F[Hash(k)];
    while(p!=NULL)
    {
        if(p->data.key==k)
            return p;
        else p=p->next;//木有找到
    }
    return p;
}
void Insert(records R, HASH F)
{
    if(Search(R.key,F)==NULL)
    {
        int locate=Hash(R.key);
        cellptr p=F[locate];
        F[locate]=new celltype;
        F[locate]->data=R;
        F[locate]->next=p;
    }
}
void Delete(int k,HASH F)
{
    int locate=Hash(k);
    cellptr p=F[locate],temp;
    if(p!=NULL)
    {
        if(p->data.key==k)
        {
            F[locate]=p->next;
            delete p;
        }
        else
        {
            temp=F[locate];
            while(temp->next!=NULL)
            {
                if(temp->next->data.key==k)
                {
                    p=temp->next;
                    temp->next=p->next;
                    delete p;
                }
                else temp=temp->next;
            }
        }
    }
}

