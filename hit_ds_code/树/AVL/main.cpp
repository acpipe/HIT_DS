#include "AVL.h"
int main()
{
    AVL<int> test;
    node<int>* x;
    test.Create();
    x=test.return_rt();
    test.in_order(x);
    cout << endl;
    return 0;
}

