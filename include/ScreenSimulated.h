#ifndef _SCREENSIMULATED_H
#define _SCREENSIMULATED_H

#include "Status.h"

#include "Screen.h"


class ScreenSimulated: public Screen {
public:
ScreenSimulated();
/**
 * @param text
 */
Status setScreenText(const std::string text);
};

#endif //_SCREENSIMULATED_H
