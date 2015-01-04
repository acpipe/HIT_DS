//main.cpp
#include  "BTtree.h"
int main()
{
    BTtree<char> test;
    test.pre_create();
    test.pre_order(test.return_root());
    cout << endl;
    test.in_order(test.return_root());
    cout << endl;
    test.post_order(test.return_root());
    cout << endl;
    test.nrec_pre_order(test.return_root());
    cout << endl;
    test.nrec_in_order(test.return_root());
    cout << endl;
    test.nrec_post_order(test.return_root());
    cout << endl;
    test.level_order(test.return_root());
    cout << endl;
    return 0;
}
//ABDH##I##E##CF#J##G##
//ABDHIECFJG
//HDIBEAFJCG
//HIDEBJFGCA
//ABDHIECFJG
//HDIBEAFJCG
//HIDEBJFGCA
//ABCDEFGHIJ
