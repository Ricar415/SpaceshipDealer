#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include "sale.hpp"
#include <cstring>
#include <vector>
#include "owner.hpp"
#include "vehicle.hpp"
using namespace std;

class platform{
    vector<sale> sales;
    vector<vehicle> vehicles;
    vector<owner> owners;
public:
    void menu();
    void lavailable(); //list functions
    void lbydate(date,date);
    void lbyocapacity();
    void lbyowner(string o);
    void lforhuman();
    void lforalien();
    void lsales(); //end of list functions
    bool createowner();
    bool modifyowner();
    int checktype(string rn);
    bool ask();
    bool ask(bool i);
};

#endif
