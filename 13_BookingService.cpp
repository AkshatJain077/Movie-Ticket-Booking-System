// 13_BookingService.cpp
// Responsibility: orchestrate the booking flow end to end. Depends on the
// ABSTRACT Payment type only (Dependency Inversion) - it never mentions
// UpiPayment/CardPayment/CashPayment by name.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class BookingService {
private:
    Cinema* cinema;
    vector<Booking*> bookings;

public:
    BookingService(Cinema* cinema) : cinema(cinema) {}

    // FR4 + FR6: validate ALL seats first (all-or-nothing), then price, then pay.
    Booking* bookSeats(Show* show, vector<string>& seatNumbers, Customer* customer, Payment* payment) {
        vector<ShowSeat*> selected;

        for (string& num : seatNumbers) {
            ShowSeat* ss = show->findSeat(num);
            if (ss == nullptr) {
                cout << "  Invalid seat number: " << num << ". Booking cancelled, nothing changed.\n";
                return nullptr;
            }
            if (!ss->isAvailable()) {
                cout << "  Seat " << num << " is already BOOKED. Booking cancelled, nothing changed.\n";
                return nullptr;
            }
            selected.push_back(ss);
        }

        double amount = PriceCalculator::calculateTotal(selected);
        Booking* booking = new Booking(show, selected, amount, customer);

        for (ShowSeat* ss : selected) ss->book();   // reserve while payment is processed

        cout << "  TOTAL: Rs." << amount << "\n";
        bool paid = payment->pay(amount);            // runtime polymorphism

        if (!paid) {
            for (ShowSeat* ss : selected) ss->release();   // FR6: release seats on failure
            booking->fail();
            cout << "  Booking NOT confirmed. Seats released back to AVAILABLE.\n";
            delete booking;
            return nullptr;
        }

        booking->confirm();
        bookings.push_back(booking);
        return booking;
    }

    // FR8: cancel a confirmed booking, release its seats
    bool cancelBooking(string bookingId) {
        for (Booking* b : bookings) {
            if (b->getBookingId() == bookingId && b->getStatus() == CONFIRMED) {
                for (ShowSeat* ss : b->getSeats()) ss->release();
                b->cancel();
                cout << "  Booking " << bookingId << " cancelled. Seats are AVAILABLE again.\n";
                return true;
            }
        }
        cout << "  Booking ID not found (or already cancelled).\n";
        return false;
    }

    vector<Booking*>& getBookings() { return bookings; }
};
