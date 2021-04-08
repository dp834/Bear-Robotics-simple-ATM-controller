#ifndef _CARDREADER_H
#define _CARDREADER_H

#include "Status.h"
#include "CardReaderHandler.h"

class CardReader {
public:
virtual Status readCard(Card &card, const uint64_t *accountID) = 0;
private:
};

#endif //_CARDREADER_H
