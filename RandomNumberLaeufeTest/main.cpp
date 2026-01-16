#include <iostream>
#include "RandomGen.h"

const unsigned int N=20;
typedef int LaeufeResult[N];


void FillArray(int F[], const unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        F[i] = rgen::GetRandVal(-100, 100);;
    }
}

void InitLaeufeResult(LaeufeResult result) {
    for (unsigned int i = 0; i < N; i++) {
        result[i]=0;
    }
}

void AnalyseLaeufe(int F[], const unsigned int n, LaeufeResult result) {
    if (n<1) {
        return;
    }
    InitLaeufeResult(result);

    int prev=F[0];
    int streakCnt=1;
    for (unsigned int i = 1; i < n; i++) {
        if (F[i]>=prev) {
            streakCnt++;
        } else {
            if (streakCnt<20) {
                result[streakCnt]++;
            }
            streakCnt=1;
        }
        prev = F[i];
    }

    if (streakCnt<20) {
        result[streakCnt]++;
    }
}

void PrintArray(int const F[], const unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        std::cout << F[i] << " ";
    }
}

int main() {

    int F[N];
    FillArray(F, N);
    PrintArray(F,N);
    LaeufeResult result;
    AnalyseLaeufe(F, N, result);
    std::cout << std::endl;
    PrintArray(result,N);
    return 0;
}