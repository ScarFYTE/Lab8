#include <iomanip>
#include <iostream>

using namespace std;

class Account {
protected:
    double balance;
    double interestRate; 

public:
    Account(double bal, double rate) : balance(bal), interestRate(rate) {}
    virtual double CalculateInterest(double timeInMonths) = 0;
    virtual ~Account() = default;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double bal, double rate) : Account(bal, rate) {}

    double CalculateInterest(double timeInMonths) override {
        return balance * interestRate * (timeInMonths / 12.0);
    }
};

class CheckingAccount : public Account {
private:
    double fee;

public:
    CheckingAccount(double bal, double rate, double transactionFee)
        : Account(bal, rate), fee(transactionFee) {}

    double CalculateInterest(double timeInMonths) override {
        return (balance - fee) * interestRate * (timeInMonths / 12.0);
    }
};

int main() {
    SavingsAccount savings(5000, 0.03);
    CheckingAccount checking(3000, 0.015, 10);

    cout << fixed << setprecision(2);
    cout << "Savings Account Interest: $"
         << savings.CalculateInterest(6) << '\n';
    cout << "Checking Account Interest: $"
         << checking.CalculateInterest(6) << '\n';

    return 0;
}

