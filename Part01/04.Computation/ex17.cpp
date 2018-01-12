/* Write a program that finds the min, max, and mode of a sequence of strings */
#include "../std_lib_facilities.h"
// globals
string mode;
string maxVal;
string minVal = "zzzzzzzzzz";
// functions header
vector<string> getWords();
int getRepeats(string word, vector<string> list);

int main()
{
    int repeats = 0;
    vector<string> words = getWords();

    for (string w : words)
    {
        if (minVal > w)
        {
            minVal = w;
        }
        if (maxVal < w)
        {
            maxVal = w;
        }
        
        int tempRepetition = getRepeats(w, words);
        if (tempRepetition > repeats)
        {
            repeats = tempRepetition;
            mode = w;
        }
        
    }

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Mode: " << mode << endl;

    return 0;
}

vector<string> getWords()
{
    vector<string> words;
    string tempWord;

    cout << "Type a sequence of strings separated by enters, type ~~ to stop.\n";
    while (cin >> tempWord)
    {
        if (tempWord == "~~") break;
        words.push_back(tempWord);
    }
        
    return words;
}

int getRepeats(string word, vector<string> list)
{
    int count = 0;
    for (string w : list) {
        if (word == w)
            count++;
    }

    return count;
}