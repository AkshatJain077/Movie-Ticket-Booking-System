// 12_TicketPrinter.cpp
// Responsibility: format and print a ticket. PRINTING ONLY - must NOT calculate
// price and must NOT change booking/seat status. (Single Responsibility)
#include <iostream>
#include <vector>
using namespace std;

class TicketPrinter {
public:
    static void printTicket(Booking* booking) {
        cout << "\n  ================ TICKET ================\n";
        cout << "   Booking ID : " << booking->getBookingId() << "\n";
        cout << "   Movie      : " << booking->getShow()->getMovie()->getTitle() << "\n";
        cout << "   Screen     : Screen-" << booking->getShow()->getScreen()->getScreenNumber()
             << "   " << booking->getShow()->getStartTime() << "\n";
        cout << "   Seats      : ";
        vector<ShowSeat*>& seats = booking->getSeats();
        for (size_t i = 0; i < seats.size(); i++) {
            cout << seats[i]->getSeat().getSeatNumber();
            if (i != seats.size() - 1) cout << ", ";
        }
        cout << "\n   Amount     : Rs." << booking->getAmount() << "\tStatus: CONFIRMED\n";
        cout << "  ==========================================\n";
    }
};
