#ifndef _BANKAPI_H
#define _BANKAPI_H

#include "Status.h"
#include "Account.h"
#include <cstdint>

class BankAPI {
public:
Status validatePin(Account user, uint32_t pin, bool &valid);
Status getBalance(Account user, int &amount);
Status deposit(Account user, int amount);
Status withdraw(Account user, int amount);
Status getAccount(uint64_t accountID, Account &user);
};

#endif //_BANKAPI_H
