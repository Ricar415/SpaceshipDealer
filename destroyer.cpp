#include "destroyer.hpp"
#include <string>
using namespace std;
destroyer::destroyer(int nweapons, vector<weapon> weapons, string rn){
	vrn = rn;
	nw = nweapons;
	weaponr = weapons;
}
void destroyer::modifynw(int nweapons){
	nw = nweapons;
}
void destroyer::modifyvrn(string nvrn) {
	vrn = nvrn;
}
void destroyer::modifyweapons(int position, int type) {
	weapon a(type);
	weaponr.erase(weaponr.begin()+position);
	weaponr.push_back(a);
}
