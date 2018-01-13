/* Write a program that converts from Celsius to Fahrenheit and from 
 * Fahrenheit to Celcius. Use estimation to see if your results are
 * plausible.
 */
#include "../std_lib_facilities.h"


double ctof(double c)
{
    return ((c * 9) / 5) + 32;
}
double ftoc(double f)
{
    return ((f - 32) * 5) / 9;
}

int main()
{

    cout << "Type a number followed by C to convert from Celsius to Fahrenheit or F\n";
    cout << "to convert from Fahrenheit to Celsius: (type non-number to stop)\n";
    cout << ">";
    for (double temp, tempResult; cin >> temp;)
    {
        char unit, unitResult;
        
        cin >> unit;

        if (unit == 'c' || unit == 'C') {
            tempResult = ctof(temp);
            unitResult = 'F';
        }
        else if (unit == 'f' || unit == 'F') {
            tempResult = ftoc(temp);
            unitResult = 'C';
        }
        else
            error("Error: invalid unit given.");
        
        cout << tempResult << unitResult << endl;
        cout << ">";
    }

    return 0;
}