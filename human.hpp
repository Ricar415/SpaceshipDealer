#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "owner.hpp"

using namespace std;

class human: public owner{

public:

    ~human(){}
    human(string n, string p); /// parametrized constructor 
	void show(); /// prints the information of the human (polymorphed)

};

#endif
