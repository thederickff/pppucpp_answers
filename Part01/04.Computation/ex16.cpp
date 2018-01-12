/* In the drill you wrote a program that, given a series of numbers, 
 * found the max and min of that series. The number that appears the 
 * most time in a sequence is called the mode. Create a program that
 * finds the mode of a set of positive integers.
 */
#include "../std_lib_facilities.h"


vector<int> readSet();
int countRepeatsOf(int number, vector<int> set);

int main() 
{
    vector<int> numbers = readSet();

    int mode = 0;
    int repeats = 0;

    for (int n : numbers) 
    {
        int tempRepeats = countRepeatsOf(n, numbers);

        if (repeats < tempRepeats)
        {
            repeats = tempRepeats;
            mode = n;
        }
    }

    cout << "Mode: " << mode << ", cuz it repeated " << repeats << " times\n";

    return 0;
}


vector<int> readSet()
{
    vector<int> numbers;

    int tempNum;
    while(cin >> tempNum)
    {
        numbers.push_back(tempNum);
    }

    return numbers;
}

int countRepeatsOf(int number, vector<int> set)
{
    int count = 0;
    for (int s : set)
    {
        if (number == s)
            count++;
    }
    return count;
}