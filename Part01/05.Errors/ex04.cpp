/* Do exercise 3 again, but this time handle error inside ctok(). */
#include "../std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
    try {
        if (c < -273.15) error("The lowest temperature that can be reached is -273.15 Celsius");
        return c + 273.15;
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    }
    return -1000;
}

int main()
{
    double c = 0;           // declare input variable
    cin >> c;               // retrieve temperature to input variable
    double k = ctok(c);   // convert temperature
    if (k == -1000)
        return -1;
    cout << k << "k" << '\n';      // print out temperature
           
    return 0;
}