#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "owner.hpp"

using namespace std;

class alien: public owner{

public:

    ~alien(){}
    alien(string n, string p); /// parametrized constructor
	void show(); /// prints the information of the alien (polymorphed)

};

#endif
