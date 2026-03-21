#include <iostream>
#include <fstream>

#include "TestData.h"

int main() {
    const std::string filePath{"TestData.txt"};

    std::ofstream out{filePath};
    GenerateTestData(10, out);
    out.close();
    std::ifstream in{filePath};
    PrintTestData(in);
    in.close();
}
