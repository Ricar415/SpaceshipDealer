#include "vehicle.hpp"
#include <string>
using namespace std;

bool vehicle::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
void vehicle::modifyp(int){}
void vehicle::modifymc(int){}
void vehicle::modifytype(int){}
void vehicle::modifyprice(int){}
void vehicle::modifyowner(string o){
    owner = o;
}
void vehicle::modifyavailability(){}
void vehicle::modifylist(string n){}

