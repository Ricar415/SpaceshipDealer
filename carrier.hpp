#ifndef CARRIER_HPP
#define CARRIER_HPP

#include "vehicle.hpp"

using namespace std;

class carrier: public vehicle{

private:

	int maxload, cruisingspeed;
    bool energyshield;

public:

    // -- Constructor and Destructor --
    ~carrier(){}
    carrier(int ml, int cs, bool es, int propulsiont, int maxcrewt, int pricet, owner *nowner, string vn); /// parametrized constructor
    
	// -- Modify functions --
	void modifyml(int ml); /// modifies the maximum load to the given one
    void modifycs(int cs); /// modifies the cruising speed to the given one
    void modifyes(bool es); /// modifies the energy shield to the given one

	// -- Show functions --
	void show(); /// prints the information of the carrier in the screen

	// -- Formatting functions --
	string reg(); /// returns formatted string with the information of the carrier

};
#endif
