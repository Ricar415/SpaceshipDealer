#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "owner.hpp"

using namespace std;

class alien: public owner{

public:

    alien(string n); /// parametrized constructor
	void show(); /// prints the information of the alien (polymorphed)

};

#endif
