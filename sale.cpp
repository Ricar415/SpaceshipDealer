#include "sale.hpp"
#include <string>
using namespace std;
sale::sale(string vn,string n,date d){
    vrn = vn;
    rn = n;
    saledate = d;
}
sale::~sale(){}
void sale::buy(date){}
