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
	friend class platform;
private:
    date saledate;
    string vrn;
    string rn;
public:
    sale(string vn, string n, date d);
    ~sale();
    void buy(date);//will ask for owner NIF/NIE, check if it corresponds to a registered owner, list available vehicles and ask for vehicle RN, then call function sale(NIE/NIF,RN,date)
};

#endif
