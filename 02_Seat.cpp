// 02_Seat.cpp
// Responsibility: one physical seat - its number and type. Knows its own price.
#include <string>
using namespace std;

enum SeatType { SILVER, GOLD, PLATINUM };

const double SILVER_PRICE = 150.0;
const double GOLD_PRICE = 250.0;
const double PLATINUM_PRICE = 400.0;

class Seat {
private:
    string seatNumber;
    SeatType type;

public:
    Seat(string seatNumber, SeatType type) : seatNumber(seatNumber), type(type) {}

    string getSeatNumber() const { return seatNumber; }
    SeatType getType() const { return type; }

    double getPrice() const {
        if (type == SILVER) return SILVER_PRICE;
        if (type == GOLD) return GOLD_PRICE;
        return PLATINUM_PRICE;
    }

    string getTypeName() const {
        if (type == SILVER) return "SILVER";
        if (type == GOLD) return "GOLD";
        return "PLATINUM";
    }
};
