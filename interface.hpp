#ifndef INTERFACE_H
#define INTERFACE_H
class interface {
public:
	void menu(); //main conducting part of the user interface
	void lbydate(); // asks date of start and end and then calls platform::lbydate with given parameters
	void lbyowner(); // asks the owner to list and then calls platform::lbyowner with given
	bool createowner(); //asks register number and then calls platform::createowner
    bool modifyowner(); //asks owner to modify and new register number and then calls platform::modifyowner
    bool removeowner(); //asks owner to remove and calls platform::removeowner
	bool createvehicle(); //asks every part of the vehicle information needed and then calls vehicle(*given parameters*)
	bool modifyvehicle(); //asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters
	bool removevehicle(); //asks vehicle to remove and calls platform::removevehicle
	bool ask(); // asks if the user wants to continue with the program
};
#endif
