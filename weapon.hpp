#ifndef WEAPON_H
#define WEAPON_H

class weapon{

private:

	int type, ocapacity; // 1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)

public:

	// -- Constructor --
	weapon(int type); // parametrized constructor
	weapon(); // void constructor

	// -- Modify functions --
	void modify(int ntype);

	// -- Auxiliary functions --
	int returntype();
	int focapacity();

	// -- Show functions --
	void show();

};
#endif