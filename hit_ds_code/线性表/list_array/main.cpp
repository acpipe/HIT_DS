#include<iostream>
#include<cstring>
#include "array_list.h"
using namespace std;
struct rate
{
    char name[30];//银行名字
    double current_rate;//活期利率
};
int main()
{
    List<rate>R;
    struct rate x;
    int N;
    printf("1--插入\n2--删除\n3--查询\n4--打印\n0--退出\n");
    while(cin >> N)
    {
        switch(N)
        {
        case 1:
            int m;
            cin >> m;//插入个数
            for(int i=1; i<=m; i++)
            {
                cin >> x.name >> x.current_rate;
                R.Insert(i,x);
            }//插入的时候一直在后面插入
            break;
        case 2:
            cin >> x.name;
            for(int i=1; i<=R.End()-1; i++)
                if(strcmp(R.Retrieve(i).name,x.name)==0)  R.Delete(i);
            break;
        case 3:
            cin >> x.name;
            for(int i=1; i<R.End(); i++)
            {
                if(strcmp(R.Retrieve(i).name,x.name)==0)
                    cout << R.Retrieve(i).current_rate << endl;
            }
            break;
        case 4:
            for(int i=1; i<R.End(); i++)
                cout << R.Retrieve(i).name << "---" <<  R.Retrieve(i).current_rate << endl;
                break;
        case 0:
            return 0;
        }
       printf("1--插入\n2--删除\n3--查询\n4--打印\n0--退出\n");
    }
    return 0;
}

