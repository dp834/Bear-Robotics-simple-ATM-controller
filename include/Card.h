#ifndef _CARD_H
#define _CARD_H

#include "Status.h"
#include <cstdint>

class Card {
public:
Card(uint64_t id);
Status getAccountID(const uint64_t *id);
private:
    const uint64_t accountID;
};

#endif //_CARD_H
