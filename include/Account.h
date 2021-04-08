#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include "Status.h"

#include <cstdint>
#include <string>

class Account {
public:

Account(uint64_t id, std::string firstName, std::string lastName, uint64_t timedToken);

Status getID(const uint64_t &id);
Status getFirstName(const std::string &firstName);
Status getLastName(const std::string &lastName);
Status getTimedToken(const uint64_t &token);

private:
    const uint64_t id;
    const std::string firstName;
    const std::string lastName;
    const uint64_t timedToken;
};

#endif //_ACCOUNT_H
