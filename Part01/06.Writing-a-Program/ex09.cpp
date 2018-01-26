/*
    Write a program that reads digits and composes them into integers. For example,
    123 is read as the characters 1, 2, and 3. The program should output 123 is 1
    hundred and 2 tens and 3 ones. The numbers should be output as an int value.
    Handle numbers with one, two, three, four digits. Hint: To get the integer
    value 5 from the character '5' subtract '0', that is, '5'-'0'==5.
*/
#include "../std_lib_facilities.h"


void thousands(int n);
void hundreds(int n);
void tens(int n);
void ones(int n);

int main()
{
    vector<int> digits;
    vector<string> complements {"ones", "tens", "hundreds", "thousands"};

    cout << "Enter few digits (four is the limit), type . to stop" << endl;

    for (char digit; cin >> digit;)
    {
        if (digit == '.') break;
        digits.push_back(digit - '0');
        if(digits.size() > 3) break;
    }


    for (int digit : digits) {
        cout << digit;
    }

    cout << " is ";

    for (int i = 0; i < digits.size(); ++i) {
        cout << digits[i] << " " << complements[digits.size() - (i+1)] << " ";
    }

    cout << "\n";

    return 0;
}