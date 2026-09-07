// 03_Screen.cpp
// Responsibility: one auditorium - its number, and the physical seats fixed inside it.
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {}

    void addSeat(Seat seat) { seats.push_back(seat); }
    int getScreenNumber() const { return screenNumber; }
    vector<Seat>& getSeats() { return seats; }
};
