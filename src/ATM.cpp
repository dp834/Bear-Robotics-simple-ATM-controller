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
    const uint64_t *accountID;

    cardReader->readCard(card, accountID);

    IF_ERROR_RETURN(
        screen->setScreenText("Welcome, getting account information\n") );

    if( bankAPI->getAccount(*accountID, currentUser) ){
        std::cerr << "Failed to get Account information\n" ;
        return ERR_IO;
    }


    IF_ERROR_RETURN( getPin() );


    return ERR_NONE;
}

Status ATM::getPin(){
    std::string buff = "";
    const std::string *firstName;
    const std::string *lastName;

    IF_ERROR_RETURN(
        currentUser->getFirstName(firstName) );
    IF_ERROR_RETURN(
        currentUser->getLastName(lastName) );



    screen->setScreenText("Hello ");
    screen->setScreenText(*firstName);
    screen->setScreenText(" ");
    screen->setScreenText(*lastName);
    screen->setScreenText("\nPlease enter your pin:");


    return ERR_NONE;
}
