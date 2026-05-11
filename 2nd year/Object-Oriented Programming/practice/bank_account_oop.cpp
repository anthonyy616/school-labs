#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



class BankAccount {
    private:
        double balance;
    public:
        BankAccount(double initialBalance) : balance(initialBalance) {}
        
        void deposit(double amount) {
            balance += amount;
        }
        void withdraw(double amount) {
            if (amount <= balance) {
                balance -= amount;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        }
        double getBalance() const {
            return balance;
        }
};

int main() {
    BankAccount account(500.0);

    account.deposit(200.0);
    account.withdraw(100.0);

    cout << "Current balance: $" << fixed << setprecision(2) << account.getBalance() << endl;

    account.withdraw(700.0); // Attempt to withdraw more than the balance
    
    cout << "Current balance: $" << fixed << setprecision(2) << account.getBalance() << endl;

    return 0;
}