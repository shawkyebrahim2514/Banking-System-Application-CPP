# Banking System
 Banking system application with CPP
 
## Overview
* Allow creating a bank account for a specific client
* There are two types of this banking accounts (Basic and Saving)
   *  Each one of these two types has a different implementation of the withdraw and deposit function
* There is a Client class that contains all client information
* The main class that runs the application and stores all clients with their ID to access them
* All client information will be stored in the database file (dataBase.txt) and will be uploaded each time the application runs

### Banking Account types
* Basic bank account
   * Contains account ID.
   * Contains account balance.
   * Has two different constructors:
      * The first sets the balance to 0.
      * The second the balance to a given value without any constrains.
   * Withdow money from this bank type as you want within the range of the account balance.
   * Deposit money to this bank type with any amount of money.
* Saving bank account
   * It extends the basic bank account attributes and methods.
   * This account requires the user to keep a minimum amount of money in the account, which is called the minimum balance, as long as the account is open.
   * This minimum balance takes a default value of 1000 L.E.
   * It also requires him to make deposits that are not less than 100 a time.
   * The constructor sets the balance to a given value that should be greater than or equal to the minimum balance amount.
   
### Client class
* It contains the information of a client
   * His name.
   * His address
   * His phone number
   * His bank account type
   * A pointer that refers to his bank account
   
   
### Main Window
> There are many options in the main widnow
* Create a new account
* List all clients
   * showing all their information (name, address, phone number ...)
* Withdraw money
* Deposit money

## Screenshots
![image](https://user-images.githubusercontent.com/101745968/199621429-a0bb40cd-74e0-4043-980f-0d0774c20cf1.png)

![image](https://user-images.githubusercontent.com/101745968/199621450-22d2239a-8e19-4f05-87e5-007ed823f947.png)

![image](https://user-images.githubusercontent.com/101745968/199621509-ad4f48c7-c708-4627-8a82-ef2f53a5eae5.png)
