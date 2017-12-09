#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <limits>

#include "carrier.hpp"
#include "destroyer.hpp"
#include "fighter.hpp"
#include "station.hpp"

#include "human.hpp"
#include "alien.hpp"

#include "sale.hpp"

using namespace std;

class platform{

private:

    vector<sale> sales;
    vector<vehicle*> vehicles; /// Vector of pointers to allow pure virtual functions and polymorphism
    vector<owner*> owners; /// Vector of pointers to allow pure virtual functions and polymorphism

public:

    // -- Destructor --
	~platform();

    // -- List functions --
    void lavailable(); /// calls vehicle::show() for every available vehicle in vehicles vector by register number order
	void lall(); /// calls vehicle::show() for every vehicle in vehicles vector by register number order
    void lbyocapacity(); /// calls vehicle::show() for every vehicle in vehicles vector from the one with highest offensive capacity to the one with the lowest o.capacity
    void lbyowner(string rn); /// calls vehicle::show() for every vehicle bought by the owner with the given rn

	void showweapons(int position); /// calls funcion weapon::show of every weapon of the vehicle at the given position in the vehicles vector

	void listowners(); /// calls owner::show() for every owner in the owners vector by register number order

    void lsales(); /// calls sale::show() for every sale in sales vector
	void lsales(date start, date end); /// calls sale::show() for every sale in sales vector between the given dates


    // -- Create functions --
	void createhuman(string rn); /// dynamically creates a human with the given rn and adds it at the end of the owners vector
	void createalien(string rn); /// dynamically creates an alien with the given rn and adds it at the end of the owners vector

	void createfighter(int ms, int propulsiont, int pricet, weapon weapon1,weapon weapon2, string rn); /// dynamically creates a fighter with the given parameters and adds it at the end of vehicles vector
	void createcarrier(int ml,int cs, bool es, int propulsiont, int maxcrewt, int pricet, string rn); /// dynamically creates a carrier with the given parameters and adds it at the end of the vehicles vector
	void createdestroyer(vector<weapon> weapons, int propulsiont, int maxcrewt, int pricet, string rn); /// dynamically creates a destroyer with the given parameters and adds it at the end of the vehicles vector
	void createstation(int maxp,int hn,bool es, int propulsiont, int maxcrewt, int pricet, string rn); /// dynamically creates a station with the given parameters and adds it at the end of the vehicles vector
	

    // -- Modify functions --
	void modifyowner(int position, string nrn); /// modifies the rn of the owner at the given position in the owners vehicle

	void modifyvehicle(int position, int code, int value); /// modifies the vehicle at the given position in the vehicles vector, the value to be modified depends on the given code
	void modifyvehicle(int position, string nvrn); /// modifies the rn of the vehicle at the given position in the vehicles vector
	void modifyvehicle(int position, bool es); /// modifies the energy shield of the vehicle at the given position in the vehicles vector
	void modifyvehicle(int position, int pos, weapon nw); /// modifies the weapon at the given position of the vehicle at the given position in the vehicles vector

	void modifypropulsion(int position, int npropulsion); /// modifies propulsion type of the vehicle at the given position in the vehicles vector
	void modifymcrew(int position, int nmaxcrew); /// modifies maximum crew of the vehicle at the given position in the vehicles vector
	void modifyprice(int position, int nprice); /// modifies price of the vehicle at the given position in the vehicles vector


    // -- Remove functions --
	void removeowner(int position); /// removes owner at the given position in the owners vehicle
	void removevehicle(int position); /// removes vehicle from the vehicles vector at the given position


    // -- Sell functions --
	void sell(string vrn, string rn, date saledate); /// creates a sale with the given parameters and adds it at the end of sales vector


    // -- Check functions --
	bool checkowner(string rn); /// returns 1 if there is an owner with the given rn in owners vector and 0 otherwise
	bool checkvehicle(string rn); /// returns 1 if there is a vehicle with the given rn in vehicles vector and 0 otherwise
	bool checksales(string vrn); /// returns 0 if the vehicle is available and 1 otherwise

	bool checkdate(date d); /// returns 1 if a date is valid and 0 otherwise
    int checktype(string rn); /// returns 1 if the string is formatted as a human rn, 2 if as an alien rn, 3 if as a vehicle rn and 0 otherwise
	int checkchar(char position); /// returns 0 if not a letter or a number, 1 if a number and 2 if a letter


    // -- Auxiliary functions --
	int vehicleposition(string rn); /// returns position in the vehicles vector of the vehicle with the given rn
	int ownerposition(string rn); /// returns position in owners vector of owner with the given rn

	int vsize(); /// returns the size of the vehicles vector for iteration purposes
	int osize(); /// returns the size of the owners vector for iteration purposes
	int ssize(); /// returns the size of the sales vector for iteration purposes

	int destroyerwsize(int position); /// returns the size of the weapon vector of a destroyer in the given position for iteration purposes

	int stationhn(int position); /// returns the number of hangars of the vehicle at the given position in the vehicles vector

	int checkvehicletype(int position); /// returns the type of the vehicle at the given position in the vehicles vector


	/// -- File formatting functions --
	string vregister(int position); /// returns formatted string with the information of the vehicle at the given position
	string oregister(int position); /// returns formatted string with the information of the owner at the given position
	string sregister(int position); /// returns formatted string with the information of the sale at the given position

};
#endif
