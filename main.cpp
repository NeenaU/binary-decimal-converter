#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

string dtbResult = "2";

/**
 * Method used to concatenate a string and integer together to help form the result of a decimal to binary conversion
 * @param a: The string to be concatenated
 * @param b: The int to be concatenated
 * @return: The result of the concatenation in the form of an int
 */
string concatenate(string a, int b) {
    string c;

    if (dtbResult == "2") { //The first calculation has been performed, no concatenation is needed
        c = to_string(b);
    }
    else {
        c = a+to_string(b);
    }

    return c;

}

int main() {
    int option, number, finalResult;

    cout << "Welcome to the Binary Decimal Converter\n";
    cout << "Enter 1 if you would like to convert from binary to decimal\nEnter 2 if you would like to convert from decimal to binary\n";
    cin >> option;

    cout << "Enter the number you would like to convert" << endl;
    cin >> number;

    //Convert binary to decimal by iterating through each digit in the number, multiplying it by 2^i and adding this to the final result
    //i starts at 0 and increases by 1 with each iteration
    if (option == 1) {

        int temp, digits;
        digits++;
             temp = number;

        while (temp != 0) { //Find the number of digits in the number
            digits++;
            temp = temp/10;
        }
        digits++;

        int currentDigit, multiplier, two;
        multiplier = 1;
        two = 2;

        //Calculate result
        for (int i=0; i<digits; i++) {
            currentDigit = number / multiplier % 10;
            finalResult = finalResult + currentDigit*(pow(two, i));

            multiplier*=10;
        }
    }
    //Convert decimal to binary by continuously dividing by 2 and finding the remainder
    //The remainders are put together in reverse order to form the result
    else if (option == 2) {

        int modResult, workingNumber;

        workingNumber = number;

        while (workingNumber != 0) {
            workingNumber = workingNumber/2;
            modResult = workingNumber%2;

            dtbResult = concatenate(dtbResult, modResult);
        }

        istringstream iss(dtbResult);
        iss >> finalResult;
    }

    cout << "The result is " << finalResult;

    return 0;
}