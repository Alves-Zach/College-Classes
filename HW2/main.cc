#include <iostream>
#include <string>
#include <vector>

using namespace std;

string programName;

int isOperator(string argIn) {
        // Checking what operator was used
        if (argIn == "+") {
            return 1;
        }
        if (argIn == "-") {
            return 2;
        }
	if (argIn == "*") {
            return 3;
        }
	if (argIn == "/") {
            return 4;
        }
        if (argIn == "@") {
            return 5;
        }
	// Returning 0 if it's not an operator
        return 0;
}

int isOption(string argIn) {
    // Checking what option was used
    if (argIn == "-d") {
        // Decimal
        return 1;
    }
    if (argIn == "-h") {
        // Hexidecimal
        cout << hex;
        return 2;
    }
    if (argIn == "-o") {
        // Octal
        cout << oct;
        return 3;
    }
    // Returning 0 if it's not an option
    return 0;
}

int checkNumArgs(int numArgs, int minArgs) {
    if (numArgs >= minArgs) {
        return 1;
    }
    cerr << programName << ": Not enough input arguments" << endl;
    return 0;
}

bool isNumber(string strIn, int base) {
    // Decimal
    if (base == 1) {
        // Checking each digit to see if it's in range
        for (char c : strIn) {
            if (c > '9' || c < '0') {
                cerr << programName << ": " << strIn << " is not a valid decimal number" << endl;
                return 0;
            }
        }
        return 1;
    }
    // Hexidecimal
    if (base == 2) {
        // Checking if the input is only the 0x
        if (strIn.length() == 2) {
            cerr << programName << ": " << strIn << " is not a valid hexidecimal number" << endl;
            return 0;
        }

        // Checking each digit to see if it's in range
        for (char c : strIn.substr(2, strIn.length() - 2)) {
            if ((c > '9' || c < '0') && (c < 'a' || c > 'f')) {
                cerr << programName << ": " << strIn << " is not a valid hexidecimal number" << endl;
                return 0;
            }
        }
        return 1;
    }
    // Octal
    if (base == 3) {

        for (char c : strIn.substr(1, strIn.length() - 1)) {
            if (c > '7' || c < '0') {
                cerr << programName << ": " << strIn << " is not a valid octal number" << endl;
                return 0;
            }
        }
        return 1;
    }
    // Binary
    if (base == 4) {
        // Checking if the input is only the 0b
        if (strIn.length() == 2) {
            cerr << programName << ": " << strIn << " is not a valid binary number" << endl;
            return 0;
        }

        // Checking each digit to see if it's in range
        for (char c : strIn.substr(2, strIn.length() - 2)) {
            if (c != '1' && c!= '0') {
                cerr << programName << ": " << strIn << " is not a valid binary number" << endl;
                return false;
            }
        }
        return 1;
    }
    return 0;
}

int baseToStoi(int baseIn) {
    if (baseIn == 1) {
        return 10;
    }
    if (baseIn == 2) {
        return 16;
    }
    if (baseIn == 3) {
        return 8;
    }
    if (baseIn == 4) {
        return 2;
    return 0;
    }
    return 10;
}

int getBaseInput(string strIn) {
    if (strIn[0] == '0') {
        if (strIn[1] == 'x') {
            // Hexidecimal
            return 2;
        }
        if (strIn[1] == 'b') {
            // Binary
            return 4;
        }
        // Octal
        return 3;
    }
    // Decimal
    return 1;
}

vector<int> convertInput(char *arrIn[], int numArgsIn, int startingPos) {
    vector<int> returnArr;
    int baseSTOI;
    string curArg;
    int base;

    for (int i = startingPos; i < numArgsIn; i++) {
        // Setting the current char pointer to a string
        curArg = arrIn[i];
        base = getBaseInput(curArg);
        baseSTOI = baseToStoi(base);
        if (isNumber(curArg, base)) {
            if (curArg == "0") {
                returnArr.push_back(0);
            }
            else if (base != 1 && base != 3) {
                // Storing the current argument in the vector as an in rather than as a string
                returnArr.push_back(stoi(curArg.substr(2, curArg.length() - 1), nullptr, baseSTOI));
            }
            else if (base == 1) {
                returnArr.push_back(stoi(curArg, nullptr, baseSTOI));
            }
            else if (base == 3) {
                returnArr.push_back(stoi(curArg.substr(1, curArg.length() - 1), nullptr, baseSTOI));
            }
        }
        else {
            vector<int> emptyVector;
            return emptyVector;
        }
    }
    return returnArr;
}

void calcResult(vector<int> vectIn, int operatorNum) {
    // Check if empty to not output anything
    if (!vectIn.empty()) {
        int result = 0;
        switch (operatorNum) {
            case 1:     // +
                // for loop with +
                for (int i : vectIn) {
                    result += i;
                }

                // Actually outputting the sum
                cout << result << endl;
                break;
                case 2: {       // -
                    // for loop with -
                    result = vectIn[0];
                    int vectSize = vectIn.size();
                    for (int i = 1; i < vectSize; i++) {
                        result = result - vectIn[i];
                    }

                    // Have to flip sign and then slap a negative sign on if it's negative
                    // Negative hex values print weird
                    if (result < 0) {
                        result *= -1;
                        cout << '-' << result << endl;
                    }
                    // Outputing like normal if it's above 0 or at 0
                    else {
                        cout << result << endl;
                    }
                    break;
                }
                case 3:     // *
                    result = 1;
                    // for loop with *
                    for (int i : vectIn) {
                        result *= i;
                    }

                    cout << result << endl;
                    break;
                case 4:     {       // /
                    result = vectIn[0];
                    int vectSize = vectIn.size();
                    int divByZero = 0;
                    // for loop with /
                    for (int i = 1; i < vectSize; i++) {
                        // Checking for division by 0 error
                        if (vectIn[i] == 0) {
                            cerr << programName << ": Divide by zero error at operand " << i + 1 << endl;
                            divByZero = 1;
                            break;
                        }
                        else  {
                            result /= vectIn[i];
                        }
                    }

                    if (!divByZero) {
                        cout << result << endl;
                    }
                    break;
                }
                case 5:
                        // do @ stuff
                        result = -1;
                        int curDiff;
                        int curMaxDiff = 0;

                        for (int i : vectIn) {
                            curDiff = abs(i - 45);
                            if (curDiff >= curMaxDiff) {
                                curMaxDiff = curDiff;
                                result = i;
                            }
                        }

                        cout << result << endl;
                        break;
                }
            }
}

int main(int argc, char *argv[]) {
    programName = argv[0];

    if (checkNumArgs(argc, 2)) {
        string firstArg = argv[1];
	// Checking if the first arg is an operator
        int firstArgReturn = isOperator(firstArg);
        if (firstArgReturn) {
            vector<int> convertedInput = convertInput(argv, argc, 2);
            calcResult(convertedInput, firstArgReturn);
        }
        else if (isOption(argv[1]) && checkNumArgs(argc, 3)){
            // First arg must be an option or throw an error
            string operatorStr = argv[2];
            int operatorInt = isOperator(operatorStr);
            if (operatorInt) {
                vector<int> convertedInput = convertInput(argv, argc, 3);
                calcResult(convertedInput, operatorInt);
            }
            else {
                cerr << programName << " : " << argv[2] << "is not a valid operator" << endl;
            }
        }
	else {
            cerr << programName << ": " << firstArg << " Is not a valid operator or option" << endl;
            return 0;
        }
    }

    return 0;
}
