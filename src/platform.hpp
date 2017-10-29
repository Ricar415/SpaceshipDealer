#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include "sale.hpp"
#include "initmenu.hpp"
class platform{
    friend class initmenu;
public:
    void lavailable(); //list functions
    void lbydate(date,date);
    void lbyocapacity();
    void lbyowner();
    void lforhuman();
    void lforalien();
    void lsales(); //end of list functions
};

#endif
