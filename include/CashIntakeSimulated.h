#ifndef _CASHINTAKESIMULATED_H
#define _CASHINTAKESIMULATED_H

#include "Status.h"

#include "CashIntake.h"


class CashIntakeSimulated: public CashIntake {
public:
CashIntakeSimulated();
Status getCash(int &amount);
};

#endif //_CASHINTAKESIMULATED_H
