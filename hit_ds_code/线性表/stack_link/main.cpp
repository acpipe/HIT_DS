//ºÏ≤È¿®∫≈∆•≈‰
#include <iostream>
#include <stdio.h>
#include "stack_link.h"
#define maxlen 1000
char a[maxlen];
using namespace std;
int main()
{
    stack<char> s;
    int i=0,j=0;
    char m;
    while(cin >> m && m!='#') i++;
    while (j<=i-1)
    {
        if(a[j]=='('||a[j]=='['||a[j]=='{') s.push(a[j]);
        else if(a[j]==')')
        {
            if(!s.empty()&&s.top()=='(')  s.pop();
            else break;
        }
        else if(a[j]==']')
        {
            if(!s.empty()&&s.top()=='[')  s.pop();
            else break;
        }
        else if(a[j]=='}')
        {
            if(!s.empty()&&s.top()=='{')  s.pop();
            else break;
        }
        j++;
    }
    if(j==i&&s.empty()) printf("∆•≈‰’˝»∑\n");
    else printf("∆•≈‰¥ÌŒÛ\n");
    return 0;
}
