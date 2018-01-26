/*
    Redo the "Bulls and Cows" game from exercise 12 in 
    Chapter 5 to use four letters rather than four digits.
*/
#include "../std_lib_facilities.h"


void separator()
{
    cout << "------------" << endl;
}

int main()
{
    cout << "Bulls and Cows Game." << endl;
    cout << "A word with four letters was generated, have a guess." << endl;
    cout << "One cow means one letter is correct, One bull means one" << endl;
    cout << "letter correct and in the right order." << endl;
    vector<char> letter {'a', 'b', 'c', 'd'};
    vector<char> guesses(4);
    bool running = true;
    int cows, bulls;

    while (running) {
        cows = 0;
        bulls = 0;
        cout << "1st digit: ";
        cin >> guesses[0];
        cout << "2nd digit: ";
        cin >> guesses[1];
        cout << "3rd digit: ";
        cin >> guesses[2];
        cout << "4th digit: ";
        cin >> guesses[3];
        separator();
        for (int i = 0; i < letter.size(); ++i) {
            cout << guesses[i];
            if (guesses[i] == letter[i]) {
                bulls++;
                continue; // steps to the next number rather than checking for cows.
            }
            for (int j = 0; j < guesses.size(); ++j) {
                if (guesses[j] == letter[i]) cows++;
            }
        }
        cout << '\n';
        cout << "Bulls: " << bulls << endl;
        cout << "Cows: " << cows << endl;
        separator();
        if (bulls == 4) running = false;
    }

    return 0;
}