#include "tree.h"
int main()
{
    tree<char> test;
    node<char>* r;
    test.Create();
    r=test.return_rt();
    test.pre_order(r);
    cout << endl;
    test.post_order(r);
    cout << endl;
    test.level_order(r);
    return 0;
}
//AB#C#D###
