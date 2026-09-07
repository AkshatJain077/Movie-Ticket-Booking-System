// 09_Payment.cpp
// Responsibility: the payment CONTRACT only. pay() is pure virtual - no body here.
// (Abstraction) Any new payment method just extends this; nothing else changes.
#include <string>
using namespace std;

class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual string getMethodName() = 0;
    virtual ~Payment() {}
};
