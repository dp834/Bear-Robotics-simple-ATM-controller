#include "CardReaderSimulated.h"

#include <iostream>

Status CardReaderSimulated::readCard(Card &card, const uint64_t *&accountID) {
    return card.getAccountID(accountID);
}

Status CardReaderSimulated::ejectCard() {
    std::cout << "Ejecting Card\n" << std::endl;
    return ERR_NONE;
}
