cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp BankAccount.cpp BankAccount.h SavingBankAccount.cpp SavingBankAccount.h Client.cpp Client.h BankApplication.cpp BankApplication.h)
