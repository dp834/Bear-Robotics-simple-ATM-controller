#ifndef _ACCOUNTSERVER_H
#define _ACCOUNTSERVER_H

#include "Account.h"

class AccountServer: public Account {
public:
AccountServer(uint64_t id, std::string firstName, std::string lastName, uint64_t timedToken, int pin, int balance);
Status validatePin(const int pin, bool &valid);
Status getBalance(int &bal);
Status setBalance(int bal);

private:
int pin;
int balance;

};

#endif //_ACCOUNTSERVER_H
