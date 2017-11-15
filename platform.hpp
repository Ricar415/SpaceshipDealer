#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include "sale.hpp"
#include "initmenu.hpp"
#include <string>
using namespace std;

class platform{
public:
    void menu();
    void lavailable(); //list functions
    void lbydate(date,date);
    void lbyocapacity();
    void lbyowner(string o);
    void lforhuman();
    void lforalien();
    void lsales(); //end of list functions
};

#endif
