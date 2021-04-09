#include "ATM.h"

#include <iostream>

ATM::ATM(CardReader *cardReader, CashBin *cashBin, CashIntake *cashIntake, BankAPI *bankAPI, Screen *screen, Keypad *keypad){
    this->cardReader = cardReader;
    this->cashBin = cashBin;
    this->cashIntake = cashIntake;
    this->bankAPI = bankAPI;
    this->screen = screen;
    this->keypad = keypad;
    this->currentUser = NULL;
}

/* We are waiting till a card is inserted then we can process the full trasnaction with the user */
Status ATM::cardSwiped(Card &card) {
    ATMTransaction transaction = ATM_INVALID_TRANSACTION;
    const uint64_t *accountID;
    uint32_t pin;
    bool authenticated = false;

    cardReader->readCard(card, accountID);

    if( screen->setScreenText("Welcome, getting account information\n") ){
        std::cerr << "Failed to print text\n";
        return ERR_IO;
    }

    if( bankAPI->getAccount(*accountID, currentUser) ){
        std::cerr << "Failed to get Account information\n" ;
        return ERR_IO;
    }


    if( getPin(pin) ){
        std::cerr << "Error getting pin from user\n";
        return ERR_IO;
    }

    if( bankAPI->validatePin(*currentUser, pin, authenticated) ){
        std::cerr << "Failed to authenticate user with server\n";
        return ERR_IO;
    }

    if(!authenticated){
        screen->setScreenText("Invalid pin.\nExiting\n");
        returnCard();
        return ERR_IO;
    }

    screen->setScreenText("Authentication successful\n");

    while(transaction != ATM_EXIT){
       if( promptTransaction(transaction)){
            std::cerr << "Error getting transaction from user\n";
            return ERR_IO;
       }

       if( handleTransaction(transaction) ){
            std::cerr << "Error processing transaction\n";
            return ERR_IO;
       }
    }

    return ERR_NONE;
}

Status ATM::getPin(uint32_t &pin){
    std::string buff = "";
    const std::string *firstName;
    const std::string *lastName;

    int digit;
    pin = 0;

    IF_ERROR_RETURN(
        currentUser->getFirstName(firstName) );
    IF_ERROR_RETURN(
        currentUser->getLastName(lastName) );



    screen->setScreenText("Hello ");
    screen->setScreenText(*firstName);
    screen->setScreenText(" ");
    screen->setScreenText(*lastName);
    screen->setScreenText("\nPlease enter your pin:");


    /* Will error when we get no digits */
    while(keypad->getDigitInput(digit) == ERR_NONE){
        pin = pin*10 + digit;
    };
    if(pin == 0){
        /* Due to the way this is written no way to determine if io error or no input */
        return ERR_IO;
    }

    return ERR_NONE;
}

Status ATM::returnCard(){
    IF_ERROR_RETURN(
        screen->setScreenText("Please take your card from the Card Reader\n") );
    IF_ERROR_RETURN(
        cardReader->ejectCard());

    return ERR_NONE;
}

Status ATM::promptTransaction(ATMTransaction &transaction){
    std::string prompt =
        "What would you like to do?\n"
        "   1) Show Balance \n"
        "   2) Deposit \n"
        "   3) Withdraw \n"
        "   4) Exit \n"
        "";
    int choice;
    int tmp;

    IF_ERROR_RETURN(
        screen->setScreenText(prompt));

    
    IF_ERROR_RETURN(
        keypad->getDigitInput(choice) );

    if( keypad->getDigitInput(tmp) == ERR_NONE ){
        /* they entered more than 1 digit error */
        /* This method does NOT scale well */
        /* neet to get the buffer to clear */
        while(keypad->getDigitInput(tmp) == ERR_NONE ){
        }
        transaction = ATM_INVALID_TRANSACTION;
        return ERR_NONE;
    }

    switch(choice){
        case(1):transaction = ATM_CHECK_BALANCE;break;
        case(2):transaction = ATM_DEPOSIT;break;
        case(3):transaction = ATM_WITHDRAW;break;
        case(4):transaction = ATM_EXIT;break;
        default: transaction = ATM_INVALID_TRANSACTION;
    }

    return ERR_NONE;
}

Status ATM::handleTransaction(ATMTransaction transaction){

    switch(transaction){
        case(ATM_CHECK_BALANCE): return checkBalance();
        case(ATM_DEPOSIT): return deposit();
        case(ATM_WITHDRAW): return withdraw();
        case(ATM_EXIT): return ERR_NONE;
        default: {
            std::string msg = "Invalid Selection please choose 1,2,3,4\n";
            IF_ERROR_RETURN(
                screen->setScreenText(msg) );
        }
    }
    return ERR_NONE;
}

Status ATM::checkBalance(){
    int balance;
    std::string msg = "Your current balance is: $";

    IF_ERROR_RETURN(
        bankAPI->getBalance(*currentUser, balance) );

    msg += std::to_string(balance);
    msg += "\n";

    IF_ERROR_RETURN(
        screen->setScreenText(msg) );

    return ERR_NONE;
}

Status ATM::deposit(){
    int amount = 0;
    std::string msg = "Deposited $";

    IF_ERROR_RETURN(
        screen->setScreenText("Please insert your money\n") );

    IF_ERROR_RETURN(
        cashIntake->getCash(amount) );

    IF_ERROR_RETURN(
        bankAPI->deposit(*currentUser, amount) );

    msg += std::to_string(amount);
    msg += "\n";

    IF_ERROR_RETURN(
        screen->setScreenText(msg) );

    return ERR_NONE;
}

Status ATM::withdraw(){
    Status status;
    int amount = 0;
    int digit;
    std::string msg = "Withdrew $";

    IF_ERROR_RETURN(
        screen->setScreenText("How much would you like to withdraw?") );

    IF_ERROR_RETURN(
        keypad->getDigitInput(amount) );

    while(keypad->getDigitInput(digit) == ERR_NONE){
        amount = amount*10 + digit;
    }

    status = bankAPI->withdraw(*currentUser, amount);
    if( status == ERR_INVALID_TRANSACTION ){
        screen->setScreenText("Insufficient Funds cannot withdraw\n");
        return ERR_NONE;
    }else if( status ){
        return status;
    }

    IF_ERROR_RETURN(
        cashBin->dispenseCash(amount) );

    IF_ERROR_RETURN(
        screen->setScreenText("Please take your money\n") );

    msg += std::to_string(amount);
    msg += "\n";

    IF_ERROR_RETURN(
        screen->setScreenText(msg) );

    return ERR_NONE;
}
