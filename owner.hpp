#ifndef OWNER_HPP
#define OWNER_HPP
#include <string>
using namespace std;

class owner{

protected:

    string rn;

public:

	owner(string n); // parametrized constructor

	void modify(string nrn); // changes register number to the given

	string reg(); // returns formatted string with the information of the owner
	string rrn(); // returns register number

	virtual void show() = 0; // pure virtual show function

};

#endif
