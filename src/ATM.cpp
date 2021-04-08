#include "ATM.h"

ATM::ATM(CardReader &cardReader, CashBin &cashBin, CashIntake &cashIntake, BankAPI &bankAPI, Screen &screen, Keypad &keypad){
    cardReader = cardReader;
    cashBin = cashBin;
    cashIntake = cashIntake;
    bankAPI = bankAPI;
    screen = screen;
    keypad = keypad;
    currentUser = NULL;
}

Status ATM::cardSwiped(Card &card) {
    const uint64_t *accountID;
    cardReader->readCard(card, accountID);

    return ERR_NONE;
}
