//main.cpp
#include  "BTtree.h"
int main()
{
  BTtree<char> tree;
  tree.pre_create();
  tree.pre_order(tree.return_root());
  cout << endl;
  tree.in_order(tree.return_root());
  cout << endl;
  tree.post_order(tree.return_root());
  cout << endl << endl;
  tree.nrec_pre_order(tree.return_root());
  cout << endl;
  tree.nrec_in_order(tree.return_root());
  cout << endl;
  tree.nrec_post_order(tree.return_root());
  cout << endl << endl;
  tree.level_order(tree.return_root());
  return 0;
}
//ABDH##I##E##CF#J##G##
//ABDHIECFJG
//HDIBEAFJCG
//HIDEBJFGCA
//
//ABDHIECFJG
//HDIBEAFJCG
//HIDEBJFGCA
//
//ABCDEFGHIJ
