/* Modify the program from exercise 19 so that when you enter a name, the program will output
 * the corresponding score or name not found.
 */
#include "../std_lib_facilities.h"
// global variables
vector<string> names;
vector<int> scores;
// function headers
void search(string name);

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

        for (int i = 0; i < names.size(); ++i) 
        {
            if (name == names[i]) {
                cerr << "Error, you tried to enter a name twice." << endl;
                return 0;
            }
        }
        names.push_back(name);
        scores.push_back(score);
    }

    cout << "Type a name, and I will give you its score type 'NoName' to stop." << endl;
    for (string name; cin >> name;) 
    {
        if (name == "NoName") break;

        search(name);
    }
    return 0;
}

void search(string name)
{
    for (int i = 0; i < names.size(); ++i) 
    {
        if (name == names[i]) {
            cout << "Score: " << scores[i] << endl;
            return;
        }
    }
    cout << "Name not found." << endl;
}