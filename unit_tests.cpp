//
// Created by Jimmy Kong on 2024-09-20.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "myStack.hpp"

constexpr int test_value_1 = 10;
constexpr int test_value_2 = -20;
constexpr int test_value_3 = 7;

// Example test case provided in lab instructions
TEST_CASE("A new stack is empty", "testTag1") {
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.full() == false);
}

/**
 * Test popping an empty stack
 * Precondition: Cannot pop an empty stack, operation is ignored
 * Postcondition: Stack remains empty
 * Invariant: Stack size is between 0 and max_size
 */
TEST_CASE("Pop an empty stack") {
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.top() == empty_value);
}

/**
 * Test popping an empty stack and pushing values
 * Precondition: Only integer values can be pushed
 * Postcondition: Top value equals to test_value_2
 * Invariant: Stack size is between 0 and "max_size" constexpr
 */
TEST_CASE("Pop empty stack and add values") {
    MyStack tester;
    tester.pop();
    tester.push(test_value_1);
    tester.push(test_value_2);

    REQUIRE(tester.empty() == false);
    REQUIRE(tester.top() == test_value_2);
}

/**
 * Test popping an empty stack and pushing values
 * Precondition: Maximum stack amount cannot exceed "max_size" constexpr
 * Postcondition: top value equals to the value that hits the maximum stack amount
 * Invariant: "max_size" remains unchanged
 */
TEST_CASE("Push more than maximum stack amount, check value of top of stack") {
    MyStack tester;
    int invalid_amount = 100;
    int top_value;

    for (int i = 0; i < invalid_amount; i++) {
        tester.push(i);
        if (i == max_size - 1) top_value = i;
    }

    REQUIRE(tester.full() == true);
    REQUIRE(tester.top() == top_value);
}

/**
 * Test checking top value on empty stack
 * Precondition: Empty stack does not contain any valid integer values
 * Postcondition: An invalid value "empty_value" is returned when top value is checked
 * Invariant: stack contains 0 integer values
 */
TEST_CASE("Check top value on empty stack") {
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.top() == empty_value);
}

/**
 * Test pushing X values and popping Y values, then check top for expected value
 * Precondition: Empty stack does not contain any valid integer values
 * Postcondition: Only one integer remains in the stack
 * Invariant: stack is neither empty nor full
 */
TEST_CASE("Push 3 values then pop 2 values, check top for expected value") {
    MyStack tester;
    tester.push(test_value_1);
    tester.push(test_value_2);
    tester.push(test_value_3);
    tester.pop();
    tester.pop();

    REQUIRE(tester.empty() == false);
    REQUIRE(tester.full() == false);
    REQUIRE(tester.top() == test_value_1);
}

/**
 * Test pushing 10 values to stack and check if stack is full and top value equals last value pushed
 * Precondition: Stack is empty before pushed
 * Postcondition: Stack is full and top value equals last value pushed
 * Invariant: "max_size" remains unchanged
 */
TEST_CASE("Push exactly 10 values, check if stack is full and top value is expected value") {
    MyStack tester;
    int top_value;

    for (int i = 0; i < max_size; i++) {
        tester.push(i);
        if (i == max_size - 1) top_value = i;
    }

    REQUIRE(tester.full() == true);
    REQUIRE(tester.top() == top_value);
}
