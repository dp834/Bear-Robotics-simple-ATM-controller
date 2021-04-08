#ifndef _BANKAPI_H
#define _BANKAPI_H

#include "Status.h"
#include "Account.h"
#include <cstdint>
#include <memory>

class BankAPI {
public:
virtual Status validatePin(Account user, uint32_t pin, bool &valid) = 0;
virtual Status getBalance(Account user, int &amount) = 0;
virtual Status deposit(Account user, int amount) = 0;
virtual Status withdraw(Account user, int amount) = 0;
virtual Status getAccount(uint64_t accountID, Account *&user) = 0;
};

#endif //_BANKAPI_H
