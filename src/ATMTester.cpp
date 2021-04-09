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
    ATM atm(cardReader, cashBin, cashIntake, bankAPI, screen, keypad);

    CardSimulated *card = new CardSimulated(1);
    atm.cardSwiped(*card);

    card = new CardSimulated(2);
    atm.cardSwiped(*card);

    card = new CardSimulated(3);
    atm.cardSwiped(*card);

    card = new CardSimulated(10);
    atm.cardSwiped(*card);
    /* Can test each component here individually too */

    /* Testing the card Reader with a card */
    const uint64_t *accountID;
    cardReader->readCard(*card, accountID);

    return 0;
}
