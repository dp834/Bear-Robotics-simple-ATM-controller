#ifndef _ATM_H
#define _ATM_H

#include "Status.h"

#include <memory>

#include "CardReader.h"
#include "CashBin.h"
#include "CashIntake.h"
#include "BankAPI.h"
#include "Screen.h"
#include "Keypad.h"


class ATM: public CardReaderHandler {
public:
ATM(CardReader *cardReader, CashBin *cashBin, CashIntake *cashIntake, BankAPI *bankAPI, Screen *screen, Keypad *keypad);

Status cardSwiped(Card &card);
private:
    enum ATMTransaction { ATM_WITHDRAW, ATM_DEPOSIT, ATM_CHECK_BALANCE, ATM_EXIT, ATM_INVALID_TRANSACTION };
    CardReader *cardReader;
    CashBin *cashBin;
    CashIntake *cashIntake;
    BankAPI *bankAPI;
    Screen *screen;
    Keypad *keypad;
    Account *currentUser;

    Status getPin(uint32_t &pin);
    Status returnCard();
    Status promptTransaction(ATMTransaction &transaction);
    Status handleTransaction(ATMTransaction transaction);
    Status checkBalance();
    Status deposit();
    Status withdraw();
};

#endif //_ATM_H
