#include <iostream>

class Account {
private:
    int balance; // account balance

public:
    // constructor with validation
    Account(int initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cout << "Error: Initial balance was invalid, set to 0.\n";
        }
    }

    // add money
    void credit(int amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // withdraw money if enough balance
    void debit(int amount) {
        if (amount > balance) {
            std::cout << "Debit amount exceeded account balance.\n";
        } else if (amount > 0) {
            balance -= amount;
        }
    }

    // return current balance
    int getBalance() const {
        return balance;
    }
};

int main() {
    // create 2 accounts
    Account account1(50);
    Account account2(-7);  // invalid -> set to 0

    std::cout << "account1 balance: " << account1.getBalance() << "\n";
    std::cout << "account2 balance: " << account2.getBalance() << "\n\n";

    // credit both accounts
    std::cout << "Adding 25 to account1 balance\n";
    account1.credit(25);
    std::cout << "account1 balance: " << account1.getBalance() << "\n";

    std::cout << "Adding 30 to account2 balance\n";
    account2.credit(30);
    std::cout << "account2 balance: " << account2.getBalance() << "\n\n";

    // debit both accounts
    std::cout << "Attempting to debit 20 from account1 balance\n";
    account1.debit(20);
    std::cout << "account1 balance: " << account1.getBalance() << "\n";

    std::cout << "Attempting to debit 50 from account2 balance\n";
    account2.debit(50);  // should show error
    std::cout << "account2 balance: " << account2.getBalance() << "\n";

    return 0;
}
