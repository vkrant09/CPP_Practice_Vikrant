#include "saving.h"

// define static member
double SavingsAccount::annualInterestRate = 0.0;

SavingsAccount::SavingsAccount(double balance) {
    if (balance >= 0.0) {
        savingsBalance = balance;
    } else {
        savingsBalance = 0.0; // prevent negative balances
    }
}

void SavingsAccount::calculateMonthlyInterest() {
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
    savingsBalance += monthlyInterest;
}

double SavingsAccount::getBalance() const {
    return savingsBalance;
}

void SavingsAccount::modifyInterestRate(double newRate) {
    if (newRate >= 0.0) {
        annualInterestRate = newRate;
    }
}
