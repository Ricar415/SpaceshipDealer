#ifndef WEAPON_H
#define WEAPON_H

class weapon{
	int type;
	int ocapacity; // 1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)
public:
	weapon(int type);
	weapon();
	void modify(int ntype);
	void show();
};

#endif