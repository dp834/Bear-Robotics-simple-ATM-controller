#include "BankAPISimulated.h"

#include <algorithm>


BankAPISimulated::BankAPISimulated(std::string accountFile) {
    /* Can read accounts from a database file, will probably just hardcode a few options here */
    accounts.emplace_back(new AccountServer(1, "Bob", "Jones", 123454321, 1111, 10));
    accounts.emplace_back(new AccountServer(2, "Zach", "Smith", 231491832, 1210, 100));
    accounts.emplace_back(new AccountServer(3, "Bear", "Robotics", 312321459, 2839, 1000));
}

Status BankAPISimulated::validatePin(const Account user, const uint32_t pin, bool &valid) {
    Status status;

    std::shared_ptr<AccountServer> acc;

    status = findMatchingAccount(user, acc);
    if(status){
        return status;
    }

    return acc->validatePin(pin, valid);
}

Status BankAPISimulated::getBalance(const Account user, int &amount) {
    Status status;

    std::shared_ptr<AccountServer> acc;

    status = findMatchingAccount(user, acc);
    if(status){
        return status;
    }

    return acc->getBalance(amount);
}

Status BankAPISimulated::deposit(const Account user, int amount) {
    Status status;

    int balance;

    std::shared_ptr<AccountServer> acc;

    status = findMatchingAccount(user, acc);
    if(status){
        return status;
    }

    status = acc->getBalance(balance);
    if(status){
        return status;
    }

    return acc->setBalance(balance + amount);
}

Status BankAPISimulated::withdraw(const Account user, int amount) {
    Status status;

    int balance;

    std::shared_ptr<AccountServer> acc;

    status = findMatchingAccount(user, acc);
    if(status){
        return status;
    }

    status = acc->getBalance(balance);
    if(status){
        return status;
    }

    return acc->setBalance(balance - amount);
}

Status BankAPISimulated::getAccount(const uint64_t accountID, std::shared_ptr<Account> user) {
    Status status;

    int balance;

    std::shared_ptr<AccountServer> acc;

    status = findAccountByID(accountID, acc);
    if(status){
        return status;
    }

    user = acc;
    return ERR_NONE;
}

Status BankAPISimulated::findMatchingAccount( Account acc, std::shared_ptr<AccountServer> match){
    std::list<std::shared_ptr<AccountServer>>::iterator it;

    it = std::find_if(accounts.begin(), accounts.end(),
        [acc](std::shared_ptr<AccountServer> acc1){
            return *acc1 == acc;
        }
    );

    if( it == accounts.end() ){
        return ERR_PARAM;
    }

    match = *it;

    return ERR_NONE;
}


Status BankAPISimulated::findAccountByID( const uint64_t accountID, std::shared_ptr<AccountServer> match){
    std::list<std::shared_ptr<AccountServer>>::iterator it;

    it = std::find_if(accounts.begin(), accounts.end(),
        [accountID](std::shared_ptr<AccountServer> acc1){
            return *acc1 == accountID;
        }
    );

    if( it == accounts.end() ){
        return ERR_PARAM;
    }

    match = *it;

    return ERR_NONE;
}
