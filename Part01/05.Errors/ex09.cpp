/* Modify the program from exercise 8 to write out an error if the result cannot be
 * represented as an int.
 */
#include "../std_lib_facilities.h"

int main()
{
    try {
        int n, sum = 0;
        vector<int> numbers;

        cout << "Please enter the numbers of values you want to sum: " << endl;
        cin >> n;
        cout << "Please enter some integers (press '|' to stop): " << endl;
        for (double number; cin >> number;) {
            numbers.push_back(narrow_cast<int>(number));
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
    } catch (exception& e) {
        cerr << "error: " << e.what() << endl;
    }
    return 0;
}