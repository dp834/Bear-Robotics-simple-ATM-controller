#include "CardReaderSimulated.h"

CardReaderSimulated::CardReaderSimulated(CardReaderHandler handler):CardReader(handler) {

}

Status CardReaderSimulated::readCard(Card card) {
    return ERR_NONE;
}
