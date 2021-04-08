#ifndef _CARDREADER_H
#define _CARDREADER_H

#include "Status.h"
#include "CardReaderHandler.h"

class CardReader {
public:
CardReader(CardReaderHandler handler);
Status readCard(Card card);
private:
    CardReaderHandler handler;
};

#endif //_CARDREADER_H
