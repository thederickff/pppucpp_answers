/* Write a program to solve quadratic equations. A quadratic equations is of the form
 *                               ax2 + bx + c = 0
 * If you don't know the quadratic formula for solving such an expression, do some
 * research. Remember, researching how to solve a problem is often necessary before a
 * programmer can teach the computer how to solve it. Use doubles for the user inputs
 * for a, b, and c. Since there are two solutions to a quadratic equation, output both
 * x1 and x2.
 */
#include "../std_lib_facilities.h"

int main()
{
    double a, b, c, delta, x1, x2;

    cout << "Quadratic equations calculator." << endl;
    cout << "Enter a, b and c separated by blank spaces:";
    cin >> a >> b >> c;

    delta = (b * b) -4 * a * c;


    x1 = (-b + sqrtl(delta)) / 2 * a;
    x2 = (-b - sqrtl(delta)) / 2 * a;

    cout << "X1: " << x1 << endl;
    cout << "X2: " << x2 << endl;

    return 0;
}