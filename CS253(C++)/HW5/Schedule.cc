#include "Event.h"
#include "Schedule.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Ctors and Dtors

    // Comparison class for events to tell which comes first
    bool eventCompare(Event ea, Event eb) {
        if (ea.year() < eb.year()) {
            return true;
        }
        else if(ea.year() > eb.year()) {
            return false;
        }
        else {
            if (ea.month() < eb.month()) {
                return true;
            }
            else if(ea.month() > eb.month()) {
                return false;
            }
            else {
                if (ea.day() < eb.day()) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }

    // No args ctor
    Schedule::Schedule() { }

    // Ctor that takes an istream
    Schedule::Schedule(istream &is) {
        Schedule s;
        s.read(is);
    }

    // Ctor that takes a c++ string
    Schedule::Schedule(const string &fileNameIn) {
        filebuf fb;
        if (fb.open(fileNameIn, std::ios::in)) {
            istream is(&fb);
            Schedule s;
            s.read(is);
            fb.close();
        }
        else {
            string errorString = "File: " + fileNameIn + " cannot be opened";
            throw runtime_error(errorString);
        }
    }

    // Ctor that takes a c string
    Schedule::Schedule(const char *fileNameIn) {
        string s(fileNameIn);
        filebuf fb;
        if (fb.open(s, std::ios::in)) {
            istream is(&fb);
            Schedule sch;
            sch.read(is);
            fb.close();
        }
        else {
            string errorStr = "File: " + s + " could not be opened";
            throw runtime_error(errorStr);
        }
    }

    // Copy ctor
    Schedule::Schedule(const Schedule &rhs) {
        for (Event e : rhs.events) {
            events.push_back(e);
        }
    }

    // Assignment ctor
    Schedule &Schedule::operator=(const Schedule &rhs) {
        for (Event e : rhs.events) {
            events.push_back(e);
        }

        return *this;
    }

    // Dtor
    Schedule::~Schedule() {
        events.clear();
    }

// Methods
    // Reading lines from an istream and adding them to contents of this schedule
    void Schedule::read(istream &is) {
        string curString;

        while (is >> curString) {
            try {
                Event e(curString);
                events.push_back(e);
            }
            catch (runtime_error &re) {
                is.setstate(std::ios_base::failbit);
                throw re;
                break;
            }
        }

        sort(events.begin(), events.end(), eventCompare);
    }

    // Make this schedule empty
    void Schedule::clear() {
        events.clear();
    }

    // Return the number of events in this Schedule as a size_t
    size_t Schedule::size() const{
        return events.size();
    }

    // Return true iff the schedule is empty
    bool Schedule::empty() {
        if (events.size() == 0) {
            return true;
        }
        return false;
    }

    // Return the corisponding event by const referance
    const Event &Schedule::operator[](const size_t &numIn) const{
        if (numIn >= this->size()) {
            string errorStr = "Entered number (" + to_string(numIn) +
                ") was out of bounds for the current Schedule";
            throw range_error(errorStr);
        }
        else {
            return events.at(numIn);
        }
    }

    // Insertion operator
    ostream &operator<<(ostream &stream, const Schedule &sch) {
        int forLength = sch.size();
        for (int i = 0; i < forLength; i++) {
            stream << sch[i] << '\n';
        }

        return stream;
    }
