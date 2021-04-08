#include "CashBinSimulated.h"
#include <iostream>

CashBinSimulated::CashBinSimulated() {

}

Status CashBinSimulated::dispenseCash(int amount) {
    std::cout << "Dispensed $" << amount <<  "\n";
    return ERR_NONE;
}
