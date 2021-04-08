#ifndef _CARD_H
#define _CARD_H

#include "Status.h"
#include <cstdint>

class Card {
public:
virtual Status getAccountID(const uint64_t *&id) = 0;
private:
};

#endif //_CARD_H
