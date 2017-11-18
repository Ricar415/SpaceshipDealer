#ifndef OWNER_HPP
#define OWNER_HPP
#include <string>
using namespace std;

class owner{
    friend class platform;
protected:
    string rn;
public:
	void modify(string nrn);
};

#endif
