#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <cstring>
#include <string>
#include "weapon.hpp"

using namespace std;

class vehicle {
protected:
	string vrn;
	int propulsion;
	int maxcrew;
	int price;
	int type;
public:
	bool check(string cvrn);
	int checktype();
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
};

#endif
