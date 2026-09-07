// 07_Customer.cpp
// Responsibility: identify who is booking - name and phone. Nothing else.
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phone;

public:
    Customer(string name, string phone) : name(name), phone(phone) {}
    string getName() const { return name; }
    string getPhone() const { return phone; }
};
