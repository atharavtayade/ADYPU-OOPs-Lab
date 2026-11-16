
#include <iostream>
#include <string>
using namespace std;

// Base class
class BankAccount {
private:
    int accountNumber;
    double balance;

protected:
    string accountHolder;

public:
    // Constructor
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited: Rs. " << amount << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Display account details
    void displayDetails() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Protected data is accessed through a public function
    double getBalance() {
        return balance;
    }
};

// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal,
                   double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    // Calculate interest
    void calculateInterest() {
        double interest = getBalance() * interestRate / 100;

        cout << "Interest Amount: Rs. "
             << interest << endl;
    }

    // Display savings account details
    void displaySavings() {
        displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {

    // Create SavingsAccount object
    SavingsAccount account(101, "Atharav", 10000, 5);

    cout << "===== BANK ACCOUNT DETAILS =====" << endl;

    account.displaySavings();

    cout << "\n===== DEPOSIT DETAILS =====" << endl;
    account.deposit(2000);

    cout << "\n===== INTEREST DETAILS =====" << endl;
    account.calculateInterest();

    cout << "\n===== UPDATED ACCOUNT DETAILS =====" << endl;
    account.displaySavings();

    return 0;
}
