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

int GetNextSmallestPrime(const int startValue) {
    for (int i = startValue; i >= 2; i--) {
        if (IsPrime(i))
            return i;
    }
    return 0;
}

int MultiplyArray(const std::vector<int> &arrayToMultiply) {
    if (arrayToMultiply.empty()) {
        return 0;
    }
    int result=arrayToMultiply[0];

    for (int i = 1; i < arrayToMultiply.size(); i++) {
        result*=arrayToMultiply[i];
    }

    return result;
}

void PrintResult(const std::vector<int> &arrayToPrint) {
    std::cout << "Ausgabe: ";
    for (int i = arrayToPrint.size()-1; i >= 0; i--) {
        if (i == 0) {
            std::cout << arrayToPrint[i];
        }
        else {
            std::cout << arrayToPrint[i]<<", ";
        }
    }
}

int main() {
    std::vector<int> primeNumbers={};
    int input=0;

    std::cout << "Eingabe: ";
    std::cin >> input;


    int primeDivisionResult=input;
    int currentPrimeNumber=GetNextSmallestPrime(input);

    do
    {
        if (primeDivisionResult%currentPrimeNumber==0)
        {
            primeDivisionResult=primeDivisionResult/currentPrimeNumber;
            primeNumbers.push_back(currentPrimeNumber);
        }
        else {
            currentPrimeNumber=GetNextSmallestPrime(currentPrimeNumber-1);
        }
    } while (MultiplyArray(primeNumbers)!=input);

    PrintResult(primeNumbers);
    return 0;
}