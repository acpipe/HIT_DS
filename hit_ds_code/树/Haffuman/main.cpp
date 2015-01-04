#include<iostream>
#include<cstring>
#include<cstdio>
#define N 10000
using namespace std;
struct HTnode
{
    int lchild,rchild,parent,num;
    int flag;//标记是否访问过
    char ch;
};
struct  CodeNode
{
    char ch; //存储被编码的字符
    char bits[N+1]; //字符编码位串
};
struct CodeNode HuffmanCode[N];
struct HTnode  Haffuman[2*N-1];
void Resert(HTnode a[])
{
    for (int i=0; i<N; i++)
    {
        a[i].parent = -1;
        a[i].lchild = -1;
        a[i].rchild = -1;
        a[i].num=0;
        a[i].flag=1;
    }
}
int Selectmin(int a,int b,HTnode c[])
{
    int m;
    for(int i=a; i<b; i++)
        if(c[i].flag==1)
        {
            m=i;
            break;
        }
    for(int i=m; i<b; i++)
        if(c[i].num<c[m].num&&c[i].flag==1)
            m=i;
    c[m].flag=0;
    return m;
}
void Encoding(CodeNode H[],HTnode a[],int x,char s[])
{
    int c,p,start;
    char cd[x+1];
    cd[x]='\0';
    for(int i=0; i<x; i++)
    {
        H[i].ch=a[i].ch;
        start=x;
        c=i;
        while((p=a[c].parent)>=0)
        {
            cd[--start]=(a[p].lchild==c)? '0' : '1';
            c=p;
        }
        strcpy(H[i].bits,&cd[start]);
    }
    for(unsigned int i=0; i<strlen(s); i++)
        for(int j=0; j<x; j++)
        {
            if(s[i]==H[j].ch)
                cout << H[j].bits;
        }
}
void read(HTnode a[],int &x,char s[])
{
    Resert(a);//初始化
    for(unsigned int i=0; i<=strlen(s); i++)
    {
        int f=0;
        for(int j=0; j<x; j++)
            if(a[j].ch==s[i])
            {
                a[j].num++;
                f=1;
                break;
            }
        if(!f)
        {
            a[x-1].ch=s[i];
            a[x-1].num++;
            x++;
        }
    }
    x--;
    for(int i=x; i<2*x-1; i++)
    {
        int w=Selectmin(0,i,a);//返回下标最小的
        int z=Selectmin(0,i,a);//选择次小的下标
        a[w].parent=a[z].parent=i;
        a[i].lchild=w;
        a[i].rchild=z;
        a[i].num=a[w].num+a[z].num;
    }
}
void Decoding(HTnode a[],int x,char s[])
{
    int j=2*x-2;
    for(unsigned int i=0; i<=strlen(s); i++)
    {
        if(s[i]=='0')
            j=a[j].lchild;
        else j=a[j].rchild;
        if(a[j].lchild==-1&&a[j].rchild==-1)
        {
            cout << a[j].ch;
            j=2*x-2;
        }
    }
}
int main()
{
    char s[N],s1[N];
    int x=1;
    //构造HaffMan树
    gets(s);
    read(Haffuman,x,s);
    //读入
    Encoding(HuffmanCode,Haffuman,x,s);
    //编码
    gets(s1);
    Decoding(Haffuman,x,s1);
    return 0;
}

