/*
 * Basic bank account class that holds ( bank account ID, balance of the account )
 * This bank account type can withdraw any money of the balance
 * This bank account type can deposit any money to the balance
 */

#ifndef PROJECT_BANKACCOUNT_H
#define PROJECT_BANKACCOUNT_H
#include <iostream>

class BankAccount {
protected:
    int accountID;
    double balance;
public:
    explicit BankAccount(int accountID);
    explicit BankAccount(int accountID, double balance);
    int getID();
    double getBalance();
    // make it virtual because the basic and saving type have different implementation of it
    virtual bool withdraw(double money);
    // make it virtual because the basic and saving type have different implementation of it
    virtual bool deposit(double money);
};

#endif
