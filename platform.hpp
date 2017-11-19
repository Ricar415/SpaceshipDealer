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
	bool createhuman(string rn);
	bool createalien(string rn);
	bool checkowner(string rn);
	bool checkvehicle(string rn);
	int ownerposition(string rn);
	void modifyowner(int position, string nrn);
	void removeowner(int position);
	int createvehicle();
	int createvehicle(int type);
	int modifyvehicle();
	int removevehicle();
    int checktype(string rn);
	int checkchar(char position);
	void createfighter(int ms,weapon weapon1,weapon weapon2, string rn);
	void createcarrier(int ml,int cs, bool es, string rn);
	void createdestroyer();
	void createstation(int maxp,int hn,bool es,string rn);
	bool checksales(string rn, string vrn);
	void sell(string vrn, string rn, date saledate);
	bool checkdate(date d);
};

#endif
