#include <iostream>

int main() {
    //Arithmetische Operatoren
    int a = 0;
    int b = 2;
    int c = 3;

    a = b + c;  //5
    a = b - c;  //-1
    a = b * c;  //6
    a = b / c;  //0 -> schneidet ab
    a = c % b;  //1
    a = -c;     //-3
    a = +c;     //3
    a = 17 % 3; //2

    std::cout << a << std::endl;
    return 0;
}