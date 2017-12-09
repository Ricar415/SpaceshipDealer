#ifndef INIT_HPP
#define INIT_HPP

#include <fstream>
#include <iostream>

#include "platform.hpp"

class init {

private:

	platform *platforme; /// the platform with which the initializer will interact

public:

	// -- Constructor --
	init(platform *_platforme); /// parametrized constructor

	// -- Read functions --
	void initialize(); /// read and load values from default files
	void initialize(string VehicleFile, string OwnerFile, string SaleFile); /// read and load values from given files

	// -- Write functions --
	void registry(); /// write values
};

#endif