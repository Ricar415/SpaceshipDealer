#ifndef DESTROYER_HPP
#define DESTROYER_HPP

#include <string>
#include <vector>

#include "vehicle.hpp"
#include "weapon.hpp"

using namespace std;

class destroyer: public vehicle{

private:

	vector<weapon> weaponr;

public:

	// -- Constructor --
    destroyer(vector<weapon> weapons, int propulsiont, int maxcrewt, int pricet, string rn); // parametrized constructor
	
	// -- Modify functions --
	void modifyweapon(int position, weapon w); // modifies the weapon in the given position to the given one
	void addweapon(int weapontype); // adds weapon with the given type at the end of the weapon vector
	void removeweapon(int weaponposition); // removes weapon from the weapon vector in the given position

	// -- Auxiliary functions --
	int ocapacity(); // returns offensive capacity
	int nweapons(); // returns number of weapons for iteration purposes
	
	// -- Show functions --
	void show(); // prints the information of the destroyer in the screen
	void showweapon(int position); // prints the information of the weapon in the given position in the screen

	// -- Formatting functions --
	string reg(); // returns formatted string with the information of the destroyer

};
#endif
