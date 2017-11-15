#ifndef ALIEN_HPP
#define ALIEN_HPP
#include "owner.hpp"
#include <string>
using namespace std;

class alien: public owner{
public:
    alien(string n);
    ~alien();
    void modify(string n);
};

#endif
