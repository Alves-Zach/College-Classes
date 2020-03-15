#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Reading input into a vector
    int curNumInt = -1;
    vector<int> nums;
    while (curNumInt != 0) {
        cin >> curNumInt;
        if (curNumInt != 0) {
            nums.push_back(curNumInt);
        }
    }
    int index = 0;
    for (int i : nums) {
        cout << "Integer number " << index + 1 << " is: " << i << '\n';
        index++;
    }
    index = 0;
    cout << '\n';

    // Reading from a file into a string
    string bigString = "";
    string curLine = "";
    ifstream inFile;
    inFile.open("in");
    while (getline(inFile, curLine)) {
        bigString += curLine;
    }

    // Inseting each char from the big string into a multiset
    multiset<char> mset;
    for (char c : bigString) {
        mset.insert(c);
        cout << c << " ";
    }
    cout << '\n';

    for (char c : mset) {
        cout << c << " ";
    }

    // Inserting every char from the multiset into a set
    set<char> cset;
    for (char c : mset) {
        cset.insert(c);
    }
    cout << '\n';

    for (char c : cset) {
        cout << c << " ";
    }

    // couting all the sizes of the containers
    cout << '\n' << '\n' << "Multiset size: " << mset.size() << '\n';
    cout << "Set size: " << cset.size() << '\n';
    cout << "String size: " << bigString.size() << '\n';

    cout << '\n';


}
