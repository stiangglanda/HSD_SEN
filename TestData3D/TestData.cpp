//
// Created by stiangglanda on 2026-03-21.
//

#include "TestData.h"
#include "RandomGen.h"

const int low=-100;
const int high=100;

struct Point3D {
    int x, y, z;
};

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
    return os << " (" << point.x << ", " << point.y << ", " << point.z << ")";
}

static Point3D GeneratePoint3D(const int lo, const int hi) {
    return Point3D{rgen::GetRandVal(lo, hi), rgen::GetRandVal(lo, hi), rgen::GetRandVal(lo, hi)};
}

void GenerateTestData(int Amount, std::ostream& out) {
    out << "COUNT="<<Amount;
    for (int i=0; i<Amount; i++) {
        out << GeneratePoint3D(low, high);
    }
}

void PrintTestData(std::istream& in) {
    std::cout << in.rdbuf();
}
