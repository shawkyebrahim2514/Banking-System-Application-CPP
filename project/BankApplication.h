/*
 * This class manages the operations that clients interact with
 * It has a generated ID that increase by 1 after a new client registered
 * It has a map that holds all the clients bank account
 * Client class can be accessed by his bank account's ID
 */

#ifndef PROJECT_BANKAPPLICATION_H
#define PROJECT_BANKAPPLICATION_H
#include <iostream>
#include <vector>
#include <map>
#include "Client.h"
#include "BankAccount.h"

class BankApplication {
    int generatedID;
    std::map<int,Client> containerClients;
    void showWindow();
    std::vector<std::string> split(const std::string& line);
    bool continueRunning();
    void takeClientOption();
    void print(const std::string& paragraph);
    void takeClientInformation(std::string& name, std::string& address, std::string& phoneNumber);
    void createClientBankAccount(Client& client);
    void printClientInformation(Client& client);
    bool validPhoneNumber(const std::string& phoneNumber);
public:
    BankApplication();
    ~BankApplication();
    void createClientAccount();
    void listClients();
    void withdraw();
    void deposit();
    void run();
};


#endif
