//
// Created by stiangglanda on 2026-03-21.
//

#include "TestData.h"
#include "RandomGen.h"
#include "scanner.h"

const int low=-0;
const int high=50;

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

static int ScanHeader(pfc::scanner& scan) {
    int val=0;

    if (scan.current_symbol().get_keyword()=="COUNT") {
        scan.next_symbol();
        if (scan.is('=')) {
            scan.next_symbol();
            val=scan.get_integer();
            scan.next_symbol();
        } else {
            std::cerr << "Error ScanHeader =";
        }
    } else {
        std::cerr << "Error ScanHeader";
    }
    return val;
}

static Point3D ScanPoint3D(pfc::scanner& scan) {
    if (!scan.is('(')) {
        std::cerr << "Error ScanPoint3D (";
    }
    scan.next_symbol();
    Point3D point;
    point.x = scan.get_integer();
    scan.next_symbol();
    if (!scan.is(',')) {
        std::cerr << "Error ScanPoint3D , y";
    }
    scan.next_symbol();
    point.y = scan.get_integer();
    scan.next_symbol();
    if (!scan.is(',')) {
        std::cerr << "Error ScanPoint3D , z";
    }
    scan.next_symbol();
    point.z = scan.get_integer();
    scan.next_symbol();
    if (!scan.is(')')) {
        std::cerr << "Error ScanPoint3D )";
    }
    scan.next_symbol();
    return point;
}

void ScanTestData(std::istream &in) {
    pfc::scanner scan{};
    scan.register_keyword("COUNT");
    scan.set_istream(in);

    int amount=ScanHeader(scan);
    Point3D* pointArray=new Point3D[amount];
    int index=0;

    while (!scan.is_eof()) {
        if (index >= amount) {
            std::cerr << "index >= amount" << std::endl;
            break;
        }

        pointArray[index]=ScanPoint3D(scan);
        index++;
    }

    if (index!=amount) {
        std::cerr << "index != amount" << std::endl;
    }

    PrintMatchingPoints(pointArray, index);

}

void PrintMatchingPoints(struct Point3D const *points, int n) {
    std::cout << "Points with matching dimensions:" << std::endl;
    for (int i=0; i<n; i++) {
        bool firstMatch = true;

        for (int j=0; j<n; j++) {
            if (i != j && (points[i].x==points[j].x || points[i].y==points[j].y || points[i].z==points[j].z)) {
                if (firstMatch) {
                    std::cout << std::endl << points[i] << " ->";
                    firstMatch=false;
                }
                std::cout << " " << points[j];
            }
        }
    }
}

