#include "CashIntakeSimulated.h"

#include <iostream>
#include <climits>

CashIntakeSimulated::CashIntakeSimulated() {

}

Status CashIntakeSimulated::getCash(int &amount) {
    std::string input;

    std::cout << "How much are you depositing? (Positive whole numbers only)\n";
    
    std::cin >> input;

    amount = std::stoi(input);

    if(amount < 0){
        return ERR_IO;
    }

    /* read the trailing newline */
    getchar();

    return ERR_NONE;
}
