///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 16. 01. 2026
// Description : Ackermann
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include <iostream>

struct Result {
    unsigned int val;
    unsigned int callCnt;
    unsigned int maxDepth;
};

// b
unsigned int Ackermann(unsigned int m, unsigned int n) {
    if (m == 0) {
        return n+1;
    } else if (n == 0) {
        return Ackermann(m-1, 1);
    } else {
        return Ackermann(m-1, Ackermann(m, n-1));
    }
}
// c & d
Result AckermannFinal(unsigned int m, unsigned int n, unsigned int currentDepth = 0) {
    static unsigned int globalCallCnt = 0;
    static unsigned int globalMaxDepth = 0;

    if (currentDepth == 0) {
        globalCallCnt = 0;
        globalMaxDepth = 0;
    }

    globalCallCnt++;
    if (currentDepth > globalMaxDepth) {
        globalMaxDepth = currentDepth;
    }

    unsigned int resultValue;

    if (m == 0) {
        resultValue = n + 1;
    }
    else if (n == 0) {
        resultValue = AckermannFinal(m - 1, 1, currentDepth + 1).val;
    }
    else {
        unsigned int innerResult = AckermannFinal(m, n - 1, currentDepth + 1).val;
        resultValue = AckermannFinal(m - 1, innerResult, currentDepth + 1).val;
    }
    return {resultValue, globalCallCnt, globalMaxDepth};
}

int main() {
    const unsigned int m = 3;
    const unsigned int n = 2;

    std::cout << "b) Ackermann(" << m << ", " << n << ") = " << Ackermann(m, n) << std::endl;

    Result res = AckermannFinal(m, n);
    std::cout << "c&d) Ackermann(" << m << ", " << n << ") = " << res.val << std::endl;
    std::cout << "Aufrufe: " << res.callCnt << std::endl;
    std::cout << "Max Tiefe: " << res.maxDepth << std::endl;

    return 0;
}