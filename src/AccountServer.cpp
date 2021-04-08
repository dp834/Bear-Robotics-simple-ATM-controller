#include "AccountServer.h"

AccountServer::AccountServer(uint64_t id, std::string firstName, std::string lastName, uint64_t timedToken, int pin, int balance)
    :Account(id, firstName, lastName, timedToken),
     pin(pin),
     balance(balance)
    {}

Status AccountServer::validatePin(const int pin, bool &valid){
    valid = pin == this->pin;
    return ERR_NONE;
}

Status AccountServer::getBalance(int &bal){
    bal = balance;
    return ERR_NONE;
}

Status AccountServer::setBalance(int bal){
    /* Real server could do checking etc */
    balance = bal;

    return ERR_NONE;
}
