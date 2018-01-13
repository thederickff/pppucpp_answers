/*
 * Absolute zero is the lowest temperature that can be reached; it is -273.15C, or 0K.
 * The above program, even when corrected, will produce erroneous results when given a
 * temperature below this. Place a check in the main program that will produce an error
 * if a temperature is given below -273.15C.
 */
#include "../std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
    if (c < -273.15) error("The lowest temperature that can be reached is -273.15 Celsius");

    return c + 273.15;
}

int main()
{
    try {
        double c = 0;           // declare input variable
        cin >> c;               // retrieve temperature to input variable
        double k = ctok(c);   // convert temperature
        cout << k << "k" << '\n';      // print out temperature
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 0;
    }
}