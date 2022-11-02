#include "BankAccount.h"

BankAccount::BankAccount(int accountID) {
    // Constructor with no money, will be initialized with 0 balance
    this->accountID = accountID;
    balance = 0;
}

BankAccount::BankAccount(int accountID, double balance) {
    this->accountID = accountID;
    this->balance = balance;
}

int BankAccount::getID() {
    return this->accountID;
}

double BankAccount::getBalance() {
    return this->balance;
}

bool BankAccount::withdraw(double money) {
    // Check if the money to withdraw in range of the balance
    if(balance - money < 0){
        return false;
    }
    balance -= money;
    return true;
}

bool BankAccount::deposit(double money) {
    // Deposit the money without any restrictions
    balance += money;
    return true;
}
