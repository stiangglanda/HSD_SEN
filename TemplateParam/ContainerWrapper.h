#ifndef CONT_WRAPPER_H
#define CONT_WRAPPER_H
#include <vector>
#include <algorithm>
#include <string>


//Template-Klasse mit non-type Parameter und Defaultwerten
//to do
template <typename TElem = int,
          typename TCont = std::vector<TElem>,
          typename TCont::size_type const size = 10>
class ContainerWrapper {
public:
    ContainerWrapper(TElem const initVal = TElem{}) {
        mCont.resize(size);
        std::fill(mCont.begin(), mCont.end(), initVal);
    }

    void Print(std::ostream& ost = std::cout, std::string const& delim = " ") {
        if (!ost.good()) {
            throw std::ios::failure{"error in Print - ostream"};
        }

        copy(mCont.cbegin(), mCont.cend(), std::ostream_iterator<TElem>(ost, delim.c_str()));
        ost << std::endl;
    }
private:
    TCont mCont;
};

#endif //CONT_WRAPPER_H