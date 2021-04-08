#include "BankAPI.h"

Status BankAPI::validatePin(Account user, uint32_t pin, bool &valid) {
    return ERR_NONE;
}

Status BankAPI::getBalance(Account user, int &amount) {
    return ERR_NONE;
}

Status BankAPI::deposit(Account user, int amount) {
    return ERR_NONE;
}

Status BankAPI::withdraw(Account user, int amount) {
    return ERR_NONE;
}

Status BankAPI::getAccount(uint64_t accountID, Account &user) {
    return ERR_NONE;
}
