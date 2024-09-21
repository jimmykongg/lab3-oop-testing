//
// Created by Jimmy Kong on 2024-09-20.
//
#include <string>
#pragma once

using namespace std;

constexpr int max_size = 10;
constexpr int empty_value = -1;

class MyStack {
private:
    int stack[max_size];
    int topIndex;

public:
    // Default constructor
    // RETURN: a MyStack object initialized with topIndex = -1
    MyStack();

    // Accept an int and adds it to the top of the stack, returning true if it was added, else false
    // PRE: val is an integer
    // POST: val is unchanged
    // RETURN: a boolean value indicating whether val is added to the top of the stack
    bool push(int val);

    // Decrement the instance variable which stores the index of the "top" element
    // RETURN: does not return any value
    void pop();

    // Return (without removing) the int on the "top" of the stack
    // RETURN: top element of the stack as an int
    int top() const;

    // Return true if the stack is empty, else false
    // RETURN: a boolean value indicating whether stack is empty
    bool empty() const;

    // Return true if the stack is full, else false
    // RETURN: a boolean value indicating whether stack is full
    bool full() const;

    // Print the contents of the stack (bottom of the stack to the top) to standard output and return the printed message
    // RETURN: a string representation of the stack contents
    string print() const;
};
