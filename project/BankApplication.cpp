#include <fstream>
#include <sstream>
#include <regex>
#include "BankApplication.h"
#include "SavingBankAccount.h"
#include "Client.h"

BankApplication::BankApplication() {
    // Upload clients data from the database file
    /*
     * The first line in the database file is the current generatedID
     * Each two lines after that line has a client information
     * The first line of the two lines contains (name, address, phone number, bank account type)
     * The second line of the two lines contains (account ID, bank account balance)
     */
    std::fstream dataBase("dataBase.txt", std::ios::in);
    std::string line1, line2;
    std::getline(dataBase, line1);
    if(dataBase.eof()) {
        // if the database file is empty
        // initialize the ID generator to the default value
        this->generatedID = 20210000;
        return;
    }
    generatedID = std::stoi(line1);
    while (std::getline(dataBase, line1)){
        std::getline(dataBase, line2);
        // split words from the line1 and line2
        auto clientInformation = split(line1);
        auto bankAccountInformation = split(line2);

        // store each information in its variable name
        std::string name = clientInformation[0], address = clientInformation[1], phoneNumber = clientInformation[2];
        bool bankAccountType = clientInformation[3][0] - '0';
        int accountID = std::stoi(bankAccountInformation[0]);
        double accountBalance = std::stod(bankAccountInformation[1]);

        // Create a Client class and BankAccount class to store above information
        Client client(name, address, phoneNumber);
        BankAccount* bankAccount;
        if(bankAccountType){
            bankAccount = new SavingBankAccount(accountID, accountBalance);
        }else{
            bankAccount = new BankAccount(accountID, accountBalance);
        }
        client.setBankAccount(bankAccount, bankAccountType);

        // Add it to the clients container
        this->containerClients[accountID] = client;
    }
}

BankApplication::~BankApplication() {
    // At the end of the program, we must save all clients data in the database file
    std::fstream dataBase("dataBase.txt", std::ios::out);
    // First line contains the current generated ID
    dataBase << generatedID << '\n';
    // Loop over all clients in the clients container and store his information in the database file
    for(auto& temp : this->containerClients){
        Client client = temp.second;
        BankAccount* bankAccount = client.getBankAccount();
        dataBase << client.getName() << ',' << client.getAddress() << ',' << client.getPhoneNumber()
                 << ',' << client.getBankAccountType() << '\n';
        dataBase << bankAccount->getID() << ',' << std::fixed << bankAccount->getBalance() << '\n';
    }
    dataBase.close();
}

std::vector<std::string> BankApplication::split(const std::string &line) {
    // Split the line string by separate each word, the separator between words is (,)
    std::vector<std::string> result;
    int len = line.find(','), from = 0;
    while (len != -1){
        result.push_back(line.substr(from, len++ - from));
        from = len;
        len = line.find(',', from);
    }
    result.push_back(line.substr(from));
    return result;
}

void BankApplication::print(const std::string &paragraph) {
    // Print the paragraph parameter in a suitable form
    int width = 200;
    int part = width / 2 - paragraph.size()/2;
    std::cout << std::string(part, '-') << ' ' << paragraph << ' ' << std::string(part, '-') << '\n';
}

bool BankApplication::validPhoneNumber(const std::string& phoneNumber) {
    // Check if the phone number is valid or not
    // Valid phone number is the number that start with (010), (011), (012) or (015)
    // And after that exist 8 digital numbers
    std::regex reg("(010|011|012|015)[0-9]{8}");
    return std::regex_match(phoneNumber, reg);
}

bool BankApplication::continueRunning() {
    // Check if the user want to do more operation or not
    std::string input;
    print("Do you want to do more operations?");
    std::cout << "Enter y(yes), n(no): ";
    std::cin >> input;
    if(input == "y" || input == "yes") return true;
    else return false;
}

void BankApplication::takeClientOption() {
    // Take option from the user
    int userInput;
    std::cout << "Enter your choice: ";
    std::cin >> userInput;
    while (userInput < 1 || userInput > 4){
        std::cout << "Enter correct choice: ";
        std::cin >> userInput;
    }
    switch (userInput) {
        case 1:
            createClientAccount();
            break;
        case 2:
            listClients();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            deposit();
            break;
    }
}

void BankApplication::showWindow() {
    // Show the window that shows options that client can interact with it
    print("Welcome in Banking system application, what do you want to do?");
    std::cout << "1- create new client account\n";
    std::cout << "2- list all clients\n";
    std::cout << "3- withdraw money\n";
    std::cout << "4- deposit money\n";
}

void BankApplication::run() {
    // Run the banking system application
    showWindow();
    takeClientOption();
    if(continueRunning()) run();
}

void BankApplication::takeClientInformation(std::string &name, std::string &address, std::string &phoneNumber) {
    // This regex replace any character (,) with (-) because in the dataBase the data is separated by (,)
    std::regex reg(",");

    // Take the name from the client
    std::cout << "Enter your name: ";
    std::cin.sync();
    std::getline(std::cin, name);
    name = std::regex_replace(name, reg, "-");

    // Take the address from the client, and make only the first character in upper case
    std::cout << "Enter your address: ";
    std::cin.sync();
    std::getline(std::cin, address);
    address = std::regex_replace(address, reg, "-");
    std::transform(address.begin(), address.end(), address.begin(), tolower);
    address[0] = toupper(address[0]);

    // Take the phone number from the client and check the validation of this phone number
    std::cout << "Enter your phone number: ";
    std::cin >> phoneNumber;
    while (!validPhoneNumber(phoneNumber)){
        std::cout << "Enter valid phone number: ";
        std::cin >> phoneNumber;
    }
}

void BankApplication::printClientInformation(Client& client) {
    // Print all client information
    print(client.getName());
    std::cout << "Address: " << client.getAddress() << '\n';
    std::cout << "Phone number: " << client.getPhoneNumber() << '\n';
    std::cout << "Bank account ID: " << client.getBankAccount()->getID() << '\n';
    std::cout << "The type of the bank account: ";
    if(client.getBankAccountType()) std::cout << "Saving\n";
    else std::cout << "Basic\n";
    std::cout << "Bank account's balance: " << std::fixed << client.getBankAccount()->getBalance() << '\n';
}

void BankApplication::createClientBankAccount(Client &client) {
    // Creating a bank account for a client
    bool bankType;
    double money;
    BankAccount* bankAccount;

    std::cout << "choose your bank account type (basic) 0 ,(saving) 1: ";
    std::cin >> bankType;

    // Initialize the bank account's balance
    std::cout << "Enter the initial balance: ";
    std::cin >> money;
    if(bankType){
        while (money < SavingBankAccount::minimumBalance){
            std::cout << "Enter money that is greater or equal to " << SavingBankAccount::minimumBalance << " : ";
            std::cin >> money;
        }
        bankAccount = new SavingBankAccount(generatedID, money);
    }else{
        bankAccount = new BankAccount(generatedID, money);
    }

    client.setBankAccount(bankAccount, bankType);
    containerClients[generatedID] = client;
}

void BankApplication::createClientAccount() {
    // Create an account for the new client
    std::string name, address, phoneNumber;
    // Take his basic information
    takeClientInformation(name, address, phoneNumber);
    // Create new class and a new bank account for him
    Client client (name, address, phoneNumber);
    createClientBankAccount(client);
    // Print his information
    printClientInformation(client);
    // Increase the ID generator by 1
    generatedID ++;
}

void BankApplication::listClients() {
    // Print all clients that are stored in the application
    print("All clients' information");
    for(auto& temp : containerClients){
        printClientInformation(temp.second);
    }
}

void BankApplication::withdraw() {
    // Take client ID to withdraw
    int ID;
    std::cout << "Enter your account ID ";
    std::cin >> ID;
    Client client = containerClients[ID];
    printClientInformation(client);

    // Take the money to withdraw
    int money;
    std::cout << "Enter the money to withdraw: ";
    std::cin >> money;
    while (!client.getBankAccount()->withdraw(money)) {
        print("Sorry this is more than you can withdraw");
        std::cout << "Enter the right money to withdraw: ";
        std::cin >> money;
    }

    print("Successfully withdrawing!");
    std::cout<<"Your balance now : (" << client.getBankAccount()->getBalance() << ")\n";
}

void BankApplication::deposit() {
    // Take client ID to deposit
    int ID;
    std::cout << "Enter account ID ";
    std::cin >> ID;
    Client client = containerClients[ID];
    printClientInformation(client);

    // Take the money to deposit
    int money;
    std::cout << "Enter the Amount to deposit: ";
    std::cin >> money;
    while (!client.getBankAccount()->deposit(money)) {
        print("Sorry this is less than you can deposit (at least 100 L.E)");
        std::cout << "Enter the right money to deposit: ";
        std::cin >> money;
    }

    print("Successfully withdrawing!");
    std::cout << "Your balance now : " << client.getBankAccount()->getBalance() << '\n';
}