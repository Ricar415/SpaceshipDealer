#include <string>
#include <iostream>

#include "sale.hpp"

using namespace std;

// -- Constructor --
sale::sale(string vn,string n,date d){
    vrn = vn;
    rn = n;
    saledate = d;
}

// -- Auxiliary functions --
string sale::rvrn() { return vrn; }
string sale::rorn() { return rn; }
bool sale::greaterequalthan(date date) {
	if (saledate.year >= date.year) { return 1; }
	else if (saledate.month >= date.month) { return 1; }
	else if (saledate.day >= date.day) { return 1; }
	else { return 0; }
}

// -- Show functions --
void sale::showsale() { // Vehicle information, Owner information, Date of sale DD/MM/YYYY
	cout << "Vehicle sold: " << vrn << endl << "Owner: " << rn << endl << "Date of sale: " << saledate.day << "/" << saledate.month << "/" << saledate.year << endl;
}

// -- Formatting functions --
string sale::reg() { // Returns string of formatted parameters
    string temp, space = " ", day = to_string(saledate.day), month = to_string(saledate.month), year = to_string(saledate.year);
    temp = vrn;
    temp += space;
    temp += rn;
    temp += space;
    temp += day;
    temp += space;
    temp += month;
    temp += space;
    temp += year;
    return temp;
}
string sale::to_string(int a){
    stringstream stream;
    stream << a;
    return stream.str();
}
