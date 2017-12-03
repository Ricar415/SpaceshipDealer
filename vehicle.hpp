#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <cstring>
#include <string>
#include "weapon.hpp"

using namespace std;

class vehicle {
	friend class platform;
protected:
	string vrn;
	int propulsion;
	int maxcrew;
	int type;
	int price;
public:
	virtual bool check(string cvrn) = 0;
	int checktype();
	string rvrn();
	string showpropulsion();
	void modifypropulsion(int npropulsion);
	void modifymaxcrew(int nmaxcrew);
	void modifyprice(int nprice);
	virtual void show() = 0;
	virtual int nweapons();
	virtual void showweapon(int a);
	virtual void modifyweapon(int pos, weapon w);
	void modifyvrn(string nvrn);
	virtual void modifycs(int cs);
	virtual void modifyml(int ml);
	virtual void addweapon(int weapontype);
	virtual void removeweapon(int weaponposition);
	virtual void modifyms(int ms);
	virtual void modifymp(int mp);
	virtual void modifyhn(int hn);
	virtual void modifyes(bool es);
	virtual int ocapacity();
	virtual int hn();
};

#endif
