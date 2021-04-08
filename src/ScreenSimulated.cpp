#include "ScreenSimulated.h"
#include <iostream>

ScreenSimulated::ScreenSimulated() {

}

Status ScreenSimulated::setScreenText(const std::string text) {
    std::cout << text;
    fflush(stdout);
    return ERR_NONE;
}
