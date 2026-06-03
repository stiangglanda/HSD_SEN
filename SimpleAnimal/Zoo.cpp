#include <algorithm>
#include <sstream>
#include "Zoo.h"
using namespace std;

Zoo::~Zoo() {
    for (auto ani : mAnimals) {
        delete ani;
    }
    mAnimals.clear();
}

void Zoo::Add(Animal const *ani) {
    if (ani == nullptr) {
        throw invalid_argument{"null pointer param in Zoo::Add(...)"};
    }
    mAnimals.push_back(ani);
}

std::string Zoo::ToString() const {
    ostringstream ost;
    ost << "This Zoo has " << mAnimals.size() << " animals:" << endl;
    for (auto ani : mAnimals) {
        ost << ani->ToString();
    }
    return ost.str();
}

Zoo::TCAniItor Zoo::cbegin() const {
    return mAnimals.cbegin();
}

Zoo::TCAniItor Zoo::cend() const {
    return mAnimals.cend();
}
