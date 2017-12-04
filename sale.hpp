#ifndef SALE_HPP
#define SALE_HPP
#include "vehicle.hpp"
#include <string>
using namespace std;

struct date{
	int day;
	int month;
	int year;
};
class sale{
private:
    date saledate;
    string vrn;
    string rn;
public:
	bool check(string cvrn);
    sale(string vn, string n, date d);
	void showsale();
	bool greaterequalthan(date date);
	bool checkowner(string orn);
	string rvrn();
	string reg();
};

#endif
