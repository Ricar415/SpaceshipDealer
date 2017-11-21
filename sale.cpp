#include "sale.hpp"
#include <string>
using namespace std;
sale::sale(string vn,string n,date d){
    vrn = vn;
    rn = n;
    saledate = d;
}
bool sale::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
