#ifndef _CARDREADERSIMULATED_H
#define _CARDREADERSIMULATED_H

#include "Status.h"

#include "CardReader.h"


class CardReaderSimulated: public CardReader {
public:
CardReaderSimulated(CardReaderHandler handler);
Status readCard(Card card);
private:
    CardReaderHandler handler;
};

#endif //_CARDREADERSIMULATED_H
