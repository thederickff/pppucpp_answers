/* Modify the program from exercise 8 to use double instead of int. Also, make a vector of
 * doubles containing the N-1 differences between adjacent values and write out that vector
 * of differences.
 */
#include "../std_lib_facilities.h"

int main()
{
    vector<double> numbers;
    vector<double> diffs;
    int n = 0;
    double sum = 0;

    cout << "Please enter the numbers of values you want to sum: " << endl;
    cin >> n;
    if (n < 0) error("You have to sum at least one value!");
    cout << "Please enter some doubles (press '|' to stop): " << endl;
    for (double number; cin >> number;) {
        numbers.push_back(number);
        if (numbers.size() >= 2)
            diffs.push_back(number - numbers[numbers.size() - 2]);
    }

    if (numbers.size() < n) error("Sum of more numbers than there are in the vector.");

    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < numbers.size(); ++i) {
        if (i < n) 
        {
            cout << numbers[i] << " ";
            sum += numbers[i];
        }
    }
    cout << ") is " << sum << endl;

    cout << "The differences:\n";
    for (double n : diffs) {
        cout << n << endl;
    }

    return 0;
}