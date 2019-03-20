#ifndef _SALES_DATA_H
#define _SALES_DATA_H
#include <string>
#include <iostream>
struct sales_data {
    sales_data() = default;
    sales_data(const std::string &name): bookNo(name) {};
    sales_data(const std::string &name, unsigned num, double unitprice):
        bookNo(name), units_sold(num), revenue(unitprice * units_sold) {};
    sales_data(std::istream &is) {is >> bookNo >> units_sold >> revenue;};
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
    std::string isbn() const {return bookNo;};
    struct sales_data &combine (const struct sales_data &sec);
};

inline std::ostream &print(std::ostream &os, const struct sales_data &book)
{
    os << book.isbn() << " units: " << book.units_sold <<  " total: " << book.revenue << "$";
    return os;
}

#endif
