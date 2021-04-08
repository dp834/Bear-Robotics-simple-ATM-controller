#ifndef _CARDREADERHANDLER_H
#define _CARDREADERHANDLER_H

#include "Status.h"

#include "Card.h"

class CardReaderHandler{
public:
Status cardSwiped(Card card);
};

#endif //_CARDREADERHANDLER_H
