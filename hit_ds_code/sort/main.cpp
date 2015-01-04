#include <iostream>
#include <ctime>
#include<cstring>
#include <cstdlib>
#include "sort.h"
#define maxlen 100000
using namespace std;
int test[maxlen],a[maxlen];
void reset()
{
    srand((unsigned)time(NULL));
    for(int i=0; i<maxlen; i++)
        test[i]=0+rand()%100000;
}
int main()
{
    reset();
    clock_t t;
    printf("-------TIME COST OF SORT-------\n");
    memcpy(a,test,sizeof(test));
    t=clock();
    Basic_BubbleSort(a,maxlen);
    cout << "Basic_BubbleSort:" <<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    BubbleSort(a,maxlen);
    cout << "BubbleSort:"<<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    MergeSort(a,maxlen);
    cout <<"MergeSort:" <<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    qsort(a,maxlen);
    cout << "qsort:" << clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    SelectSort(a,maxlen);
    cout <<"SelectSort:"<<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    heapsort(a,maxlen);
    cout << "heapsort:" <<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    Insertsort(a,maxlen);
    cout << "Insertsort:" <<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    BinaryInsertsort(a,maxlen);
    cout << "BinaryInsertsort:" <<clock()-t<< "ms" << endl;
    memcpy(a,test,sizeof(test));
    t = clock();
    ShellSort(a,maxlen);
    cout << "ShellSort:" <<clock()-t<< "ms" << endl;
    return 0;
}
