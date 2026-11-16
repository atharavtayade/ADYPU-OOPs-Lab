
#include <iostream>
#include <exception>
using namespace std;

// Base Custom Exception
class BankException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Transaction Error";
    }
};

// Insufficient Balance Exception
class InsufficientBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient Balance!";
    }
};

// Invalid Amount Exception
class InvalidAmount : public BankException {
public:
    const char* what() const noexcept override {
        return "Error: Invalid Transaction Amount!";
    }
};

// Bank Account Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        balance += amount;
        cout << "Amount Deposited: Rs. " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientBalance();
        }

        balance -= amount;
        cout << "Amount Withdrawn: Rs. " << amount << endl;
    }

    void displayBalance() {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {

    BankAccount account(5000);

    cout << "===== BANKING SYSTEM =====" << endl;

    account.displayBalance();

    // Deposit Transaction
    try {
        account.deposit(2000);
    }
    catch (BankException& e) {
        cout << e.what() << endl;
    }

    // Withdrawal Transaction
    try {
        account.withdraw(1000);
    }
    catch (BankException& e) {
        cout << e.what() << endl;
    }

    // Invalid Withdrawal Transaction
    try {
        account.withdraw(10000);
    }
    catch (InsufficientBalance& e) {
        cout << e.what() << endl;
    }
    catch (InvalidAmount& e) {
        cout << e.what() << endl;
    }

    // Invalid Deposit Transaction
    try {
        account.deposit(-500);
    }
    catch (InvalidAmount& e) {
        cout << e.what() << endl;
    }

    cout << "\n===== FINAL ACCOUNT DETAILS =====" << endl;
    account.displayBalance();

    return 0;
}
