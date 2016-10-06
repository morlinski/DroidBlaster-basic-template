#ifndef _PACKT_TYPES_HPP_
#define _PACKT_TYPES_HPP_

#include <cstdint>
#include <cstdlib>

typedef int32_t status;

const status STATUS_OK = 0;
const status STATUS_KO = -1;
const status STATUS_EXIT = -2;

struct Location {
	Location() :x(0.0f), y(0.0f) {};
	float x;
	float y;
	
};

//float test = rand();
#define RAND(pMax) (float(pMax) * float(rand()) / float(RAND_MAX))
#endif