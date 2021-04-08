#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "Status.h"
#include <string>

class Keypad {
public:
virtual Status getDigitInput(int &digit) = 0;
virtual Status getStringInput(std::string &input) = 0;
};

#endif //_KEYPAD_H
