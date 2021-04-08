#include "CardSimulated.h"

/* Inherits constructor from Card */

Status CardSimulated::getAccountID(const uint64_t *id){

    /* Card is not bound to an acount */
    if( accountID == 0 ){
        return ERR_IO;
    }

    id = &accountID;
    return ERR_NONE;
}
