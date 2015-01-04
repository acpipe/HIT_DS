#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define B 10000//桶的大小
int  divitor=11;
using namespace std;
enum {empty=-1,deleted=-2};
struct records
{
    int key;
    char other;
};
typedef records HASH[B];
inline int hashfun1(int k);
int Search(int k, HASH F);
void Delete(int k,HASH F);
void Insert(records R, HASH F);
void Init(HASH info);
void Print(HASH info);
int main()
{
    bool f=true;
    int n;
    records r;
    HASH info;
    Init(info);
    printf("1---Insert\n2---Delete\n3---Search\n4---Print\n5---Return\n");
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
            cout << Search(r.key,info) << endl;
            break;
        case 4:
            Print(info);
            break;
        default:
            f=false;
            break;
        }
    }
    return 0;
}
/*****************************************************************************************/
/************************************散列函数********************************************/
/****************************************************************************************/
inline int hashfun1(int k)//质数除余法
{
    return  k%B;
}
//inline int hashfun2(int k)
//{
//   k=(k*k)/100;
//   return k%1000;
//}
/**************************************************************************************/
/******************************冲突处理的方法*****************************************/
/*************************************************************************************/
/***********1.线性探测法************/
int Search(int k, HASH F)
{
    int first=hashfun1(k),rehash=0,locate;
    for(locate=first; rehash<B&&F[locate].key!=empty; locate=(first+(++rehash))%B)
        if(F[locate].key==k)
            return locate;
    return -1;
}
void Insert(records R, HASH F)
{
    int first=hashfun1(R.key),rehash=0,locate;
    for(locate=first; rehash<B&&F[locate].key!=R.key; locate=(first+(++rehash))%B)
        if(F[locate].key==empty||F[locate].key==deleted)
        {
            F[locate]=R;
            break;
        }
    if(rehash>=B)
        cout<<"hash table is full!" << endl;
}
/**************************************************************************************/
/**************************************辅助函数***************************************/
/*************************************************************************************/
void Init(HASH info)
{
    for(int i=0; i<B; i++)
        info[i].key=empty;
}
void Delete(int k,HASH F)
{
    int locate=Search(k,F);
    F[locate].key=(locate!=-1)?deleted:F[locate].key;
}
void Print(HASH info)
{
    for(unsigned int i=0; i<B; i++)
        cout << info[i].key <<" ";
}
