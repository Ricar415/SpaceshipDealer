#ifndef INTERFACE_H
#define INTERFACE_H

#include <cstring>
#include <vector>

#include "platform.hpp"
#include "vehicle.hpp"
#include "owner.hpp"
#include "sale.hpp"

class interface {

private:

	platform *platforme; // the platform with which the interface will interact

public:

	// -- Constructor --
	interface(platform *platform); // parametrized constructor

	// -- Menu --
	void menu(); // main conducting part of the user interface

private:

	// -- Menu --
	bool ask(); // asks if the user wants to continue with the program
	void initfile(); // gives the option of charging vehicles, owners and sales from other files different than the ones that the program rewrites and reads automatically


	// -- List functions --
	bool lbydate(); // asks date of start and end and then calls platform::lbydate with given parameters
	bool lbyowner(); // asks the owner to list and then calls platform::lbyowner with given parameters

	void showweapons(string vrn);  // calls platform::showweapons at position returned by platform::vehicleposition with the given vrn


	// -- Create functions --
	bool createowner(); // asks register number and then calls platform::createowner
	bool createvehicle(); // asks every part of the vehicle information needed and then calls vehicle(*given parameters*)


	// -- Modify functions --
    bool modifyowner(); // asks owner to modify and new register number and then calls platform::modifyowner
	bool modifyvehicle(); // asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters

	int modifyprice(); // asks new price and calls platofrm::modifyprice with given parameter
	int modifymaxcrew(); // asks new maximum crew and calls platform::modifymcrew with given parameter
	int modifypropulsion(); // asks new propulsion and calls platform::modifypropulsion with given parameter


	// -- Remove functions --
    bool removeowner(); // asks owner to remove and calls platform::removeowner
	bool removevehicle(); // asks vehicle to remove and calls platform::removevehicle


	// -- Sell functions --
	bool sell(); // asks owner rn, checks it, then asks vrn, checks it, then asks saledate and calls platform::sell with given parameters
	bool addfighter(string rn, date saledate, int hn); // will only be called after buying a station and will give you the option to buy fighters in addition to that, asks how many, vrn and creates new sales for them with the same saledate and owner rn 

};
#endif
