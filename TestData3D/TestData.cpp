///////////////////////////////////////////////////////////////////////////
// Workfile : TestData.cpp
// Author : Leander Kieweg
// Date : 21.03.2026
// Description : TestData Module Implemantation
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////
#include "TestData.h"
#include "RandomGen.h"
#include "scanner.h"

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
    return os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
}

static Point3D GeneratePoint3D(const int lo, const int hi) {
    return Point3D{rgen::GetRandVal(lo, hi), rgen::GetRandVal(lo, hi), rgen::GetRandVal(lo, hi)};
}

void GenerateTestData(int Amount, std::ostream& out, const int lo, const int hi) {
    if (!out.good()) {
        std::cerr << "error write file" << std::endl;
        return;
    }
    out << "COUNT=" << Amount << " ";
    for (int i = 0; i < Amount; i++) {
        out << GeneratePoint3D(lo, hi) << " ";
    }
}

void PrintTestData(std::istream& in) {
    if (!in.good()) {
        std::cerr << "error read file" << std::endl;
        return;
    }
    std::cout << in.rdbuf();
}

static int ScanHeader(pfc::scanner& scan) {
    if (scan.current_symbol().get_keyword() != "COUNT") {
        std::cerr << "Error: Header must start with 'COUNT'" << std::endl;
        return -1;
    }
    scan.next_symbol();

    if (!scan.is('=')) {
        std::cerr << "Error: Expected '=' after COUNT" << std::endl;
        return -1;
    }
    scan.next_symbol();

    if (!scan.is_integer()) {
        std::cerr << "Error: Expected integer value for count" << std::endl;
        return -1;
    }
    int val = scan.get_integer();
    scan.next_symbol();

    return val;
}

static bool ScanPoint3D(pfc::scanner& scan, Point3D& p) {
    if (!scan.is('(')) {
        std::cerr << "Error: Expected '(' at start of point" << std::endl;
        return false;
    }
    scan.next_symbol();

    if (!scan.is_integer()) {
        std::cerr << "Error: Expected integer for x coordinate" << std::endl;
        return false;
    }
    p.x = scan.get_integer();
    scan.next_symbol();

    if (!scan.is(',')) {
        std::cerr << "Error: Expected ',' after x coordinate" << std::endl;
        return false;
    }
    scan.next_symbol();

    if (!scan.is_integer()) {
        std::cerr << "Error: Expected integer for y coordinate" << std::endl;
        return false;
    }
    p.y = scan.get_integer();
    scan.next_symbol();

    if (!scan.is(',')) {
        std::cerr << "Error: Expected ',' after y coordinate" << std::endl;
        return false;
    }
    scan.next_symbol();

    if (!scan.is_integer()) {
        std::cerr << "Error: Expected integer for z coordinate" << std::endl;
        return false;
    }
    p.z = scan.get_integer();
    scan.next_symbol();

    if (!scan.is(')')) {
        std::cerr << "Error: Expected ')' at end of point" << std::endl;
        return false;
    }
    scan.next_symbol();

    return true;
}

void PrintMatchingPoints(Point3D const* points, int n) {
    if (points == nullptr || n <= 0) {
        return;
    }
    std::cout << "Points with matching dimensions:" << std::endl;
    for (int i = 0; i < n; i++) {
        bool firstMatch = true;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (points[i].x == points[j].x ||
                points[i].y == points[j].y ||
                points[i].z == points[j].z) {

                if (firstMatch) {
                    std::cout << points[i] << " -> ";
                    firstMatch = false;
                }
                std::cout << points[j] << " ";
            }
        }
        if (!firstMatch) {
            std::cout << std::endl;
        }
    }
}

Point3D* ScanTestData(std::istream& in, int& count) {
    if (!in.good()) {
        std::cerr << "error read file" << std::endl;
        return nullptr;
    }

    pfc::scanner scan{};
    scan.register_keyword("COUNT");
    scan.set_istream(in);
    count = 0;

    if (scan.is_eof()) {
        return nullptr;
    }

    int amount = ScanHeader(scan);
    if (amount <= 0) {
        return nullptr;
    }

    Point3D* pointArray = new Point3D[amount];

    for (int i = 0; i < amount; i++) {
        if (scan.is_eof()) {
            std::cerr << "Error: Unexpected end of file" << std::endl;
            delete[] pointArray;
            return nullptr;
        }
        if (!ScanPoint3D(scan, pointArray[i])) {
            delete[] pointArray;
            return nullptr;
        }
    }

    count = amount;
    return pointArray;
}