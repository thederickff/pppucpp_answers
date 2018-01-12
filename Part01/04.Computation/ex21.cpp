/* Modify the program from exercise 19 so that when you enter an integer, the program
 * will output all the names with that score or score not found.
 */
#include "../std_lib_facilities.h"
// global variables
vector<string> names;
vector<int> scores;
// function headers
void search(int score);

int main()
{
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

    cout << "Type a score, and I will give you the owner of that score, type (0) to stop.\n";

    for (int n; cin >> n; )
    {
        if (n == 0)
            break;
        search(n);
    }

    return 0;
}

void search(int score)
{
    for (int i = 0; i < scores.size(); ++i)
    {
        if (score == scores[i])
        {
            cout << "Name: " << names[i] << endl;
            return;
        }
    }
    cout << "Score not found." << endl;
}