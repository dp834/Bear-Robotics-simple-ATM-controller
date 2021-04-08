#include "KeypadSimulated.h"
#include <iostream>

KeypadSimulated::KeypadSimulated() {

}

Status KeypadSimulated::getDigitInput(int &digit) {
    char c;
    c = getchar();

    if(!isdigit(c)){
        /* Can ignore or throw error */
        return ERR_IO;
    }
    
    digit = c - '0';

    return ERR_NONE;
}

Status KeypadSimulated::getStringInput(std::string &input) {
    std::getline(std::cin, input);
    return ERR_NONE;
}
