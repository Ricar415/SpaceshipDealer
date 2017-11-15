#include "sale.hpp"

sale::sale(string vn,string n,date d){
    strcpy(&vrn,vn);
    strcpy(&rn,n);
    saledate = d;
};
sale::~sale(){};
void sale::buy(date){};
