/*
    Define a class Name_value that holds a string and a value. Rework exercise
    19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
*/
#include "../std_lib_facilities.h"

class Name_value {
public:
    string name;
    int value;
    Name_value(string n, int val) 
    : name(n), value(val) { }
};

int main()
{
    vector<Name_value> nvs;

    cout << "Enter a sequence of name-and-value pairs, type 'NoName 0' to stop.\n";
    while (true)
    {
        string name;
        int score;
        cin >> name >> score;
        if (name == "NoName" && score == 0)
            break;

        for (int i = 0; i < nvs.size(); ++i) {
            if (name == nvs[i].name) {
                cerr << "Error, you tried to enter a name twice." << endl;
                return 0;
            }
        }
        Name_value nv(name, score);
        nvs.push_back(nv);
    }

    cout << "-----Showing list-----" << endl;
    for (int i=0; i < nvs.size(); ++i) {
        cout << nvs[i].name << " " << nvs[i].value << endl;
    }
    return 0;
}