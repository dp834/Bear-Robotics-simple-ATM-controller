#ifndef _CASHBIN_H
#define _CASHBIN_H

#include "Status.h"

class CashBin {
public:
virtual Status dispenseCash(int amount) = 0;
};

#endif //_CASHBIN_H
