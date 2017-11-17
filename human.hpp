#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "owner.hpp"
#include <string>
using namespace std;

class human: public owner{
public:
    human(string n);
    void modify(string n);
};

#endif
