#ifndef _CARDSIMULATED_H
#define _CARDSIMULATED_H

#include "Status.h"

#include "Card.h"


class CardSimulated: public Card {
public:
CardSimulated(uint64_t id);
Status getAccountID(const uint64_t *&id);
private:
    const uint64_t accountID;
};

#endif //_CARDSIMULATED_H
