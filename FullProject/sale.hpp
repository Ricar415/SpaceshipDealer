#ifndef SALE_HPP
#define SALE_HPP
#include "vehicle.hpp"

struct date{
	int day;
	int month;
	int year;
};
class sale{
    friend class platform;
private:
    date saledate;
    char vrn[9];
    char hrn[10];
    char arn[11];
public:
    sale(char*,char*,date);
    ~sale();
    void buy(date);//will ask for owner NIF/NIE, check if it corresponds to a registered owner, list available vehicles and ask for vehicle RN, then call function sale(NIE/NIF,RN,date)
};

#endif
