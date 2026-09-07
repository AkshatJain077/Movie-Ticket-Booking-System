// 05_Show.cpp
// Responsibility: one screening = a Movie on a Screen at a start time. Owns its ShowSeats.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Show {
private:
    int showId;
    string startTime;
    Movie* movie;      // aggregation: Show borrows a Movie, does not own its lifetime
    Screen* screen;     // aggregation: Show borrows a Screen
    vector<ShowSeat> showSeats;   // composition: created fresh for this show, dies with it

public:
    Show(int showId, string startTime, Movie* movie, Screen* screen)
        : showId(showId), startTime(startTime), movie(movie), screen(screen) {
        for (Seat& s : screen->getSeats()) {
            showSeats.push_back(ShowSeat(s));
        }
    }

    int getShowId() const { return showId; }
    string getStartTime() const { return startTime; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }

    // printing only - must NOT change any seat's status
    void displayLayout() {
        cout << "\n  SCREEN-" << screen->getScreenNumber() << "  " << startTime
             << "  |  " << movie->getTitle() << "\n";
        string currentType = "";
        for (ShowSeat& ss : showSeats) {
            if (ss.getSeat().getTypeName() != currentType) {
                currentType = ss.getSeat().getTypeName();
                cout << "\n  " << currentType << "\t";
            }
            cout << ss.getSeat().getSeatNumber()
                 << (ss.isAvailable() ? "[ ] " : "[X] ");
        }
        cout << "\n\n  ( [ ] = available   [X] = booked )\n";
    }

    ShowSeat* findSeat(string seatNumber) {
        for (ShowSeat& ss : showSeats) {
            if (ss.getSeat().getSeatNumber() == seatNumber) return &ss;
        }
        return nullptr;
    }
};
