//file:mystack.h
#ifndef _MYSTACK_H_INCLUDE_
#define _MYSTACK_H_INCLUDE_
#define N 10002
template <typename T>
class Stack
{
public:
    Stack():stack_top(0) {}
    void push(T t)
    {
        s[stack_top++] = t;
    }
    void pop()
    {
        stack_top--;
    }
    T top()
    {
        return s[stack_top-1];
    }
    bool empty()
    {
        return stack_top == 0;
    }
private:
    int stack_top;
    T s[N];
};
#endif // _STACK_H_INCLUDE_
