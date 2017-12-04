#include "sale.hpp"
#include <string>
#include <iostream>

using namespace std;
sale::sale(string vn,string n,date d){
    vrn = vn;
    rn = n;
    saledate = d;
}
bool sale::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
void sale::showsale() {
	cout << "Vehicle sold: " << vrn << endl << "Owner: " << rn << endl << "Date of sale: " << saledate.day << "/" << saledate.month << "/" << saledate.year << endl;
}
bool sale::greaterequalthan(date date) {
	if (saledate.year > date.year || saledate.year == date.year) {
		return 1;
	}
	else if (saledate.month > date.month || saledate.month == date.month) {
		return 1;
	}
	else if (saledate.day > date.day || saledate.day > date.day) {
		return 1;
	}
	else {
		return 0;
	}
}
bool sale::checkowner(string orn) {
	if (orn == rn) {
		return 1;
	}
	else return 0;
}
string sale::rvrn() {
	return vrn;
}
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