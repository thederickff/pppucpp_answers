/* Write a program that reads and stores a series of integers and then computes the sum
 * of the first N integers. First ask for N, then read the values into a vector, then
 * calculate the sum of the first N values. For example:
 * "Please enter the number of values you want to sum:"
 * 3
 * "Please enter some integers (press '|' to stop): "
 * 12 23 13 24 15 |
 * "The sum of the first 3 numbers ( 12 23 13 ) is 48."
 * Handle all inputs. For example, make sure to give an error message if the user asks
 * for a sum of more numbers than there are in the vector.
 */
#include "../std_lib_facilities.h"

int n, sum = 0;
vector<int> numbers;

void getInput()
{
    cout << "Please enter the numbers of values you want to sum: " << endl;
    cin >> n;
    cout << "Please enter some integers (press '|' to stop): " << endl;
    for (int number; cin >> number;) {
        numbers.push_back(number);
    }

    if (numbers.size() < n) error("Sum of more numbers than there are in the vector.");
}

int main()
{
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < numbers.size(); ++i) {
        if (i < n)
        {
            cout << numbers[i] << " ";
            sum += numbers[i];
        }
    }
    cout << ") is " << sum << endl;

    return 0;
}
