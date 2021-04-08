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
Status setScreenText(std::string text);
private:
    std::string currentBuffer;
};

#endif //_SCREENSIMULATED_H
