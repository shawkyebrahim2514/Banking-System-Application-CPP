/*
 * Saving bank account class inherits attributes and methods from the basic one
 * This type overrides the withdraw and deposit methods from Basic account class
 * This bank account type can withdraw money but must be at least 1000 L.E in the account balance
 * This bank account type can deposit money at least 100 L.E at once
 */

#ifndef PROJECT_SAVINGBANKACCOUNT_H
#define PROJECT_SAVINGBANKACCOUNT_H
#include "BankAccount.h"

class SavingBankAccount : public BankAccount{
public:
    static double minimumBalance;
    explicit SavingBankAccount(int accountID, double money);
    bool withdraw(double money) override;
    bool deposit(double money) override;
};


#endif
