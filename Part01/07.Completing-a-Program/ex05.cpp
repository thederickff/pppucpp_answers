/*
    Simple calculator

    Revision history:

        Revised by Derick Felix December 2017
        Revised by Derick Felix January 2018
        Revised by Derick Felix February 2018
        Originally written by Derick Felix
            (mail@example.com) Summer 2017

    This program implements a basic expression calculator.
    Input from cin; output from cout.
    The grammar for input is:

        Calculation:
            Print
            Quit
            Statement
            Calculation Statement

        Print:
            ;

        Quit
            q


        Statement:
            Declaration
            Assignment
            Expression

        Declaration
            "let" Name "=" Expression
            "Const" Name "=" Expression

        Assignment:
            Name "=" Expression

        Expression:
            Term
            Expression + term
            Expression - term
        Term:
            Primary
            Term * primary
            Term / primary
            Term % primary
        Primary
            Number
            ( Expression )
            + Primary
            - Primary
        Number:
            floating-point-literal

        Input comes from cin through the Token_stream called ts.

*/
#include "../std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, double val) : kind(ch), value(val) { }
    Token(char ch, string n) : kind(ch), name(n) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() : full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

struct Variable {
	string name;
	double value;
    bool isconst;
	Variable(string n, double v) :name(n), value(v) { }
    Variable(string n, double v, bool ic) : name(n), value(v), isconst(ic) { }
};

class Symbol_table {
public:
    double get(string s);
    double set(string s, double d);
    bool is_declared(string s);
    void declare(string s, double v, bool ic);
    void declare(string s, double v);
private:
    vector<Variable> m_var_table;
};

const char let = 'L';
const char c_const = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case print:
    case quit:
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.unget();
			if (s == "let") return Token(let);	
			if (s == "quit") return Token(name);
            if (s == "const") return Token(c_const);
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

double Symbol_table::get(string s)
{
	for (int i = 0; i<m_var_table.size(); ++i)
		if (m_var_table[i].name == s) return m_var_table[i].value;
	error("get: undefined name ",s);
}

void Symbol_table::declare(string s, double d, bool ic)
{
	if (is_declared(s))
		error(s, " declared twice");
	m_var_table.push_back(Variable(s, d, ic));
}

void Symbol_table::declare(string s, double d)
{
    declare(s, d, false);
}

double Symbol_table::set(string s, double d)
{
    for (Variable& v : m_var_table) {
        if (v.name == s) {
            if (v.isconst)
                error("Cannot change const variable named ", v.name);
            else
                v.value = d;
            return v.value;
        }
    }
    error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i<m_var_table.size(); ++i)
		if (m_var_table[i].name == s) return true;
	return false;
}

Token_stream ts;
Symbol_table st;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
        return d;
	}
	case '-':
		return - primary();
    case '+':
        return + primary();
	case number:
		return t.value;
	case name:
    {
        Token t2 = ts.get();
        if (t2.kind == '=') {
            return st.set(t.name, expression());
        } 
        ts.unget(t2);
		return st.get(t.name);
    }
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
        case '%':
        {
            int l1 = narrow_cast<int>(left);
            int l2 = narrow_cast<int>(primary());
            if (l2 == 0) error("divide by zero");
            left = l1 % l2;
            t = ts.get();
        }
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
    bool isconst = false;   
    if (t.kind == c_const) isconst = true;
    t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
    st.declare(name, d, isconst);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
    case c_const:
        ts.unget(t);
        return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
        st.declare("pi", 3.1415926535, true);
        st.declare("e", 2.7182818284, true);
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}