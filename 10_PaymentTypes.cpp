// 10_PaymentTypes.cpp
// (Inheritance) Each class extends Payment and gives its own pay() body.
// (Runtime polymorphism) BookingService calls payment->pay(amount) through a
// Payment pointer - which pay() runs is decided at runtime by the real object type.
#include <iostream>
#include <string>
using namespace std;

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  [UPI] Rs." << amount << " paid successfully\n";
        return true;
    }
    string getMethodName() override { return "UPI"; }
};

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  Enter 4-digit PIN (type 0000 to simulate a FAILED payment): ";
        string pin;
        cin >> pin;
        if (pin == "0000") {
            cout << "  [Card] Payment FAILED\n";
            return false;
        }
        cout << "  [Card] Rs." << amount << " paid successfully\n";
        return true;
    }
    string getMethodName() override { return "Card"; }
};

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "  [Cash] Rs." << amount << " received\n";
        return true;
    }
    string getMethodName() override { return "Cash"; }
};
