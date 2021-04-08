#include "BankAPISimulated.h"

BankAPISimulated::BankAPISimulated(std::string accountFile) {

}

Status BankAPISimulated::validatePin(Account user, uint32_t pin, bool &valid) {
    return ERR_NONE;
}

Status BankAPISimulated::getBalance(Account user, int &amount) {
    return ERR_NONE;
}

Status BankAPISimulated::deposit(Account user, int amount) {
    return ERR_NONE;
}

Status BankAPISimulated::withdraw(Account user, int amount) {
    return ERR_NONE;
}

Status BankAPISimulated::getAccount(uint64_t accountID, Account &user) {
    return ERR_NONE;
}
