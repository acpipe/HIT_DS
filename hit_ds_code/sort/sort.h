//file:sort.h
#ifndef _SORT_HIT_HUMING_INCLUDE_
#define _SORT_HIT_HUMING_INCLUDE_
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef int T;
void print(T a[],int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void Swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
//hint:下面所有的都是按照升序排
//-------------基本BubbleSort-----------
//o(n^2) 稳定
void Basic_BubbleSort(T a[],int n)
{
    for(int i=1; i<n; i++) //从1->n-1逐步缩小排序的序列
        for(int j=n-1; j>=i; j--) //反向检测，有逆序交换
            if(a[j]<a[j-1])
                Swap(a[j],a[j-1]);
}
//-------------改进的BubbleSort-----------
//着眼点：某些系列不用n-1次就已经排好啦，这样的话后面的检测就不必要
//（比如一个升序的，最"轻"的本来就在最上面）;
//我们设置一个标志位检测是否发生啦交换，如果发生啦，说明还没有完全排好，
//没有那么已经排好啦就不用检测啦;
//o(n^2) 稳定
void BubbleSort(T a[],int n)
{
    for(int i=1; i<n; i++)
    {
        bool exchange=false; //每一趟检测之前都标志为没有发生交换
        for(int j=n-1; j>=i; j--)
        {
            if(a[j]<a[j-1])
            {
                Swap(a[j],a[j-1]);
                exchange=true;
            }
        }
        if(!exchange) return;//没有发生交换，那么已经排好啦
    }
}
//-----------------------------
//---------QuickSort-----------
//-----------------------------
//改进气泡排序，着眼点：
//减少总的比较次数和移动次
//->增大记录的比较和移动距
//->较大记录从前面直接移动到后面，较小记录从后面直接移动到前面
//快排：通过一趟排序将要排序的数据分割成独立的两部分，
//其中一部分的所有数据都比另外一不部分的所有数据都要小，
//然后再按此方法对这两部分数据分别（分治的思想）进行快速排序，
//整个 排序过程可以递归进行，以此达到整个数据变成有序序列。
int FindPivot(T a[],int low,int high)
{
//选择第一个元素作为基准元素
//    int pivotpos=low;
//    for(int i=low+1; i<=high; i++)
//    {
//        if(a[i]<a[low])
//        {
//            pivotpos++;
//            if(pivotpos!=i)Swap(a[i],a[pivotpos]);
//        }
//    }
//    Swap(a[low],a[pivotpos]);//基准元素就位
//    return pivotpos;
    //快排好多选取的方式，下面这种是我经常写的，日后有时间在研究吧！
    //两边一起找
    while(low<high)
    {
        while(low<high&&a[high]>=a[low])
            high--;
        Swap(a[low],a[high]);
        while(low<high&&a[low]<=a[high])
            low++;
        Swap(a[low],a[high]);
    }
    return low;
}
void Nec_QuickSort(T a[],int left,int right)
{
    if(left<right)
    {
        int pivotpos=FindPivot(a,left,right);
        Nec_QuickSort(a,left,pivotpos-1);
        Nec_QuickSort(a,pivotpos+1,right);
    }
}
void qsort(T a[],int n)
{
    Nec_QuickSort(a,0,n-1);
}
//-----------SelectSort----------
//0(n^2)  不稳定
void SelectSort(T a[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int k=i;
        for(int j=i+1; j<n; j++)
            if(a[k]>a[j])   k=j;
        Swap(a[i],a[k]);
    }
}
void pushdown(T a[],int first,int last)
{
    int i=first,j=2*i+1;//j为i的左儿子
    T temp=a[i];//存放子节点的根
    while(j<=last)//检查是否到最后的位置
    {
        if(j<last&&a[j]<a[j+1]) j++;//j指向儿子中的较大的一个
        if(temp>=a[j]) break;//根比较大，不调整
        else
        {
            a[i]=a[j];
            i=j;
            j=2*j+1;//指针下走
        }
    }
    a[i]=temp;
}
void heapsort(T a[],int n)
{
    int i;
    for(i=(n-2)/2; i>=0; i--)
        pushdown(a,i,n-1);
    //最大堆建立
    for(i=n-1; i>=0; i--)
    {
        Swap(a[0],a[i]);
        pushdown(a,0,i-1);
    }//最大的在最上面，然后和最后一个交换就可以得到一个上升序的序列
}
//--------Insertsort---------
void Insertsort(T a[],int n)
{
    //就是一个玩扑克的时候排序的过程
    for(int i=1; i<n; i++)
    {
        int key=a[i],j=i-1;
        while(a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
//着眼点：查找时候用二分
void BinaryInsertsort(T a[],int n)
{
    int i,key,low,high,mid,k;
    for(i=1; i<n; i++)
    {
        key=a[i],low=0,high=i-1;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(key<a[mid])high=mid-1;
            else low=mid+1;
        }//拆半查找
        for(k=i-1; k>=low; k--)a[k+1]=a[k];
        a[low]=key;
    }
}
//--------------ShellSort-------------
//对插入的改进着眼点：分块排序
void ShellSort(T a[],int n)
{
    //Knuth提出的这样取间隔 shell当时提出来的是n/2，这种不太好
    //因为这样选取走到最后一步的时候，在奇数位置的才会与在偶数位置的比较，效率低；
    //(清华的书上那么写的，关于这个间隔的选取表示不太理解，求大神科普！)
    for(int gap=n/3+1; gap>1; gap=gap/3+1)
        for(int i=gap; i<n; i++)
            for(int j=i-gap; j>=0&&a[j]>a[j+gap]; j-=gap)
                Swap(a[j],a[j+gap]);
}
void Merge (T a[] ,T b[],int s,int m , int t )
{
    //将有序序列A[s],…,A[m]和A[m+1],…,A[t]合并为一个有序序列B[s]
    int i = s,j = m+1 ,k=s ;
    while (i<= m&&j <= t)
        b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++] ;
    while ( i <= m ) b[k++] = a[i++] ;
    while ( j <= t ) b[k++] = a[j++] ;
}
void MergePass(int a[], int b[], int seg, int n)
{
    //函数的作用是把a中长度为seg的相邻序列归并成长度为2seg的序列放在b中
    int seg_start_ind = 0;
    while(seg_start_ind<=n-2*seg)
        //归并长度小于n-2*seg才可以归并
    {
        Merge(a,b,seg_start_ind,seg_start_ind + seg - 1, seg_start_ind + 2*seg - 1);
        seg_start_ind+=2*seg;
    }
    //如果有两段，一段可以归并，但是另一段比较短，那么合并两段
    if(seg_start_ind + seg < n)
        Merge(a,b,seg_start_ind,seg_start_ind+seg-1,n-1);
    else
        for(int j = seg_start_ind; j < n; j++) //如果只剩下一段,直接复制到b[]中
            b[j] = a[j];
}
void  MergeSort(T a[],int n)
{
    T* temp = new int[n];
    int seg=1;
    while(seg < n)
    {
        MergePass(a,temp,seg,n);
        //把a中长度为seg的两个相邻序列合并到temp中；
        seg*=2;
        MergePass(temp,a,seg,n);
        //把temp中长度为seg的两个相邻序列合并到a中来；
        seg*=2;
        //归并的长度没一次都要变成两倍
    }
    delete [] temp;//销毁辅助空间temp
}

#endif
