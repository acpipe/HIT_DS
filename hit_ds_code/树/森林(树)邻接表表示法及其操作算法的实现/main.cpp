#include <iostream>
#include <stdio.h>
#include "forest.h"
forest<char> v;
using namespace std;
int main()
{
    cout<<"建森林"<<endl;
    v.CreateForest();
    v.Print();
    cout<<"转换为二叉树:"<<endl;
    v.TransformForesttoBT();
    cout<<"建二叉树"<<endl;
    v.CreateBT();
    cout<<"二叉树转森林:"<<endl;
    v.TransformBTtoForest();
    v.Print();
    return 0;
}

