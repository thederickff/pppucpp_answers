/* Write a programthat writes out the first so many values of the Fibonacci series,
 * that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number of the
 * series isthe sum of the two previous ones. Find the largest Fibonacci number that
 * fits in an int.
 */
#include "../std_lib_facilities.h"

int main() 
{
    vector<int> fibs;
    fibs.push_back(1);
    fibs.push_back(1);
    
    for (int i = 1; fibs[i] > 0; ++i) {
        fibs.push_back(fibs[i-1] + fibs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        cout << fibs[i] << endl;
    }
    cout << "..." << endl;
    cout << fibs[fibs.size()-2] << endl;
    
    return 0;
}