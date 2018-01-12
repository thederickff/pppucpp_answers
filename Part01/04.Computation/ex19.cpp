/* Write a program where you first enter a set of name-and-value pairs, such as
 * Joe 17 and Barbara 22. For each pair, add the name of the vector called names
 * and the number to a vector called scores (in corresponding positions, so that
 * if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check
 * that each name is unique and terminate with an error message if a name is
 * entered twice. Write out all the (name, score) pairs, one per line.
 */
#include "../std_lib_facilities.h"

int main()
{
    vector<string> names;
    vector<int> scores;

    cout << "Enter a sequence of name-and-value pairs, type 'NoName 0' to stop.\n";
    while (true)
    {
        string name;
        int score;
        cin >> name >> score;
        if (name == "NoName" && score == 0)
            break;

        for (int i = 0; i < names.size(); ++i) {
            if (name == names[i]) {
                cerr << "Error, you tried to enter a name twice." << endl;
                return 0;
            }
        }
        names.push_back(name);
        scores.push_back(score);
    }

    cout << "-----Showing list-----" << endl;
    for (int i=0; i < names.size(); ++i) {
        cout << names[i] << " " << scores[i] << endl;
    }
    return 0;
}