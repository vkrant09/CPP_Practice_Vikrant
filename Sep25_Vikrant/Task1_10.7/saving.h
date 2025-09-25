#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
private:
    double savingsBalance;                     // current balance
    static double annualInterestRate;          // shared annual interest rate

public:
    explicit SavingsAccount(double balance = 0.0);

    void calculateMonthlyInterest();           // apply interest to balance
    double getBalance() const;                 // return current balance

    static void modifyInterestRate(double newRate); // set new annual rate
};

#endif
