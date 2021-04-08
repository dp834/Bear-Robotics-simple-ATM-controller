#include "CashIntake.h"
#include <iostream>

Status CashIntake::getCash(int &amount) {
    std::string input;

    std::cout << "Enter the number of bills you are depositing\n";

    std::cin >> input; 

    try{
        amount = std::stoi(input);
    } catch (std::invalid_argument){
        return ERR_IO;
    }

    return ERR_NONE;
}
