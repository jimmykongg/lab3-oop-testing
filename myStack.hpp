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
    MyStack();

    bool push(int val);

    void pop();

    int top() const;

    bool empty() const;

    bool full() const;

    string print() const;
};
