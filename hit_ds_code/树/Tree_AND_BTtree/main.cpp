#include "Turn.h"
int main()
{
  Tree<char> test;
  BTtree<char> t;
  test.Create();
  t=test.tree_to_bt();
  return 0;
}
/*
9
A 3 2 0
B 6 5 4 0
C 8 7 0
D 0
E 9 0
F 0
G 0
H 0
I 0
*/
