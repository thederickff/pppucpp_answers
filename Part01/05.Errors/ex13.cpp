/* The program is a bit tedious because the answer is hard-coded into the program.
 * Make a version where the user can play repeteadly (without stopping and restarting
 * the program) and each game has a new set of four digits. You can get four random
 * digits by calling the random number generator randint(10) from std_lib_facilities.h
 * four times. You will note that if you run that program repeteadly, it will pick the
 * same sequence of four digits each time you start the program. To avoid that, ask the
 * user to enter a number (any number) and call srand(n) where n is the number the user
 * entered before calling randint(10). Such an n is called seed, and different seeds give
 * different sequences of random numbers.
 */
#include "../std_lib_facilities.h"


// Start random def
std::mt19937 rng;
std::uniform_int_distribution<std::mt19937::result_type> dist9(1, 9); // distribution in range[1, 9]
// End random def

void separator()
{
    cout << "------------" << endl;
}

int main()
{
    vector<int> number(4);
    vector<int> guesses(4);
    int cows, bulls, attempts = 0;

    do {

        cout << "Bulls and Cows Game." << endl;
        cout << "A number with four digits was generated, have a guess." << endl;
        cout << "One cow means one number is correct, One bull means one" << endl;
        cout << "number correct and in the right order." << endl;
        bool running = true;
        rng.seed(std::random_device()());
        // Generate random numbers    
        for (unsigned int i = 0; i < number.size(); ++i) {
            int generated = 0;
            bool repeated = true;

            while (repeated) {
                repeated = false;
                generated = dist9(rng);
                for (unsigned int j = 0; j < i; ++j) {
                    if (generated == number[j]) repeated = true;
                }
            }

            number[i] = generated;
        }

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
            for (unsigned int i = 0; i < number.size(); ++i) {
                cout << guesses[i];
                if (guesses[i] == number[i]) {
                    bulls++;
                    continue; // steps to the next number rather than checking for cows.
                }
                for (unsigned int j = 0; j < guesses.size(); ++j) {
                    if (guesses[j] == number[i]) cows++;
                }
            }
            cout << '\n';
            cout << "Bulls: " << bulls << endl;
            cout << "Cows: " << cows << endl;
            separator();
            if (bulls == 4) running = false;
            ++attempts;
        }
        cout << "Attempts: " << attempts << endl;
        char again;
        cout << "Do you want to play again? (y/n) ";
        cin >> again;
        if (again == 'n') break;
    } while (true);

    return 0;
}