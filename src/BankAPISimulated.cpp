#include "BankAPISimulated.h"

#include <algorithm>

BankAPISimulated::BankAPISimulated(std::string accountFile) {
    /* Can read accounts from a database file, will probably just hardcode a few options here */
    accounts.emplace_back(1, "Bob", "Jones", 123454321, 1111, 10);
    accounts.emplace_back(2, "Zach", "Smith", 231491832, 1210, 100);
    accounts.emplace_back(3, "Bear", "Robotics", 312321459, 2839, 1000);
}

Status BankAPISimulated::validatePin(const Account user, const uint32_t pin, bool &valid) {
    AccountServer *acc;

    IF_ERROR_RETURN(
        findMatchingAccount(user, acc) );

    return acc->validatePin(pin, valid);
}

Status BankAPISimulated::getBalance(const Account user, int &amount) {
    AccountServer *acc;

    IF_ERROR_RETURN(
        findMatchingAccount(user, acc) );

    return acc->getBalance(amount);
}

Status BankAPISimulated::deposit(const Account user, int amount) {
    int balance;

    AccountServer *acc;

    IF_ERROR_RETURN(
        findMatchingAccount(user, acc) );

    IF_ERROR_RETURN(
        acc->getBalance(balance) );

    return acc->setBalance(balance + amount);
}

Status BankAPISimulated::withdraw(const Account user, int amount) {
    int balance;

    AccountServer *acc;

    IF_ERROR_RETURN(
        findMatchingAccount(user, acc) );

    IF_ERROR_RETURN(
        acc->getBalance(balance) );

    if( balance < amount){
        return ERR_INVALID_TRANSACTION;
    }

    return acc->setBalance(balance - amount);
}

Status BankAPISimulated::getAccount(const uint64_t accountID, Account *&user) {
    int balance;

    AccountServer *acc;

    IF_ERROR_RETURN(
        findAccountByID(accountID, acc) );

    user = acc;
    return ERR_NONE;
}

Status BankAPISimulated::findMatchingAccount( Account acc, AccountServer *&match){
    std::list<AccountServer>::iterator it;

    it = std::find_if(accounts.begin(), accounts.end(),
        [acc](AccountServer acc1){
            return acc1 == acc;
        }
    );

    if( it == accounts.end() ){
        return ERR_PARAM;
    }

    match = &(*it);

    return ERR_NONE;
}


Status BankAPISimulated::findAccountByID( const uint64_t accountID, AccountServer *&match){
    std::list<AccountServer>::iterator it;

    it = std::find_if(accounts.begin(), accounts.end(),
        [accountID](AccountServer acc1){
            return acc1 == accountID;
        }
    );

    if( it == accounts.end() ){
        return ERR_PARAM;
    }

    match = &(*it);

    return ERR_NONE;
}
