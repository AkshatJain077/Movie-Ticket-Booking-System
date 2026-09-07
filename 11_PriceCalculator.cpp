// 11_PriceCalculator.cpp
// Responsibility: turn a list of seats into a total amount. Pricing logic lives
// ONLY here - not in Booking, not in TicketPrinter. (Single Responsibility)
#include <vector>
using namespace std;

class PriceCalculator {
public:
    static double calculateTotal(vector<ShowSeat*>& seats) {
        double total = 0;
        for (ShowSeat* s : seats) {
            total += s->getSeat().getPrice();
        }
        return total;
    }
};
