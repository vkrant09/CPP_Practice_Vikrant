#include "saving.h"
#include <iostream>
#include <iomanip>

int main() {
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    // set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balances after 1 month at 3% annual rate:\n";
    std::cout << "Saver1: $" << saver1.getBalance() << "\n";
    std::cout << "Saver2: $" << saver2.getBalance() << "\n";

    // set interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after next month at 4% annual rate:\n";
    std::cout << "Saver1: $" << saver1.getBalance() << "\n";
    std::cout << "Saver2: $" << saver2.getBalance() << "\n";

    return 0;
}
