#ifndef _BANKAPISIMULATED_H
#define _BANKAPISIMULATED_H

#include "Status.h"

#include "BankAPI.h"


class BankAPISimulated: public BankAPI {
public:
BankAPISimulated(std::string accountFile);

Status validatePin(Account user, uint32_t pin, bool &valid);
Status getBalance(Account user, int &amount);
Status deposit(Account user, int amount);
Status withdraw(Account user, int amount);
Status getAccount(uint64_t accountID, Account &user);
};

#endif //_BANKAPISIMULATED_H
