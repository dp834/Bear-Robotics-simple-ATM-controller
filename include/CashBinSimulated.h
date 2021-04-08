#ifndef _CASHBINSIMULATED_H
#define _CASHBINSIMULATED_H

#include "Status.h"

#include "CashBin.h"


class CashBinSimulated: public CashBin {
public:
CashBinSimulated();
Status dispenseCash(int amount);
};

#endif //_CASHBINSIMULATED_H
