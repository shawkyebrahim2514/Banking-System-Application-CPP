#include "Client.h"

Client::Client(std::string& name, std::string& address, std::string& phoneNumber) {
    // Fill client information
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}

void Client::setBankAccount(BankAccount *&account, bool type) {
    this->bankAccount = account;
    this->bankAccountType = type;
}

std::string Client::getName() {
    return this->name;
}

std::string Client::getAddress() {
    return this->address;
}

std::string Client::getPhoneNumber() {
    return this->phoneNumber;
}

BankAccount *Client::getBankAccount() {
    return this->bankAccount;
}

bool Client::getBankAccountType() {
    return this->bankAccountType;
}

