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
    void menu();
    void lavailable(); //list functions (default by rn)
    void lbydate(date start ,date end);
    void lbyocapacity();
    void lbyowner(string o);
//    void lforhuman(); //will only include them if needed
//    void lforalien();
	void listowners();
    void lsales(); //end of list functions
    int createowner();
    int modifyowner();
	int removeowner();
	int createvehicle();
	int modifyvehicle();
	int removevehicle();
    int checktype(string rn); //checks registration number, 0 if non.valid, 1 if human, 2 if alien, 3 if vehicle
    int checkchar(char position); //check if a char is 1 a number, 2 a letter or 0 any other
    bool ask(); // asks if the user wants to continue with the program
    bool ask(bool i); //shows wether the last functionality was successfull, asks if continue
};

#endif
