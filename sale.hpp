#ifndef SALE_HPP
#define SALE_HPP

#include <string>
#include <sstream>

#include "vehicle.hpp"

using namespace std;

struct date { int day, month, year; }; // plain day/month/year structure
// struct date included here because it will only be used by code interacting with sales

class sale{

private:

    date saledate;
	string vrn, rn;

public:

    // -- Constructor --
    sale(string vn, string n, date d); /// parametrized constructor

    // -- Auxiliary functions --
	string rvrn(); /// returns the register number of the sold vehicle
	string rorn(); /// returns the register number of the owner
	bool greaterequalthan(date date); /// returns 1 if the given date is >= the saledate

    // -- Show functions --
	void showsale(); /// prints the information of the sale in the screen

    // -- Formatting functions --
	string reg(); /// returns a formatted string with the information of the sale
    string to_string(int a); /// not needed in last c++ versions

};
#endif
