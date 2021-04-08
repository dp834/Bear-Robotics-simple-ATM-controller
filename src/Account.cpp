#include "Account.h"

Account::Account(uint64_t id, std::string firstName, std::string lastName, uint64_t timedToken)
    : id(id),
      firstName(firstName),
      lastName(lastName),
      timedToken(timedToken)
{}

Status Account::getID(const uint64_t *id) const {
    id = &(this->id);
    return ERR_NONE;
}

Status Account::getFirstName(const std::string *firstName) const {
    firstName = &(this->firstName);
    return ERR_NONE;
}

Status Account::getLastName(const std::string *lastName) const {
    lastName = &(this->lastName);
    return ERR_NONE;
}

Status Account::getTimedToken(const uint64_t *token) const {
    token = &(this->timedToken);
    return ERR_NONE;
}

bool Account::operator==(const Account& rhs){
    const uint64_t *lhsID;
    const uint64_t *rhsID;

    if( this->getID(lhsID) ){
        return false;
    }

    if( rhs.getID(rhsID) ){
        return false;
    }
    return *lhsID == *rhsID;
}

bool Account::operator==(const uint64_t accountID){
    const uint64_t *lhsID;

    if( this->getID(lhsID) ){
        return false;
    }

    return *lhsID == accountID;
}
