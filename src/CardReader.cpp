#include "CardReader.h"

CardReader::CardReader(CardReaderHandler handler) {

}

Status CardReader::readCard(Card card) {
    return handler.cardSwiped(card);
}
