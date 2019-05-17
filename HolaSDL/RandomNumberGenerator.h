#pragma once
#include "checkML.h"

//This class generate a random number
class RandomNumberGenerator {
public:
	RandomNumberGenerator();
	virtual ~RandomNumberGenerator();
	virtual int nextInt() = 0;
	virtual int nextInt(int low, int high) = 0;		//random between 2 numbers
};

