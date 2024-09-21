//
// Created by Jimmy Kong on 2024-09-20.
//
#include <iostream>
#include "myStack.hpp"

using namespace std;

MyStack::MyStack(): topIndex(empty_value) {}

bool MyStack::push(int num) {
    if (full()) return false;

    stack[++topIndex] = num;
    return stack[topIndex] == num;
}

void MyStack::pop() {
    if (!empty()) topIndex--;
    else {
        string error_msg = "Stack is empty. No available elements could be popped out.";
        cout << error_msg << endl;
    }
}

int MyStack::top() const {
    if (!empty()) return stack[topIndex];
    return empty_value;
}

bool MyStack::empty() const {
    return topIndex == empty_value;
}

bool MyStack::full() const {
    return topIndex == max_size - 1;
}

string MyStack::print() const {
    string stackToString;

    if (empty()) {
        stackToString = "Stack is Empty.";
        cout << stackToString << endl;
        return stackToString;
    }

    for (int i = 0; i <= topIndex; i++) {
        if (i < topIndex) {
            stackToString += to_string(stack[i]) + ", ";
        } else {
            stackToString += to_string(stack[i]);
        }
    }
    cout << "[" << stackToString << "]" << endl;
    return stackToString;
}
