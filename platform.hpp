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
    vector<vehicle*> vehicles;
    vector<owner> owners;
public:
    void lavailable(); //list functions (default by rn)
    void lbyocapacity();
    void lbyowner(string rn);

	void lsales(date start, date end);
	void listowners();
    void lsales(); //end of list functions
	void createhuman(string rn);
	void createalien(string rn);
	bool checkowner(string rn);
	bool checkvehicle(string rn);
	int ownerposition(string rn);
	void modifyowner(int position, string nrn);
	void removeowner(int position);

	void removevehicle(int position);
	int vehicleposition(string rn);
    int checktype(string rn);
	int checkchar(char position);
	void createfighter(int ms, int propulsiont, int pricet, weapon weapon1,weapon weapon2, string rn);
	void createcarrier(int ml,int cs, bool es, int propulsiont, int maxcrewt, int pricet, string rn);
	void createdestroyer(vector<weapon> weapons, int propulsiont, int maxcrewt, int pricet, string rn);
	void createstation(int maxp,int hn,bool es, int propulsiont, int maxcrewt, int pricet, string rn);
	bool checksales(string vrn);
	void sell(string vrn, string rn, date saledate);
	bool checkdate(date d);
	int checkvehicletype(int position);

	void modifyvehicle(int position, int code, int value);
	void modifyvehicle(int position, string nvrn);
	void modifyvehicle(int position, bool es);
	void modifyvehicle(int position, int pos, weapon nw);

	void showweapons(int position);
	int stationhn(int position);

	void modifypropulsion(int position, int npropulsion);
	void modifymcrew(int position, int nmaxcrew);
	void modifyprice(int position, int nprice);
	bool lessthan(int a, int b);

	int vsize();
	int osize();
	int ssize();

	string vregister(int position);
	string oregister(int position);
	string sregister(int position);
};

#endif
