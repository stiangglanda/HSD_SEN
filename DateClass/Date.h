//
// Created by stiangglanda on 2026-04-03.
//

#ifndef DATECLASS_DATE_H
#define DATECLASS_DATE_H



class Date {

};

class Date {
public:
    // Constructor
    Date(size_t const day, size_t const month, size_t const year);

    // Accessor functions getDay, getMonth, getYear
    // ...

    // Comparison function
    // returns -1 if current date (this) is before d, +1 if it is after d, 0 if it is equal
    int Compare(Date const& d) const;

    // Write date to an output stream
    void Print(std::ostream& out) const;

private:
    size_t mDay;
    size_t mMonth;
    size_t mYear;
};

// Output operator
std::ostream &operator<<(std::ostream& out, Date const& date);


#endif //DATECLASS_DATE_H
