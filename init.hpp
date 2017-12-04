#ifndef INIT_HPP
#define INIT_HPP
#include "platform.hpp"

class init {
	platform *platforme;
public:
	init(platform *_platforme);
	void initialize();
	void registry();
};

#endif