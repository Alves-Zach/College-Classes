#include "Event.h"
#include <string>

using namespace std;

// Code from HW3 that reads inputs

// Checks to make sure the chars before and after the dot are both numbers
bool isNumber(string strIn) {
    int stringSize = strIn.size();
    for (int i = 0; i < stringSize; i++) {
        if (!isdigit(strIn[i])) {
            // If one of the chars isn't a number, throw an error saying that one of the chars
            // isn't a number
            return false;
        }
    }
    return true;
}

// Finds the dot in the YYYY.DDD format
int findDot(string strIn) {
    if (strIn == "") {
        throw runtime_error("No text was entered");
        exit(1);
    }
    int i = 0;
    int stringSize = strIn.size();
    for (i = 0; i < stringSize; i++) {
        if (strIn[i] == '.') {
            if (i == 0) {
                throw runtime_error("No year was entered");
                exit(1);
            }

            if (i == stringSize - 1) {
                throw runtime_error("No day was entered");
                exit(1);
            }
            return i;
        }
    }

    return false;
}

// Parses before the dot in YYYY.DD format
string parseBefore(string strIn, int dotLocation) {
    // Returning the part of the string that comes before the dot
    return strIn.substr(0, dotLocation);
}

// Parses after the dot in YYYY.DD format
string parseAfter(string strIn, int dotLocation) {
    // Returning the part of the string that comes after the dot
    int stringSize = strIn.size();
    return strIn.substr(dotLocation + 1, stringSize - dotLocation - 1);
}

// Checks if the year that was input is a leap year
bool checkLeapYear(int yearIn) {
    if (yearIn % 4 == 0) {
        if (yearIn % 400 == 0) {
            return true;
        }
        if (yearIn % 100 == 0 && yearIn % 400 != 0) {
            return false;
        }
        return true;
    }
    return false;
}

// Gets the year in the YYYY.DD format
int getYear(string strIn, int dotLocation) {
    string stringYear = parseBefore(strIn, dotLocation);
    int year = false;
    // Only converts the string if the input is a number
    if (isNumber(stringYear)) {
        year = stoi(stringYear);
    }
    else {
        string errorStr = ": Year input (" + stringYear + ") was not a number";
        throw runtime_error(errorStr);
        exit(1);
    }
    if (year < 1 || year > 9999) {
        string errorStr = "Year input is (" + stringYear + ") not " +
            "within acceptable range (0 < year < 10000)";
        throw runtime_error(errorStr);
        exit(1);
        return false;
    }
    return year;
}

// Finds month based on the int input
int findMonth(int dayIn, bool isLeapYear) {
    // Leap year checking
    int leap  = 0;
    if (isLeapYear) {
        leap++;
    }

    if (dayIn <= 31) {
        return 1; // Jan
    }
    if (dayIn <= 59 + leap) {
        return 2; // Feb
    }
    if (dayIn <= 90 + leap) {
        return 3; // Mar
    }
    if (dayIn <= 120 + leap) {
        return 4; // Apr
    }
    if (dayIn <= 151 + leap) {
        return 5; // May
    }
    if (dayIn <= 181 + leap) {
        return 6; // Jun
    }
    if (dayIn <= 212 + leap) {
        return 7; // Jul
    }
    if (dayIn <= 243 + leap) {
        return 8; // Aug
    }
    if (dayIn <= 274 + leap) {
        return 9; // Sep
    }
    if (dayIn <= 304 + leap) {
        return 10; // Oct
    }
    if (dayIn <= 334 + leap) {
        return 11; // Nov
    }
    else {
        return 12; // Dec
    }
}

// Finds the day of the month based on the day of the year
int findMDay(int dayIn, int monthIn, bool isLeapYear) {
    int leap = 0;
    if (isLeapYear) {
        leap++;
    }

    int mDay = dayIn;

    switch (monthIn) {
        default:
            return mDay;
            break;
        case 2:
            return mDay - 31;
            break;
        case 3:
            return mDay - 59 - leap;
            break;
        case 4:
            return mDay - 90 - leap;
            break;
        case 5:
            return mDay - 120 - leap;
            break;
        case 6:
            return mDay - 151 - leap;
            break;
        case 7:
            return mDay - 181 - leap;
            break;
        case 8:
            return mDay - 212 - leap;
            break;
        case 9:
            return mDay - 243 - leap;
            break;
        case 10:
            return mDay - 274 - leap;
            break;
        case 11:
            return mDay - 304 - leap;
            break;
        case 12:
            return mDay - 334 - leap;
            break;
    }
}

// Gets the day in the YYYY.DD format
int getDay(string strIn, int dotLocation, bool isLeapYear) {
    string stringDay = parseAfter(strIn, dotLocation);
    int day = false;
    // Only converts the string if the input is a number
    if (isNumber(stringDay)) {
        day = stoi(stringDay);
    }
    else {
        string errorStr = "Day input (" + stringDay + ") was not a number.";
        throw runtime_error(errorStr);
        exit(1);
    }
    if (isLeapYear){
        if (day < 1 || day > 366) {
            string errorStr = "Day input is (" + stringDay + ") not" +
                " within acceptable range (0 < year < 367)";
            throw runtime_error(errorStr);
            exit(1);
            return false;
        }
    }
    else {
        if (day < 1 || day > 365) {
            string errorStr = "Day input is (" + stringDay + ") not " +
                "within acceptable range (0 < year < 366)";
            throw runtime_error(errorStr);
            exit(1);
            return false;
        }
    }
    return day;
}

// Checks the input for format YYYY-MM-DD
bool checkISOFormat(string strIn) {
    int strLength = strIn.length();
    if ( strLength != 10) {
        string errorStr = "Input (" + strIn + ") was not in a proper format";
        throw runtime_error(errorStr);
        return false;
    }
    else if (strIn[4] != '-' || strIn[7] != '-') {
        string errorStr = "Input (" + strIn + ") was not in a proper format";
        throw runtime_error(errorStr);
        return false;
    }
    return true;
}

// Gets the year in the YYYY-MM-DD format
int getYearISO(string strIn) {
    string yearStr = strIn.substr(0, 4);
    if (isNumber(yearStr)) {
        return stoi(yearStr);
    }
    return -1;
}

// Gets the month in the YYYY-MM-DD format
int getMonthISO(string strIn) {
    string monthStr = strIn.substr(5, 2);
    if (isNumber(monthStr)) {
        int monthOut = stoi(monthStr);
        if (monthOut < 13) {
            return monthOut;
        }
        else {
            string errorStr = "Month input (" + monthStr + ") is invalid, " +
                "must be between 1 and 12";
            throw runtime_error(errorStr);
            return -1;
        }
    }
    return -1;
}

// Checks that the day input in ISO format is within the number of days for the specified month
bool checkDayISO(int dayIn, int monthIn, bool leapIn) {
    // Months that have 31 days in them
    if (dayIn > 31) {
        string errorStr = dayIn + " is not a valid day input for month " + monthIn;
        throw runtime_error(errorStr);
        return false;
    }
    else if (monthIn == 4 || monthIn == 6 || monthIn == 9 || monthIn == 11) {
        if (dayIn > 30) {
            string errorStr =  dayIn + " is not a valid day input for month " + monthIn;
            throw runtime_error(errorStr);
            return false;
        }
    }
    else if (monthIn == 2) {
        if (leapIn) {
            if (dayIn > 29) {
                string errorStr = dayIn + " is not a valid day input for month " +
                    to_string(monthIn) + " for this year";
                throw runtime_error(errorStr);
                return false;
            }
        }
        else if (dayIn > 28) {
                string errorStr = dayIn + " is not a valid day input for month " +
                    to_string(monthIn) + " for this year";
                throw runtime_error(errorStr);
                return false;
        }
    }

    return true;
}

// Gets the day in the YYYY-MM-DD format
int getDayISO(string strIn, int monthIn, bool leapIn) {
    string dayStr = strIn.substr(8, 2);
    if (isNumber(dayStr)) {
        int dayOut = stoi(dayStr);
        if (checkDayISO(dayOut, monthIn, leapIn)) {
            return dayOut;
        }
    }
    return -1;
}


// Gets the year month and day as ints based on input regardless of format
bool Event::outputDate(string strIn) {
    int dotLoc = findDot(strIn);
    // Checks for YYYY.DDD format
    if (dotLoc) {
        int year = getYear(strIn, dotLoc);
        bool isLeapYear = checkLeapYear(year);
        if (year) {
            int day = getDay(strIn, dotLoc, isLeapYear);
            if (day) {
                // Convert day and year to the proper output and then output it
                int month = findMonth(day, isLeapYear);
                int mDay = findMDay(day, month, isLeapYear);

                // Setting this event's members
                yearE = year;
                monthE = month;
                dayE = mDay;

                return true;
            }
        }
    }
    else {
        // Checks for YYYY-MM-DD format
        if (checkISOFormat(strIn)) {
            // Getting the year and month
            int year = getYearISO(strIn);

            if (year > 0) {
                int month = getMonthISO(strIn);

                if (month > 0) {
                    // Checking for leap year
                    bool leap = checkLeapYear(year);
                    // Getting the day and checking it based on the month and leap year status
                    int day = getDayISO(strIn, month, leap);

                    if (day > 0) {
                        // Setting this event's members
                        yearE = year;
                        monthE = month;
                        dayE = day;

                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Checking if the input from stdin is calling for today
bool checkTodYesTom(string strIn, string checkStringIn) {
    string checkString = checkStringIn;
    if (strIn.size() != checkString.size()) {
        return false;
    }

    for (size_t i = 0; i < checkString.length(); i++) {
        if (tolower(strIn[i]) != checkString[i]) {
            return false;
        }
    }
    return true;
}

// Checking the current line for valid inputs
// Also sets the event's members if input is today, tomorrow, or yesterday
bool Event::checkline(string strIn) {
    if (checkTodYesTom(strIn, "today")) {
        // Enter today's date into createFinalOutput
        struct tm *outputStruct;
        time_t t;
        time(&t);

        outputStruct = localtime(&t);

        // The -1900 and -1 is required because of how time() gets the date
        int yearOut = outputStruct -> tm_year + 1900;
        int monthOut = outputStruct -> tm_mon + 1;
        int dayOut = outputStruct -> tm_mday;

        yearE = yearOut;
        monthE = monthOut;
        dayE = dayOut;

        return 1;
    }
    else if (checkTodYesTom(strIn, "yesterday")) {
        // Enter yesterday's date into createFinalOutput
        struct tm *outputStruct;
        time_t t;
        time(&t);

        outputStruct = localtime(&t);

        // The -1900 and -1 is required because of how time() gets the date
        int yearOut = outputStruct -> tm_year + 1900;
        int monthOut = outputStruct -> tm_mon + 1;

        // Getting yesterday's day
        int dayOut = outputStruct -> tm_mday - 1;

        yearE = yearOut;
        monthE = monthOut;
        dayE = dayOut;

        return 1;
    }
    else if (checkTodYesTom(strIn, "tomorrow")) {
        // Enter tomorrow's date into createFinalOutput
        struct tm *outputStruct;
        time_t t;
        time(&t);

        outputStruct = localtime(&t);

        // The -1900 and -1 is required because of how time() gets the date
        int yearOut = outputStruct -> tm_year + 1900;
        int monthOut = outputStruct -> tm_mon + 1;

        // Getting tomorrow's day
        int dayOut = outputStruct -> tm_mday + 1;

        yearE = yearOut;
        monthE = monthOut;
        dayE = dayOut;

        return 1;
    }
    else if (outputDate(strIn)) {
        return 1;
    }

    return 0;
}

// Ctors and Dtors

    // ctor that takes a c string
    // This can have input in one of the 5 different HW3 formats, so I'm including a lot
    // of HW3 code above these ctors
    Event::Event(const char *strIn) {
        string convertedString(strIn);

        if (!checkline(convertedString)) {
        }
     }

    // ctor that takes a c++ string
    Event::Event(const string &strIn) {
        if (!checkline(strIn)) {
        }
    }

    // Copy ctor
    Event::Event(const Event &rhs) :
    yearE(rhs.year()), monthE(rhs.month()), dayE(rhs.day()) { }

    // Assignment operator
    Event &Event::operator=(const Event &rhs) {
        yearE = rhs.year();
        monthE = rhs.month();
        dayE = rhs.day();

        return *this;
    }

    // dtor
    Event::~Event() {}

// Methods

    // Sets the member functions of the event
    void Event::set(int year, int month, int day) {
        if (year > 9999 || year < 1) {
            string errorStr = "Year (" + to_string(year) + ") is an invalid year input";
            throw runtime_error(errorStr);
        }
        else if (month > 12 || month < 1) {
            string errorStr = "Month (" + to_string(month) + ") is an invalid month input";
            throw runtime_error(errorStr);
        }
        else if (day > 31 || day < 1) {
            string errorStr = "Day (" + to_string(day) + ") is an invalid day input";
            throw runtime_error(errorStr);
        }


        if (checkDayISO(day, month, checkLeapYear(year))) {
            yearE = year;
            monthE = month;
            dayE = day;
        }
    }

    // Return the year as an int
    int Event::year() const {
        return yearE;
    }

    // Return the month as an int
    int Event::month() const {
        return monthE;
    }

    // Return the day as an int
    int Event::day() const {
        return dayE;
    }

    // ostream things
    std::ostream &operator<<(std::ostream &stream, const Event &eIn) {
        struct tm * outputStruct;
        time_t t;

        outputStruct = localtime(&t);

        outputStruct -> tm_year = eIn.year() - 1900;
        outputStruct -> tm_mon = eIn.month() - 1;
        outputStruct -> tm_mday = eIn.day();

        mktime(outputStruct);

        char finalOutput[64];

        const char *finalFormat = "%4Y-%m-%d";

        strftime(finalOutput, 64, finalFormat, outputStruct);

        return stream << finalOutput;
    }
