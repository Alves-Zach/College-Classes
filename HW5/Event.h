// Include guards
#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <string>
#include <iostream>

class Event {
    public:
    // Ctors and Dtors
        // Making sure the default ctor doesn't work
        Event() = delete;

        // ctor that has 3 ints for easy making of an object
        Event(int, int, int);

        // ctor that takes a c string
        Event(const char*);

        // ctor that takes a c++ string
        Event(const std::string &);

        // Copy ctor
        Event(const Event &);

        // Assignment operator
        Event &operator=(const Event &);

        // dtor
        ~Event();

    // Methods
        // Sets the date for this event
        void set(int, int, int);

        // Return the year as an int
        int year() const;

        // Return the month as an int
        int month() const;

        // Return the day as an int
        int day() const;

    private:
        int yearE;
        int monthE;
        int dayE;

        bool checkline(std::string);

        bool outputDate(std::string);
};

// ostream things
std::ostream &operator<<(std::ostream &, const Event &);

#endif /*EVENT_H_INCLUDED*/
