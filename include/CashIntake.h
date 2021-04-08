#ifndef _CASHINTAKE_H
#define _CASHINTAKE_H

#include "Status.h"

class CashIntake {
public:
virtual Status getCash(int &amount) = 0;
};

#endif //_CASHINTAKE_H
