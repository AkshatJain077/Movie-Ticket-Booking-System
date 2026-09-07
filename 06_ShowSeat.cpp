// 06_ShowSeat.cpp
// Responsibility: the AVAILABLE/BOOKED status of ONE seat FOR ONE show.
// Why not just reuse Seat? Seat A1 physically exists once, but its status is
// different per show (booked for 6 PM, free for 9 PM). Status belongs here.
enum SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat seat;
    SeatStatus status;

public:
    ShowSeat(Seat seat) : seat(seat), status(AVAILABLE) {}

    bool isAvailable() const { return status == AVAILABLE; }
    void book() { status = BOOKED; }     // must NOT be called if already booked - caller checks first
    void release() { status = AVAILABLE; }
    Seat& getSeat() { return seat; }
};
