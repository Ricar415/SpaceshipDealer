#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"
#include <string>
#include <vector>
#include "weapon.hpp"
using namespace std;
class destroyer: public vehicle{
	vector<weapon> weaponr;
public:
    destroyer(vector<weapon> weapons, int propulsiont, int maxcrewt, int pricet, string rn);
	int nweapons();
	void modifyweapons(int position, int type);
	void showweapon(int position);
	void modifyweapon(int position, weapon w);
	void addweapon(int weapontype);
	void removeweapon(int weaponposition);
	void show();
	int ocapacity();
	bool check(string vrn);
	string reg();
};

#endif
