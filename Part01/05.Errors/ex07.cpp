/* Quadratic equations are of the form
 *                              a * xe2 + b * x + c = 0
 * To solve these, one uses the quadratic formula:
 *                          x = -b +- sqrt((be2) -4ac) / 2a
 * There is a problem, though: if b2-4ac is less than zero, then it will fail. Write
 * a program that can calculate x for a quadratic equation. Create a function that
 * prints out the roots of a quadratic equation, given a, b, c. When the program
 * detects an equation with no real roots, have it print out a message. How do you
 * know that your results are plausible? Can you check that they are correct?
 */
#include "../std_lib_facilities.h"


double calcDelta(int a, int b, int c)
{
    double d = (b * b) - 4 * a * c;

    if (d < 0) error("There are no roots for this quadratic equation.");

    return d;
}

int main()
{
    try {
        int a, b, c;
        double delta, x1, x2;

        cout << "Quadratic equation solver, give a, b and c values separated by blank spaces.\n";
        cin >> a >> b >> c;

        delta = calcDelta(a, b, c);
        cout << delta << endl;

        x1 = (-b + sqrt(delta)) / 2 * a;
        x2 = (-b - sqrt(delta)) / 2 * a;

        cout << "Root 1: " << x1 << endl;
        cout << "Root 2: " << x2 << endl;

    } catch (exception& e) {
        cerr << e.what() << endl;
    }   
    return 0;
}