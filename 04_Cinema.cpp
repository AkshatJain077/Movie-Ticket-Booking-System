// 04_Cinema.cpp
// Responsibility: the theatre - its name, and the screens and shows it owns.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Cinema {
private:
    string name;
    vector<Movie> movies;
    vector<Screen> screens;   // composition: screens belong to this cinema only
    vector<Show> shows;

public:
    Cinema(string name) : name(name) {}

    void addMovie(Movie m) { movies.push_back(m); }
    void addScreen(Screen s) { screens.push_back(s); }
    void addShow(Show s) { shows.push_back(s); }

    vector<Movie>& getMovies() { return movies; }

    // F1: list all movies currently playing
    void listMovies() {
        cout << "\n  Movies now showing:\n";
        for (size_t i = 0; i < movies.size(); i++) {
            cout << "   [" << (i + 1) << "] " << movies[i].getTitle()
                 << "\t" << movies[i].getLanguage()
                 << "\t" << movies[i].getDuration() << " min\n";
        }
    }

    // F2: for a chosen movie, list its shows
    vector<Show*> getShowsForMovie(Movie* movie) {
        vector<Show*> result;
        for (Show& s : shows) {
            if (s.getMovie() == movie) result.push_back(&s);
        }
        return result;
    }
};
