//对于数组实现和指针实现可以通用
//多项式运算
#include <iostream>
#include <stdio.h>
#include "static_state_link.h"
struct polynode
{
    int coef;
    int exp;
};
void PolyAdd(list<polynode> L1,list<polynode> L2,list<polynode> L3);
void PolySub(list<polynode> L1,list<polynode> L2,list<polynode> L3);
void PolyMultiply(list<polynode> L1,list<polynode> L2);
void Sort(list<polynode> L);
void Print(list<polynode> L);

using namespace std;

int main()
{
    int n;
    polynode p;
    list <polynode> l1,l2,l3;
    printf("请先分别输入两个多项式，首先输入每个多项式的项数，再分别输入每一项的系数和次数\n");
    printf("请输入第一个多项式\n");
    scanf(" %d",&n);
    while(n--)
    {
        scanf(" %d %d",&p.coef,&p.exp);
        l1.Insert(l1.First(),p);
    }
    printf("请输入第二个多项式\n");
    scanf(" %d",&n);
    while(n--)
    {
        scanf(" %d %d",&p.coef,&p.exp);
        l2.Insert(l2.First(),p);
    }
    printf("1---多项式加法\n2---多项式乘法\n3---多项式减法\n");
    scanf(" %d",&n);
    switch(n)
    {
    case 1:
        Print(l1);
        Print(l2);
        PolyAdd(l1,l2,l3);
        Print(l3);
        break;
    case 2:
        Print(l1);
        Print(l2);
        PolyMultiply(l1,l2);
        break;
    case 3:
        Print(l1);
        Print(l2);
        PolySub(l1,l2,l3);
        Print(l3);
        break;
    default:
        printf("End\n");
        break;
    }
    return 0;
}
//假设在输入的时候不重复输入次数相同的项
void PolyAdd(list<polynode> L1,list<polynode> L2,list<polynode> L3)
{
    polynode temp;
    int p1=1;
    int p2=1;
    Sort(L1);
    Sort(L2);
    while(p1<=L1.Size()&&p2<=L2.Size())
    {
        if(L1.Retrieve(p1).exp>L2.Retrieve(p2).exp)
        {
            L3.Insert(L3.End(),L1.Retrieve(p1));
            p1++;
        }
        else if(L1.Retrieve(p1).exp<L2.Retrieve(p2).exp)
        {
            L3.Insert(L3.End(),L2.Retrieve(p2));
            p2++;
        }
        else
        {
            temp.coef=L1.Retrieve(p1).coef+L2.Retrieve(p2).coef;
            temp.exp=L1.Retrieve(p1).exp;
            L3.Insert(L3.End(),temp);
            p1++;
            p2++;
        }
    }
    if(p1<=L1.Size())
    {
        for(int i=p1; i<=L1.Size(); i++)
            L3.Insert(L3.End(),L1.Retrieve(i));
    }
    if(p2<=L2.Size())
    {
        for(int i=p2; i<=L2.Size(); i++)
            L3.Insert(L3.End(),L2.Retrieve(i));
    }
}
void PolyMultiply(list<polynode> L1,list<polynode> L2)
{
    polynode temp;
    list<polynode> pre;
    for(int i=1; i<=L1.Size(); i++)
    {
        list<polynode> now,ans;
        for(int j=1; j<=L2.Size(); j++)
        {
            temp.coef=L1.Retrieve(i).coef*L2.Retrieve(j).coef;
            temp.exp=L1.Retrieve(i).exp+L2.Retrieve(j).exp;
            now.Insert(now.End(),temp);
        }
        PolyAdd(pre,now,ans);
        if(i==L1.Size()) Print(ans);
        for(int k=pre.Size(); k>=1; k--)
            pre.Delete(k);
        for(int k=1; k<=ans.Size(); k++)
            pre.Insert(1,ans.Retrieve(k));
    }
}
void PolySub(list<polynode> L1,list<polynode> L2,list<polynode> L3)
{
    polynode temp;
    for(int i=1; i<=L2.Size(); i++)
    {
        temp.exp=L2.Retrieve(i).exp;
        temp.coef=L2.Retrieve(i).coef*(-1);
        L2.Delete(i);
        L2.Insert(i,temp);
    }
    PolyAdd(L1,L2,L3);
}
void Sort(list<polynode> L)
{
    for(int i=1; i<L.Size(); i++)
    {
        for(int j=i+1; j<=L.Size(); j++)
        {
            if(L.Retrieve(j).exp>L.Retrieve(i).exp)
                L.Swap(i,j);
        }
    }
}
void Print(list<polynode> L)
{
    if(!L.Empty())
    {
        Sort(L);
        printf("%dx^%d",L.Retrieve(1).coef,L.Retrieve(1).exp);
        for(int i=2; i<=L.Size(); i++)
        {
            if(L.Retrieve(i).coef>0)
                printf("+%dx^%d",L.Retrieve(i).coef,L.Retrieve(i).exp);
            else if(L.Retrieve(i).coef<0)
                printf("%dx^%d",L.Retrieve(i).coef,L.Retrieve(i).exp);
        }
        printf("\n");
    }
}
/*
2
4 1
2 2

3
6 5
4 3
1 0
*/

////银行利率表管理，实际上有两个线性表
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include "list.h"
//
//using namespace std;
//
//int main()
//{
//    list<double> L1,L2;
//    int n,temp;
//    double year,rate,money,time;
//    bool flag;
//    printf("银行利率表管理\n1---插入\n2---删除\n3---修改\n4---打印\n5---查询\n6---排序\n7---计算\n其他----结束\n");
//    while(scanf(" %d",&n)!=EOF)
//    {
//        flag=true;
//        switch(n)
//        {
//        case 1://插入
//           printf("输入年限和利率\n");
//           scanf(" %lf %lf",&year,&rate);
//           L1.Insert(L1.First(),year);//插入到线性表中的第一个位置
//           L2.Insert(L2.First(),rate);//插入到线性表中的第一个位置
//           break;
//        case 2://删除
//           printf("输入要删除的年限\n");
//           scanf(" %lf",&year);
//           if(L1.Locate(year)==-1)
//             printf("要删除的年限不存在\n");
//           else
//           {
//            L1.Delete(L1.Locate(year));
//            L2.Delete(L1.Locate(year));
//           }
//           break;
//        case 3://修改
//            printf("输入要修改的年限\n");
//            scanf(" %lf",&year);
//            temp=L1.Locate(year);
//            if(temp==-1)
//             printf("要修改的年限不存在\n");
//            else
//            {
//                L1.Delete(temp);
//                L2.Delete(temp);
//                printf("输入新的年限和利率\n");
//                scanf(" %lf %lf",&year,&rate);
//                L1.Insert(temp,year);
//                L2.Insert(temp,rate);
//            }
//            break;
//        case 4://打印
//           if(!L1.Empty())
//           {
//               for(temp=L1.First();temp<=L1.Size();temp=L1.Next(temp))
//                 printf("%.2lf----%.3lf\n",L1.Retrieve(temp),L2.Retrieve(temp));
//           }
//           else printf("线性表为空\n");
//           break;
//        case 5://查询
//            if(!L1.Empty())
//            {
//                printf("输入要查找的年限\n");
//                scanf(" %lf",&year);
//                for(temp=L1.First();temp<=L1.Size();temp=L1.Next(temp))
//                {
//                    if (L1.Retrieve(temp)==year)
//                    {
//                        printf("利率为:%.3lf\n",L2.Retrieve(temp));
//                        break;
//                    }
//                }
//                if(temp==L1.End())
//                  printf("没有找到相应的利率\n");
//            }
//            else
//              printf("线性表为空\n");
//            break;
//        case 6://排序
//            for(int i=L1.First();i<=L1.Size()-1;i++)
//            {
//                for(int j=i+1;j<=L1.Size();j++)
//                {
//                    if(L2.Retrieve(j)<L2.Retrieve(i))
//                    {
//                        L1.Swap(i,j);
//                        L2.Swap(i,j);
//                    }
//                }
//            }
//            break;
//         case 7://计算
//            printf("输入年限和利率\n");
//            scanf(" %lf %lf",&year,&rate);
//            temp=L1.Locate(year);
//            if(temp==-1||L2.Retrieve(temp)!=rate)
//              printf("利率不存在\n");
//            else
//            {
//               printf("输入用户存款年限和本金\n");
//               scanf(" %lf %lf",&time,&money);
//               for(int i=1;i<=time;i++)
//               {
//                   money=money*pow((1.0+rate),1/year);
//               }
//               printf("最终用户将得到%.3lf$\n",money);
//            }
//            break;
//        default:
//            flag=false;
//            break;
//        }
//        if(!flag) break;
//        printf("银行利率表管理\n1---插入\n2---删除\n3---修改\n4---打印\n5---查询\n6---排序\n7---计算\n其他----结束\n");
//    }
//    return 0;
//}
