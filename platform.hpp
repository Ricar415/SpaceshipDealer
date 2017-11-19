#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "sale.hpp"
#include <cstring>
#include <vector>
#include "owner.hpp"
#include "vehicle.hpp"
#include "weapon.hpp"

using namespace std;

class platform{
    vector<sale> sales;
    vector<vehicle> vehicles;
    vector<owner> owners;
	vector<weapon> weapons;
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
    int checktype(string rn); //CON INTERFAZ
    int checkchar(char position); //CON INTERFAZ
	void createfighter(int ms,weapon weapon1,weapon weapon2, string rn);
	void createcarrier(int ml,int cs,string rn);
	void createdestroyer();
	void createstation(int maxp,int hn,bool eshield,string rn);
};

#endif
