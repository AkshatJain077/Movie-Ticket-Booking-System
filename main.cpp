// main.cpp
// Course rule was "no header files" -> each class file above is self-contained
// and #included here in DEPENDENCY order (not file-number order) so every
// class is fully defined before the file that uses it needs it.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "06_ShowSeat.cpp"
#include "05_Show.cpp"
#include "04_Cinema.cpp"
#include "07_Customer.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "08_Booking.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

vector<string> splitSeats(string input) {
    vector<string> result;
    stringstream ss(input);
    string item;
    while (getline(ss, item, ',')) {
        while (!item.empty() && item.front() == ' ') item.erase(item.begin());
        while (!item.empty() && item.back() == ' ') item.pop_back();
        if (!item.empty()) result.push_back(item);
    }
    return result;
}

int main() {
    // ---- seed data ----
    Cinema cinema("PVR");

    Movie m1("3 Idiots", "Hindi", 170);
    Movie m2("Interstellar", "English", 169);
    cinema.addMovie(m1);
    cinema.addMovie(m2);

    Screen scr1(1);
    scr1.addSeat(Seat("A1", SILVER)); scr1.addSeat(Seat("A2", SILVER));
    scr1.addSeat(Seat("A3", SILVER)); scr1.addSeat(Seat("A4", SILVER));
    scr1.addSeat(Seat("B1", GOLD));   scr1.addSeat(Seat("B2", GOLD));
    scr1.addSeat(Seat("B3", GOLD));
    scr1.addSeat(Seat("C1", PLATINUM)); scr1.addSeat(Seat("C2", PLATINUM));

    Screen scr2(2);
    scr2.addSeat(Seat("A1", SILVER)); scr2.addSeat(Seat("A2", SILVER));
    scr2.addSeat(Seat("B1", GOLD));   scr2.addSeat(Seat("B2", GOLD));

    cinema.addScreen(scr1);
    cinema.addScreen(scr2);

    Show show1(1, "06:00 PM", &cinema.getMovies()[0], &scr1);
    Show show2(2, "09:00 PM", &cinema.getMovies()[0], &scr2);
    Show show3(3, "08:30 PM", &cinema.getMovies()[1], &scr2);
    cinema.addShow(show1);
    cinema.addShow(show2);
    cinema.addShow(show3);

    BookingService service(&cinema);
    Customer customer("Guest", "9999999999");

    // ---- menu loop ----
    while (true) {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\nChoose: ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            cinema.listMovies();

        } else if (choice == "2") {
            cinema.listMovies();
            cout << "Choose movie: ";
            int mChoice;
            if (!(cin >> mChoice) || mChoice < 1 || mChoice > (int)cinema.getMovies().size()) {
                cout << "  Invalid choice.\n";
                cin.clear(); cin.ignore(1000, '\n');
                continue;
            }
            Movie* movie = &cinema.getMovies()[mChoice - 1];
            vector<Show*> shows = cinema.getShowsForMovie(movie);
            if (shows.empty()) { cout << "  No shows for this movie.\n"; continue; }

            cout << "\nShows:\n";
            for (size_t i = 0; i < shows.size(); i++) {
                cout << "  [" << (i + 1) << "] Screen-" << shows[i]->getScreen()->getScreenNumber()
                     << "   " << shows[i]->getStartTime() << "\n";
            }
            cout << "Choose show: ";
            int sChoice;
            if (!(cin >> sChoice) || sChoice < 1 || sChoice > (int)shows.size()) {
                cout << "  Invalid choice.\n";
                cin.clear(); cin.ignore(1000, '\n');
                continue;
            }
            Show* show = shows[sChoice - 1];
            show->displayLayout();

            cout << "\nSeats (e.g. A1,B2): ";
            cin.ignore();
            string seatInput;
            getline(cin, seatInput);
            vector<string> seatNumbers = splitSeats(seatInput);
            if (seatNumbers.empty()) { cout << "  No seats entered.\n"; continue; }

            cout << "Pay by: 1.UPI  2.Card  3.Cash > ";
            int payChoice;
            if (!(cin >> payChoice) || payChoice < 1 || payChoice > 3) {
                cout << "  Invalid payment choice.\n";
                cin.clear(); cin.ignore(1000, '\n');
                continue;
            }

            Payment* payment;
            if (payChoice == 1) payment = new UpiPayment();
            else if (payChoice == 2) payment = new CardPayment();
            else payment = new CashPayment();

            Booking* booking = service.bookSeats(show, seatNumbers, &customer, payment);
            if (booking != nullptr) TicketPrinter::printTicket(booking);
            delete payment;

        } else if (choice == "3") {
            cout << "Enter booking ID to cancel: ";
            string bid;
            cin >> bid;
            service.cancelBooking(bid);

        } else if (choice == "4") {
            cout << "\nMy tickets:\n";
            for (Booking* b : service.getBookings()) {
                cout << "  " << b->getBookingId() << "  " << b->getShow()->getMovie()->getTitle()
                     << "  Rs." << b->getAmount()
                     << "  [" << (b->getStatus() == CONFIRMED ? "CONFIRMED" : "CANCELLED") << "]\n";
            }

        } else if (choice == "0") {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "  Invalid menu choice. Try again.\n";
        }
    }
    return 0;
}
