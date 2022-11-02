#include "SavingBankAccount.h"
using namespace std;

SavingBankAccount::SavingBankAccount(int accountID, double money) : BankAccount(accountID) {
    balance = money;
}

bool SavingBankAccount::withdraw(double money) {
    // The money to withdraw shouldn't make the balance less than the minimum balance
    if(balance - money < minimumBalance){
        return false;
    }
    balance -= money;
    return true;
}

bool SavingBankAccount::deposit(double money) {
    // The money to deposit should be at least 100 L.E
    if(money < 100){
        return false;
    }
    balance += money;
    return true;
}

// This is the minimum money the balance should have all the time
double SavingBankAccount::minimumBalance = 1000;
