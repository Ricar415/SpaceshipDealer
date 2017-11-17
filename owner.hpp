#ifndef OWNER_HPP
#define OWNER_HPP
#include <string>
using namespace std;

class owner{
    friend class platform;
protected:
    string rn;
public:
    bool check(string rn); //check if an owner is registered
};

#endif
