#ifndef _BANKAPISIMULATED_H
#define _BANKAPISIMULATED_H

#include "Status.h"

#include <list>
#include <memory>

#include "BankAPI.h"
#include "AccountServer.h"


class BankAPISimulated: public BankAPI {
public:
BankAPISimulated(std::string accountFile);

Status validatePin(Account user, uint32_t pin, bool &valid);
Status getBalance(Account user, int &amount);
Status deposit(Account user, int amount);
Status withdraw(Account user, int amount);
Status getAccount(uint64_t accountID, Account *&user);

private:
std::list<AccountServer> accounts;
Status findMatchingAccount( Account acc, AccountServer *&match);
Status findAccountByID( const uint64_t accountID, AccountServer *&match);
};

#endif //_BANKAPISIMULATED_H
