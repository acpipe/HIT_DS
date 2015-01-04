#include "listtree.h"
int main()
{
  Listtree<char> test;
  test.Create();
  test.to_list();
  test.pre_order();
  cout << endl;
  test.In_order();
  cout << endl;
  test.Post_order();
  cout << endl;
  return 0;
}
//ABDH##I##E##CF#J##G##
