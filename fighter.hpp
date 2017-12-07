#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <string>

#include "weapon.hpp"
#include "vehicle.hpp"

using namespace std;

class fighter:public vehicle{

private:

	weapon weapon1, weapon2;
    int maxspeed;

public:

	// -- Constructor --
    fighter(int dmaxspeed, int propulsiont, int pricet, weapon dweapon1, weapon dweapon2, string n); // parametrized constructor

	// -- Modify functions --
	void modifyms(int ms); // modifies the maximum speed to the given one
	void modifyweapon(int pos, weapon w); // modifies the given weapon number type to the given one

	// -- Auxiliary functions --
	int ocapacity(); // returns offensive capacity
	int nweapons() { return 2; } // returns number of weapons for iteration purposes

	// -- Show functions --
	void show(); // prints the information of the fighter in the screen
	void showweapon(int wn); // prints the information of the given weapon number in the screen

	// -- Formatting functions --
	string reg(); // returns a formatted string with the information of the fighter

};
#endif
