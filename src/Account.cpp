#include "Account.h"

Account::Account(uint64_t id, std::string firstName, std::string lastName, uint64_t timedToken)
    : id(id),
      firstName(firstName),
      lastName(lastName),
      timedToken(timedToken)
{}

Status Account::getID(const uint64_t &id) {
    return ERR_NONE;
}

Status Account::getFirstName(const std::string &firstName) {
    return ERR_NONE;
}

Status Account::getLastName(const std::string &lastName) {
    return ERR_NONE;
}

Status getTimedToken(const uint64_t &token){
    return ERR_NONE;
}
