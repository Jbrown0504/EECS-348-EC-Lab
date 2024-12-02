#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;
using std::endl;
using std::stod;

double extractNumeric(const string& str); //prototype


int main()
{
    string input;

    while (true) {
        cout << "Enter a string or \"END\" to quit: ";
        cin >> input;
        if (input == "END") {
            cout << "Ending Program...";
            break;
        }
        if (input.length() > 20) {
            cout << "Invalid String: Input too long" << endl;
            continue;
        }
        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
        else {
            cout << "Invalid String" << endl;
        }
    }
    return 0;
}

double extractNumeric(const string& str) {
    //parse
    string num;
    double output;
    //checks whether first num is a sign operator
    char sign = str[0];
    if (sign == '-' || sign == '+') {
        num = str.substr(1);
    }
    else {
        num = str;
    }
    try {
        output = stod(num);
        if (sign == '-') {
            output = -output;
        }
        return output;
    }
    catch (...) {
        return -999999.99;
    }
}