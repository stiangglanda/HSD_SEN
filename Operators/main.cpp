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

    //Inkrement- und Dekrement
    int i = 2;
    int x = i++; //x = 2, i = 3

    i = 2;
    x=++i;//x = 3, i = 3

    x=++i;//x = 4, i = 4

    //i++ -> lesen, verarbeiten, erhöhen
    //++i -> lesen, erhöhen, verarbeiten

    //Relationale Operationen
    int d = 5;
    int e = 1;

    if (e<d) {
        e--;
    }
    while (d>=e) {
        d--;
    }
    if (e!=d) {
        std::cout << "ungleich" << std::endl;
    }

    //logische Operatoren
    int f=5;
    int g=3;
    bool h=true;

    if ((f>g) && h) {//wenn (5>3) true UND h true ist -> True ins IF
        std::cout << "......" << std::endl;
    }
    if ((f>g) && (f<g)) {//wenn (5>3) true UND (5<3) true ist -> True ins IF
        //immer False
        std::cout << "unmöglich" << std::endl;
    }

    while ((f<5) && (g>3)) {// False && False
        std::cout << "..." << std::endl;
    }

    if ((g == 3) && (f != 5) && h) {//FALSE weil f ist 5
        std::cout << "xxx" << std::endl;
    }

    //Bitoperatoren
    a = 0x005A;     //0b0000 0000 0101 1010
    x = a & 0x000F; //0b0000 0000 0000 1111
    //x = 0x000A    //0b0000 0000 0000 1010

    a = 0x005A;     //0b0000 0000 0101 1010
    x = a|0x000F;   //0b0000 0000 0000 1111
    //x = 0x005F;   //0b0000 0000 0101 1111

    a = 0x005A;     //0b0000 0000 0101 1010
    x = a ^ 0x000F; //0b0000 0000 0000 1111
    //x = 0x0055;   //0b0000 0000 0101 0101

    x = ~a;         //0b0000 0000 0101 1010 = 0x005A
    //x = 0xFFA5;   //0b1111 1111 1010 0101

    x = 9;      //0b0000 1001
    x = x << 1; //0b0001 0010
    //x = 18 -> Multiplikation *2, schnellste Multiplikation

    x = 9;      //0b0000 1001
    x = x >> 1; //0b0000 0100 -> 1 fällt weg
    //x = 4 -> Division durch 2, schnellste Division

    x = 9;      //0b0000 1001
    x = x >> 3; //0b0000 0001
    //x = 1 -> Division durch 6, schnellste Division


    return 0;
}