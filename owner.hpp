#ifndef OWNER_HPP
#define OWNER_HPP
#include <string>
using namespace std;

class owner{
protected:
    string rn;
public:
	void modify(string nrn);
	bool check(string crn);
	void show();
};

#endif
