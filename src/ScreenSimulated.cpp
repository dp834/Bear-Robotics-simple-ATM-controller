#include "ScreenSimulated.h"
#include <iostream>

ScreenSimulated::ScreenSimulated() {

}

Status ScreenSimulated::setScreenText(std::string text) {
    std::cout << text << "\n";
    return ERR_NONE;
}
