#ifndef _SCREEN_H
#define _SCREEN_H

#include "Status.h"
#include <string>

class Screen {
public:
virtual Status setScreenText(const std::string text) = 0;
};

#endif //_SCREEN_H
