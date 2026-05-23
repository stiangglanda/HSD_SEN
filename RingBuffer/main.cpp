///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 23.05.2026
// Description : RingBuffer Test Driver
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "RingBuffer.h"
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>

namespace std {
    template <typename T1, typename T2>
    ostream& operator<<(ostream& ost, const pair<T1, T2>& p) {
        ost << "(" << p.first << ", " << p.second << ")";
        return ost;
    }
}

void TestBasicAndOverwrite() {
    std::cout << "Basic Test";
    RingBuffer<int> rb(3);
    rb.Enqueue(1);
    rb.Enqueue(2);
    rb.Enqueue(3);
    std::cout << "Full buffer: ";
    rb.Print();

    rb.Enqueue(4);
    std::cout << "After inserting 4 (overwrite): ";
    rb.Print();

    int val;
    rb.Dequeue(val);
    std::cout << "Dequeued: " << val << ", Buffer: ";
    rb.Print();
}

void TestEmptyException() {
    std::cout << "Test Empty Buffer Exception" << std::endl;
    RingBuffer<int> rb(2);
    try {
        int val;
        rb.Dequeue(val);
    } catch (const std::out_of_range& e) {
        std::cout << "Expected exception caught: " << e.what() << std::endl;
    }
}

void TestCopyAndAssign() {
    std::cout << "Test Copy Constructor & Assignment Operator" << std::endl;
    RingBuffer<int> rb1(3);
    rb1.Enqueue(10);
    rb1.Enqueue(20);

    RingBuffer<int> rb2(rb1);
    std::cout << "Copied rb2: ";
    rb2.Print();

    rb1.Enqueue(30);
    rb1.Enqueue(40); // Overwrite
    std::cout << "Modified rb1: ";
    rb1.Print();
    std::cout << "Unmodified rb2: ";
    rb2.Print();

    RingBuffer<int> rb3(3);
    rb3.Enqueue(99);
    rb3 = rb2;
    std::cout << "Assigned rb3 from rb2: ";
    rb3.Print();

    rb3 = rb3;
    std::cout << "After self-assignment rb3: ";
    rb3.Print();
}

void TestPairType() {
    std::cout << "Test std::pair" << std::endl;
    RingBuffer<std::pair<int, std::string>> rb(2);
    rb.Enqueue(std::make_pair(1, "One"));
    rb.Enqueue(std::make_pair(2, "Two"));
    std::cout << "Pair buffer: ";
    rb.Print();

    rb.Enqueue({3, "Three"});
    std::cout << "After inserting (3, Three): ";
    rb.Print();

    std::pair<int, std::string> val;
    rb.Dequeue(val);
    std::cout << "Dequeued: (" << val.first << ", " << val.second << ")" << std::endl;
}

int main() {
    try {
        TestBasicAndOverwrite();
        TestEmptyException();
        TestCopyAndAssign();
        TestPairType();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
