#ifndef INTERFACE_H
#define INTERFACE_H
#include "sale.hpp"
#include <cstring>
#include <vector>
#include "owner.hpp"
#include "vehicle.hpp"
#include "platform.hpp"

class interface {
	platform *platforme;
public:
	interface(platform *platform);
	void menu(platform *platforme); //main conducting part of the user interface
	bool lbydate(platform *platforme); // asks date of start and end and then calls platform::lbydate with given parameters
	bool lbyowner(platform *platforme); // asks the owner to list and then calls platform::lbyowner with given
	bool createowner(platform *platforme); //asks register number and then calls platform::createowner
    bool modifyowner(platform *platforme); //asks owner to modify and new register number and then calls platform::modifyowner
    bool removeowner(platform *platforme); //asks owner to remove and calls platform::removeowner
	bool createvehicle(platform *platforme); //asks every part of the vehicle information needed and then calls vehicle(*given parameters*)
	bool modifyvehicle(platform *platforme); //asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters
	bool removevehicle(platform *platforme); //asks vehicle to remove and calls platform::removevehicle
	bool ask(); // asks if the user wants to continue with the program
};
#endif
