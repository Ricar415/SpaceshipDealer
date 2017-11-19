#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"
#include <string>
#include <vector>
using namespace std;
class destroyer: public vehicle{
public:
    destroyer(int);
    void modify(int);
};

#endif
