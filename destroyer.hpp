#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"
#include <string>
#include <vector>
#include "weapon.hpp"
using namespace std;
class destroyer: public vehicle{
	vector<weapon> weaponr;
	int nw;
	int const type = 2;
public:
    destroyer(int nweapons, vector<weapon> weapons, string rn);
    void modifynw(int nw);
	void modifyvrn(string nvrn);
	void modifyweapons(int position, int type);
};

#endif
