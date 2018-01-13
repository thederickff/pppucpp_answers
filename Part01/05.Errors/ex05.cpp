/* Add to the program so that it can also convert from Kelvin to Celsius */
#include "../std_lib_facilities.h"

double ctok(double c) // converts Celsius to Kelvin
{
    if (c < -273.15) error("The lowest temperature that can be reached is -273.15 Celsius");
    return c + 273.15;
}

double ktoc(double k) // converts Kelvin to Celsius.
{
    if (k < 0) error("The lowest temperature that can be reached is 0 Kelvin");
    return k - 273.15;
}

int main()
{
    cout << "Hi, type a temperature and a unit type, for example 456C or 456K:\n";
    cout << "Only Celsius and Kelvin are supported.\n";

    try {
        for (double temp; cin >> temp;)
        {
            char unit;
            double resultTemp;
            char resultUnit;
            cin >> unit;
            // bind result temperature and unit
            if (unit == 'c' || unit == 'C') {
                resultTemp = ctok(temp);
                resultUnit = 'K';
            }
            if (unit == 'k' || unit == 'K') {
                resultTemp = ktoc(temp);
                resultUnit = 'C';
            }
               
            cout << resultTemp << resultUnit << endl;
        }
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
           
    return 0;
}