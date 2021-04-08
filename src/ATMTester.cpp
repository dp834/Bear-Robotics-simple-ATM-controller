#include <iostream>

#include "ATM.h"
#include "CardReaderSimulated.h"
#include "CashBinSimulated.h"
#include "CashIntakeSimulated.h"
#include "BankAPISimulated.h"
#include "ScreenSimulated.h"
#include "KeypadSimulated.h"
#include "CardSimulated.h"

int main(int argc, char **argv){
    CardReader *cardReader = new CardReaderSimulated();
    CashBin *cashBin = new CashBinSimulated();
    CashIntake *cashIntake = new CashIntakeSimulated();
    BankAPI *bankAPI = new BankAPISimulated("NoFILE");
    Screen *screen = new ScreenSimulated();
    Keypad *keypad = new KeypadSimulated();

    CardSimulated card(1);

    const uint64_t *accountID;
    cardReader->readCard(card, accountID);

    ATM atm(cardReader, cashBin, cashIntake, bankAPI, screen, keypad);

    atm.cardSwiped(card);

    return 0;
}
