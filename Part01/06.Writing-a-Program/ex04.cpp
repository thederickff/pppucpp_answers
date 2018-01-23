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