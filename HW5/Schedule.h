// Include guards
#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include "Event.h"
#include <string>
#include <iostream>
#include <vector>

class Schedule {
    public:
    // Ctors and Dtors
        // No arg ctor
        Schedule();

        // Ctor that takes an istream
        Schedule(std::istream &);

        // Ctor that takes a c++ string
        Schedule(const std::string &);

        // Ctor that takes a c string
        Schedule(const char*);

        // Copy ctor
        Schedule(const Schedule &);

        // Assignment ctor
        Schedule &operator=(const Schedule &);

        // Dtor
        ~Schedule();

    // Methods
        // Reading methods from an istream and adding them to contents of this schedule
        void read(std::istream &);

        // Make this schedule empty
        void clear();

        // Return the number of events in this Schedule as a size_t
        size_t size() const;

        // Return true iff the schedule is empty
        bool empty();

        // Return the corisponding event by const referance
        const Event &operator[](const size_t &) const;

    private:
        std::vector<Event> events;
};

// Insertion operator
std::ostream &operator<<(std::ostream &, const Schedule &);

#endif /*SCHEDULE_H_INCLUDED*/
