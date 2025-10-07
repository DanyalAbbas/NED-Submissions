#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account() {
        balance = 0.0;
    }
    
    Account(double initialBalance) {
        balance = initialBalance;
    }
    
    virtual void deposit(double amount) {
        balance += amount;
    }
    
    virtual bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    double checkBalance() {
        return balance;
    }
};

class InterestAccount : public Account {
private:
    double interest;
public:
    InterestAccount() : Account() {
        interest = 0.30;
    }
    
    InterestAccount(double initialBalance, double interestRate = 0.30) : Account(initialBalance) {
        interest = interestRate;
    }
    
    void deposit(double amount) override {
        double interestAmount = amount * interest;
        balance += (amount + interestAmount);
    }
};

class ChargingAccount : public Account {
private:
    double fee;
public:
    ChargingAccount() : Account() {
        fee = 25.0;
    }
    
    ChargingAccount(double initialBalance, double withdrawalFee = 25.0) : Account(initialBalance) {
        fee = withdrawalFee;
    }
    
    bool withdraw(double amount) override {
        if (amount + fee <= balance) {
            balance -= (amount + fee);
            return true;
        }
        return false;
    }
};

class ACI {
public:
    bool transfer(double amount, Account& targetAccount) {
        cout << "Standard transfer of " << amount << endl;
        targetAccount.deposit(amount);
        return true;
    }
    
    bool transfer(double amount, InterestAccount& targetAccount) {
        cout << "Interest account transfer of " << amount << endl;
        targetAccount.deposit(amount);
        return true;
    }
    
    bool transfer(double amount, ChargingAccount& targetAccount) {
        cout << "Charging account transfer of " << amount << endl;
        targetAccount.deposit(amount);
        return true;
    }
};

int main() {
    Account regularAcc(1000);
    InterestAccount interestAcc(500, 0.30);
    ChargingAccount chargingAcc(2000, 25.0);
    ACI aci;

    cout << "Regular account: " << regularAcc.checkBalance() << endl;
    cout << "Interest account: " << interestAcc.checkBalance() << endl;
    cout << "Charging account: " << chargingAcc.checkBalance() << endl;
    
}