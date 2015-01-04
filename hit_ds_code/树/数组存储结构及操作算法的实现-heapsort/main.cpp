//main.cpp
#include  "heapsort.h"
int main()
{
    array_BTtree<int> t;
    int i,n,a[maxlen];
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> a[i];
    t.setup(a,n);
    t.heapsort();
    t.order();
    return 0;
}





















