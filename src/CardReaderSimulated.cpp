#include "CardReaderSimulated.h"

Status CardReaderSimulated::readCard(Card &card, const uint64_t *accountID) {
    return card.getAccountID(accountID);
}
