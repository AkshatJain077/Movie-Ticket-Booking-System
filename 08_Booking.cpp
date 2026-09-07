// 08_Booking.cpp
// Responsibility: one booking transaction - id, which show, which seats, amount, status.
// (Static member) nextId is shared across all Booking objects to hand out unique IDs.
#include <string>
#include <vector>
using namespace std;

enum BookingStatus { PENDING, CONFIRMED, CANCELLED, FAILED };

class Booking {
private:
    static int nextId;
    string bookingId;
    Show* show;
    vector<ShowSeat*> seats;     // aggregation: Booking references existing ShowSeats, does not own them
    double amount;
    BookingStatus status;
    Customer* customer;

public:
    Booking(Show* show, vector<ShowSeat*> seats, double amount, Customer* customer)
        : show(show), seats(seats), amount(amount), customer(customer), status(PENDING) {
        bookingId = "BK" + to_string(1000 + (++nextId));
    }

    void confirm() { status = CONFIRMED; }
    void fail() { status = FAILED; }
    void cancel() { status = CANCELLED; }

    string getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    vector<ShowSeat*>& getSeats() { return seats; }
    double getAmount() const { return amount; }
    BookingStatus getStatus() const { return status; }
};

int Booking::nextId = 0;
