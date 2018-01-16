/* Implement a little guessing game called (for some obscure reason) "Bulls and Cows".
 * The program has a vector of four different integers in the range 0 to 9 (e.g, 1234 but
 * not 1122) and it is the user's tasks to discover those numbers by repeated guesses.
 * Say the number to be guessed is 1234 and the user guesses 1359; the response should be
 * "1 bull and 1 cow" because the user got one digit (1) right and in the right position
 * (a bull) and one digit (3) right but in the wrong position (a cow). The guessing 
 * continues until the user gets four bulls, that is, has the four digits correct and in
 * the correct order.
 */
#include "../std_lib_facilities.h"


void separator()
{
    cout << "------------" << endl;
}

int main()
{
    cout << "Bulls and Cows Game." << endl;
    cout << "A number with four digits was generated, have a guess." << endl;
    cout << "One cow means one number is correct, One bull means one" << endl;
    cout << "number correct and in the right order." << endl;
    vector<int> number {1, 2, 3 ,4};
    vector<int> guesses(4);
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
        for (int i = 0; i < number.size(); ++i) {
            cout << guesses[i];
            if (guesses[i] == number[i]) {
                bulls++;
                continue; // steps to the next number rather than checking for cows.
            }
            for (int j = 0; j < guesses.size(); ++j) {
                if (guesses[j] == number[i]) cows++;
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