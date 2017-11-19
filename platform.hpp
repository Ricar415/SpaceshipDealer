#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include "sale.hpp"
#include <cstring>
#include <vector>
#include "owner.hpp"
#include "vehicle.hpp"
using namespace std;

class platform{
    vector<sale> sales;
    vector<vehicle> vehicles;
    vector<owner> owners;
public:
    bool lavailable(); //list functions (default by rn)
    bool lbydate(date start ,date end);
    bool lbyocapacity();
    bool lbyowner(string o);
//    void lforhuman(); //will only include them if needed
//    void lforalien();
	bool listowners();
    bool lsales(); //end of list functions
	bool createhuman(string rn); //CON INTERFAZ
	bool createalien(string rn); //CON INTERFAZ
	bool checkowner(string rn); //CON INTERFAZ
	int ownerposition(string rn); //CON INTERFAZ
	void modifyowner(int position, string nrn); //CON INTERFAZ
	void removeowner(int position); //CON INTERFAZ
	int createvehicle();
	int createvehicle(int type);
	int modifyvehicle();
	int removevehicle();
    int checktype(string rn); //checks registration number, 0 if non.valid, 1 if human, 2 if alien, 3 if vehicle
    int checkchar(char position); //check if a char is 1 a number, 2 a letter or 0 any other
};

#endif
