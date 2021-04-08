#ifndef _CARDREADERSIMULATED_H
#define _CARDREADERSIMULATED_H

#include "Status.h"

#include "CardReader.h"


class CardReaderSimulated: public CardReader {
public:
Status readCard(Card &card, const uint64_t *&accountID);
};

#endif //_CARDREADERSIMULATED_H
