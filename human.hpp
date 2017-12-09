#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "owner.hpp"

using namespace std;

class human: public owner{

public:

    human(string n); /// parametrized constructor 
	void show(); /// prints the information of the human (polymorphed)

};

#endif
