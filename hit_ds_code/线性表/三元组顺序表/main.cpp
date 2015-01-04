//三元组矩阵转置
//吐槽：明天要交作业啦啦啦...学长各种邪恶有木有，随便敲的，优化什么的谈不上啦...呜呜....
#include<iostream>
using namespace std;
#include  "threemat.h"
int main()
{
    TSMatrix<int>  mat;
    cin >> mat.row >> mat.col >> mat.unzero;
    for(int l=0; l<mat.unzero; l++)
        cin >> mat.data[l].i >> mat.data[l].j >> mat.data[l].v;
    cout << "原矩阵为:" << endl;
    mat.show();
    mat.turn();
    cout << endl << "转置之后的矩阵为：" << endl;
    mat.show();
    return 0;
}
//
//3 3 4
//0 0 1
//0 1 2
//0 2 3
//1 2 4
