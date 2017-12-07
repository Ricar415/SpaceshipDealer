#ifndef STATION_HPP
#define STATION_HPP

#include <string>

#include "vehicle.hpp"

using namespace std;

class station: public vehicle{

private:

    int maxp, hangarn;
    bool energyshield;

public:

	// -- Constructor --
    station(int mp, int hn, bool es, int propulsiont, int maxcrew, int price, string n); // parametrized constructor

	// -- Modify functions --
    void modifymp(int mp); // modifies the maximum passenger number to the given one
    void modifyhn(int hn); // modifies the hangar number to the given one
    void modifyes(bool es); // modifies the energy shield to the given one

	// -- Auxiliary functions --
	int hn(); // returns the number of hangars

	// -- Show functions --
	void show(); // prints the information of the station in the screen

	// -- Formatting functions --
	string reg(); // returns a formatted string with the information of the station

};
#endif
