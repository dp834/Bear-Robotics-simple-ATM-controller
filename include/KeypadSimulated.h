#ifndef _KEYPADSIMULATED_H
#define _KEYPADSIMULATED_H

#include "Status.h"

#include "Keypad.h"


class KeypadSimulated: public Keypad {
public:
KeypadSimulated();
Status getDigitInput(int &digit);
Status getStringInput(std::string &input);
};

#endif //_KEYPADSIMULATED_H
