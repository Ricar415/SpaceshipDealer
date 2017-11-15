#include "human.hpp"
#include <string>
using namespace std;
human::human(string n){
    rn = n;
};
human::~human(){
};
void human::modify(string n){
    rn = n;
};
