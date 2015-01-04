//file:main.cpp
#include  "BST.h"
int main()
{
  BST <int> test;
  test.CreateBST();
  node<int>* p=test.return_rt();
  test.in_order(p);
  cout << endl;
  test.InsertBST(25,p);
  test.in_order(p);
  cout << endl;
  test.Delete(9,p);
    test.in_order(p);
    cout << endl;
 return 0;
}

