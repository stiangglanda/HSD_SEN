#include <iostream>
#include <vector>

bool IsPrime(const int potentialPrime) {
    if (potentialPrime<2)
        return false;

    for (int i = 2; i < potentialPrime; i++)// clamp(potentialPrime/2)
    {
        if (potentialPrime % i == 0)
            return false;
    }
    return true;
}

int GetNextPrime(const int startValue) {
    for (int i = startValue; true; i++) {
        if (IsPrime(i))
            return i;
    }
}

void PrintResult(const std::vector<int> &arrayToPrint) {
    std::cout << "Ausgabe: ";
    for (int i = 0; i < arrayToPrint.size(); i++) {
        std::cout << arrayToPrint[i];

        if (i != arrayToPrint.size()-1) {
            std::cout << ", ";
        }
    }
}

int main() {
    std::vector<int> primeNumbers;
    int input=0;

    std::cout << "Eingabe: ";
    std::cin >> input;

    if (input<2) {
        std::cout << "The input number should be at least 2";
        return 0;
    }


    int primeDivisionResult=input;
    int currentPrimeNumber=2;

    while (primeDivisionResult>1)
    {
        if (primeDivisionResult%currentPrimeNumber==0)
        {
            primeDivisionResult=primeDivisionResult/currentPrimeNumber;
            primeNumbers.push_back(currentPrimeNumber);
        }
        else {
            currentPrimeNumber++;
            //currentPrimeNumber=GetNextPrime(currentPrimeNumber+1);
        }
    }

    PrintResult(primeNumbers);
    return 0;
}