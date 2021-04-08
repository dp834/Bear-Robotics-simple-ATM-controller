#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "Status.h"
#include <string>

class Keypad {
public:
Status getDigitInput(int &digit);
Status getStringInput(std::string &input);
};

#endif //_KEYPAD_H
