/*

    Write a program that checks if a sentence is correct according to the “English”
    grammar in §6.4.1. Assume that every sentence is terminated by a full stop (.)
    surrounded by whitespace. For example, birds fly but the fish swim . is a sentence,
    but birds fly but the fish swim (terminating dot missing) and birds fly but the fish
    swim. (no space before dot) are not. For each sentence entered, the program should
    simply respond “OK” or “not OK.” Hint: Don’t bother with tokens; just read into a
    string using >>.

*/
#include "../std_lib_facilities.h"

bool isSentence(string& word);
bool isNoun(const string& word);
bool isVerb(const string& word);
bool isConjunction(const string& word);

int main()
{
    try {
        bool m_ok = false;        

        while (true)
        {
            string word;
            m_ok = isSentence(word);
            if (word == ".") {
                if (m_ok) {
                    cout << "OK!" << endl;
                } else {
                    cout << "Not OK!" << endl;
                }
            }
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

bool isSentence(string& word)
{
    cin >> word;
    if (isNoun(word)) {
        string _verb;
        cin >> _verb;
        if (isVerb(_verb)) {
            string _conjunction;
            cin >> _conjunction;
            if (isConjunction(_conjunction)) {
                return isSentence(word);
            } else if (_conjunction == ".") {
                word = _conjunction;
                return true;
            }
        } 
        word = _verb;
    }
    
    return false;
}

bool isNoun(const string& word)
{
    return word == "birds" || word == "fish" || word == "C++";
}

bool isVerb(const string& word)
{
    return word == "rules" || word == "fly" || word == "swim";
}

bool isConjunction(const string& word)
{
    return word == "and" || word == "or" || word == "but";
}