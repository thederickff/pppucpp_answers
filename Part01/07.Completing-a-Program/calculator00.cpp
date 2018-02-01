#include "../std_lib_facilities.h"

class Token { // a very simple user-defined type
public:
    char kind;
    double value;
};

class Token_stream {
public:
    Token get(); // get a Token
    void putback(Token t); // put a Token back
private:
    bool full {false}; // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t; // copy t to buffer
    full = true; // buffer is now full
}

Token Token_stream::get()
{
    if (full) { // do we already have a Token ready?
        full = false; // remove Token from buffer
        return buffer;
    }
    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tag, etc.)
    switch (ch) {
        case ';': // for "print"
        case 'q': // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token {ch}; // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch); // put digit back into the input stream
            double val;
            cin >> val;
            return Token {'8', val}; // let '8' represent "a number"
        }
        default:
            error("Bad token");
    }
}

//vector<Token> tok; // we'll put the tokens here
Token_stream ts; // provides get() and putback()
// functions to match the grammar rules:
double expression(); // deal with + and -
double term(); // deal with *, / and %
double primary(); // deal with numbers and parentheses

int main()
{
    try {
        while (cin) {
            cout << ">"; // print prompt
            Token t = ts.get();
            while (t.kind == ';') t=ts.get(); // eat ';'
            if (t.kind == 'q') {
                keep_window_open();
                return 0;
            }
            ts.putback(t);
            cout << "=" << expression() << '\n';
        }
        keep_window_open();
    } 
    catch (exception& e) {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
}

double expression()
{
    double left = term(); // read and evaluate an Term
    Token t = ts.get(); // get next Token from the Token stream

    while (true) {
        switch (t.kind) {
            case '+':
                left += term(); // evaluate Term and add
                t = ts.get();
                break;
            case '-':
                left -= term(); // evaluate Term and subtract
                t = ts.get();
                break;
            default:
                ts.putback(t); // put t back into the token stream
                return left; // finally: no more + or -; return the answer
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get(); // get the next Token from the Token stream
    while (true) {
        switch(t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default: 
                ts.putback(t); // put t back into the token stream
                return left;
        }
    }
}

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(': // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '8': // we use '8' to represent a number
            return t.value; // return the number's value
        default:
            error("primary expected");
    }
}