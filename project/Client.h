/*
 * This is the client class that contains all his information ( name, address, phone number, bank account, type of the bank account)
 */

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H
#include <iostream>
#include "BankAccount.h"
#include <vector>

class Client {
private:
    std::string name, address, phoneNumber;
    BankAccount* bankAccount{};
    bool bankAccountType{};
public:
    Client ()= default;
    Client(std::string& name, std::string& address, std::string& phoneNumber);
    void setBankAccount(BankAccount*& account, bool type);
    std::string getName();
    std::string getAddress();
    std::string getPhoneNumber();
    bool getBankAccountType();
    BankAccount* getBankAccount();
};


#endif
