#ifndef FIGHTER_HPP
#define FIGHTER_HPP
#include "vehicle.hpp"
#include <string>
#include "weapon.hpp"
using namespace std;

class fighter:public vehicle{
private:
	weapon weapon1, weapon2;
    int maxspeed;
public:
    fighter(int dmaxspeed, int propulsiont, int pricet, weapon dweapon1, weapon dweapon2, string n);
	void show();
	void modifyms(int ms);
	void modifyw1(int type);
	void modifyw2(int type);
	void showweapon(int wn);
	void modifyweapon(int pos, weapon w);
	int ocapacity();
	bool check(string vrn);
	string reg();
};

#endif
