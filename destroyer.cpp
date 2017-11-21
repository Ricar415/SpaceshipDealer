#include "destroyer.hpp"
#include <string>
using namespace std;
destroyer::destroyer(vector<weapon> weapons, string rn){
	vrn = rn;
	weaponr = weapons;
	type = 2;
}
void destroyer::modifyweapons(int position, int type) {
	weapon a(type);
	weaponr[position] = a;
}
int destroyer::nweapons() {
	return weaponr.size();
}
void destroyer::showweapon(int position) {
	weaponr[position].show();
}
void destroyer::modifyweapon(int position, weapon w) {
	weaponr[position] = w;
}
void destroyer::addweapon(int weapontype) {
	weapon a(weapontype);
	weaponr.push_back(a);
}
void destroyer::removeweapon(int weaponposition) {
	weaponr.erase(weaponr.begin() + weaponposition);
}