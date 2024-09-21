//Name: Jimmy Kong
//Student# : A01348050

#include <iostream>
#include "myStack.hpp"

int main()
{
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.top() << endl;
}
