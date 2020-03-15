#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string programName;

// Sends an error message if the input isn't formatted correctly
int incorInputFormatError(string offendingData) {
    cerr << programName << ": The string you entered (" << offendingData << ") is not in the correct format" << endl;
    exit(1);
    return 0;
}

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

int findDot(string strIn) {
    if (strIn == "") {
        cerr << programName << ": No text was entered" << endl;
        exit(1);
    }
    int i = 0;
    int stringSize = strIn.size();
    for (i = 0; i < stringSize; i++) {
        if (strIn[i] == '.') {
            if (i == 0) {
                cerr << programName << ": No year was entered" << endl;
                exit(1);
            }

            if (i == stringSize - 1) {
                cerr << programName << ": No day was entered" << endl;
                exit(1);
            }
            return i;
        }
    }

    incorInputFormatError(strIn);
    return false;
}

string parseBefore(string strIn, int dotLocation) {
    // Returning the part of the string that comes before the dot
    return strIn.substr(0, dotLocation);
}

string parseAfter(string strIn, int dotLocation) {
    // Returning the part of the string that comes after the dot
    int stringSize = strIn.size();
    return strIn.substr(dotLocation + 1, stringSize - dotLocation - 1);
}

int getYear(string strIn, int dotLocation) {
    string stringYear = parseBefore(strIn, dotLocation);
    int year = false;
    // Only converts the string if the input is a number
    if (isNumber(stringYear)) {
        year = stoi(stringYear);
    }
    else {
        cerr << programName << ": Year input (" << stringYear << ") was not a number" << endl;
        exit(1);
    }
    if (year < 1 || year > 9999) {
        cerr << programName << ": Year input is (" << stringYear << ") not within acceptable range (0 < year < 10000)" << endl;
        exit(1);
        return false;
    }
    return year;
}

int getDay(string strIn, int dotLocation, bool isLeapYear) {
    string stringDay = parseAfter(strIn, dotLocation);
    int day = false;
    // Only converts the string if the input is a number
    if (isNumber(stringDay)) {
        day = stoi(stringDay);
    }
    else {
        cerr << programName << ": Day input (" << stringDay << ") was not a number." << endl;
        exit(1);
    }
    if (isLeapYear){
        if (day < 1 || day > 366) {
            cerr << programName << ": Day input is (" << stringDay << ") not within acceptable range (0 < year < 367)" << endl;
            exit(1);
            return false;
        }
    }
    else {
        if (day < 1 || day > 365) {
            cerr << programName << ": Day input is (" << stringDay << ") not within acceptable range (0 < year < 366)" << endl;
            exit(1);
            return false;
        }
    }
    return day;
}

// Checks if the number before the dot is a leap year
bool checkLeapYear(int yearIn) {
    if (yearIn % 4 == 0) {
        if (yearIn % 400 == 0) {
            cout << "Is leap year" << endl;
            return true;
        }
        if (yearIn % 100 == 0 && yearIn % 400 != 0) {
            return false;
        }
        return true;
    }
    return false;
}

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

void createFinalOutput(int yearIn, int monthIn, int mdayIn) {
    struct tm * outputStruct;
    time_t t;
    string weekdays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    outputStruct = localtime(&t);

    outputStruct -> tm_year = yearIn - 1900;
    outputStruct -> tm_mon = monthIn - 1;
    outputStruct -> tm_mday = mdayIn;

    mktime(outputStruct);

    string weekday = weekdays[outputStruct -> tm_wday];

    cout << setfill('0') <<
            weekday << ' ' <<
            setw(2) << mdayIn << ' ' <<
            months[monthIn - 1] << ' ' <<
            setw(4) << yearIn <<
            endl;
}

bool outputDate(string strIn) {
    int dotLoc = findDot(strIn);
    if (dotLoc) {
        int year = getYear(strIn, dotLoc);
        bool isLeapYear = checkLeapYear(year);
        if (year) {
            int day = getDay(strIn, dotLoc, isLeapYear);
            if (day) {
                // Convert day and year to the proper output and then output it
                int month = findMonth(day, isLeapYear);
                int mDay = findMDay(day, month, isLeapYear);
                createFinalOutput(year, month, mDay);
                return true;
            }
        }
    }
    return false;
}

void createOutput() {
    string curLine;
    while (getline(cin, curLine)) {
        if (!outputDate(curLine)) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    (void)argc;
    programName = argv[0];

    //Creates the desired output assuming correctly formatted input
    createOutput();

    return 0;
}
