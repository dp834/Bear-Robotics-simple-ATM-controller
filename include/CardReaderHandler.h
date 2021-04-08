#ifndef _CARDREADERHANDLER_H
#define _CARDREADERHANDLER_H

#include "Status.h"

#include "Card.h"

class CardReaderHandler{
public:
virtual Status cardSwiped(Card &card) = 0;
};

#endif //_CARDREADERHANDLER_H
