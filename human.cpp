#include "human.hpp"

human::human(string n){
    strcpy(&rn,n);
};
human::~human(){
};
void human::modify(string n){
    strcpy(&rn,n);
};
