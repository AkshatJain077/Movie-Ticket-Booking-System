// 01_Movie.cpp
// Responsibility: hold a movie's own data (title, language, duration). Nothing else.
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string language;
    int durationMinutes;

public:
    Movie(string title, string language, int durationMinutes)
        : title(title), language(language), durationMinutes(durationMinutes) {}

    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDuration() const { return durationMinutes; }
};
