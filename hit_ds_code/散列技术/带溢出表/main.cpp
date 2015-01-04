#include <iostream>
#include <cstdio>
#include <cmath>
#define empty -999999
#define B 10000
struct records
{
    int key;
    char str[20];
};
struct celltype
{
    records data;
    celltype *next;
};
typedef celltype HASH[B];
typedef celltype * cellptr;
HASH H;
void Init();
int Hash(int key);
cellptr Search(int key);
void Insert(records R);
void Delete(int key);
int Prime(int n);
void Print();
using namespace std;
int main()
{
    int n,tag=1;
    records R;
    Init();
    printf("1---Insert\n2---Delete\n3---Search\n4---Print\n\n");
    while(tag&&scanf(" %d",&n)!=EOF)
    {
        switch(n)
        {
        case 1:
            scanf(" %d %s",&R.key,R.str);
            Insert(R);
            break;
        case 2:
            scanf(" %d",&R.key);
            Delete(R.key);
            break;
        case 3:
            scanf(" %d",&R.key);
            printf("%s\n",(Search(R.key)!=NULL)?Search(R.key)->data.str:"empty!!!");
            break;
        case 4:
            Print();
            break;
        default:
            tag=0;
            break;
        }
    }
    return 0;
}
void Init()
{
    for(int i=0; i<B; i++)
    {
        H[i].next=NULL;
        H[i].data.key=empty;
    }
}
int Prime(int n)
{
    bool s=false;
    for(int i=n-1; i>=2&&!s; i--)
    {
        s=true;
        for(int j=2; j<=sqrt(i)&&s; j++)
        {
            s=(i%j==0)?false:true;
        }
        if(s)
            return i;
    }
}
void Print()
{
    for(int i=0; i<B; i++)
    {
        if(H[i].data.key!=empty)
        {
            printf("Í°ºÅ%d:%s%c",i,H[i].data.str,(H[i].next==NULL)?'\n':' ');
            for(cellptr p=H[i].next; p!=NULL; p=p->next)
                printf("----%s%c",p->data.str,(p->next==NULL)?'\n':' ');
        }
    }
}
cellptr Search(int key)
{
    if(H[Hash(key)].data.key==key) return (H+Hash(key));
    else if(H[Hash(key)].data.key!=empty)
    {
        for(cellptr p=H[Hash(key)].next; p!=NULL; p=p->next)
        {
            if(p->data.key==key)
            {
                return p;
                break;
            }
        }
    }
    return NULL;
}
void Insert(records R)
{
    if(Search(R.key)==NULL)
    {
        int locate=Hash(R.key);
        if(H[locate].data.key==empty)
            H[locate].data=R;
        else
        {
            cellptr p=H[locate].next;
            H[locate].next=new celltype;
            H[locate].next->data=R;
            H[locate].next->next=p;
        }
    }
    else return;
}
void Delete(int key)
{
    int locate=Hash(key);
    cellptr p=H[locate].next;
    if(H[locate].data.key==key&&p==NULL)
        H[locate].data.key=empty;
    else if(H[locate].data.key==key&&p!=NULL)
    {
        H[locate].data=p->data;
        H[locate].next=p->next;
        delete p;
    }
    else if(H[locate].data.key!=empty&&p!=NULL&&p->data.key==key)
    {
        H[locate].next=p->next;
        delete p;
    }
    else if(H[locate].data.key!=empty&&p!=NULL)
    {
        for(cellptr pp=p; pp->next!=NULL; pp=pp->next)
        {
            if(pp->next->data.key==key)
            {
                p=pp->next;
                pp->next=p->next;
                delete p;
                break;
            }
        }
    }
    else return;
}
int Hash(int Key)
{
    return Key%B;
}
