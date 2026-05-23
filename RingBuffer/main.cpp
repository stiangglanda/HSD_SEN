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

int main() {
    RingBuffer<int> rb{3};
    int valRet;
    rb.Enqueue(1);

    rb.Print();
    rb.Enqueue(2);
    rb.Print();
    rb.Enqueue(3);
    rb.Print();
    rb.Dequeue(valRet);
    rb.Print();
    rb.Enqueue(4);
    rb.Print();
    rb.Enqueue(5);
    rb.Print();

    rb.Dequeue(valRet);
    rb.Print();
    rb.Dequeue(valRet);
    rb.Print();
    rb.Dequeue(valRet);
    rb.Print();

    return 0;
}
