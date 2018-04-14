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
						Help
            Statement
            Calculation Statement

        Print:
            ;

        Quit
            "quit"
				Help
						"help"


        Statement:
            Declaration
            Assignment
            Expression

        Declaration
            "let" Name "=" Expression
            "Const" Name "=" Expression
            "from" filename
            "to" filename

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
        "From" filename declaration can also read a file as input.

        Output goes to cout and may also goes to a file if a "To" filename
        declaration is defined

*/
#include "std_lib_facilities.h"

ofstream ofs;
ifstream ifs;

class Token {
public:
	char kind;
	int value;
	string name;
	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, int val) : kind(ch), value(val) { }
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
	int value;
  bool isconst;
	Variable(string n, int v) :name(n), value(v) { }
  Variable(string n, int v, bool ic) : name(n), value(v), isconst(ic) { }
};

class Symbol_table {
public:
    int get(string s);
    int set(string s, int d);
    bool is_declared(string s);
    void declare(string s, int v, bool ic);
    void declare(string s, int v);
private:
    vector<Variable> m_var_table;
};

struct Input {
  bool get(char ch)
  {
    if (ifs) return ifs.get(ch);
    else return cin.get(ch);
  }
  void unget()
  {
    if (ifs) ifs.unget();
    else cin.unget();
  }
}

const char let = 'L';
const char c_const = 'C';
const char from_f = 'F';
const char to_f = 'T';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char help = 'H';

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	ist >> ch;

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
	{	ist.unget();
		int val;
		ist >> val;
		return Token(number,val);
	}
	case '\\':
	{
		char n;
		ist >> n;
		if (n != 'n') error("n expected");
		return Token(print);
	}
	default:
		if (isspace(ch)) return Token(print);
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(ist.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_' || ch == '.')) s+=ch;
			ist.unget();
      if (s == "help") return Token(help);
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
      if (s == "const") return Token(c_const);
      if (s == "from") return Token(from_f);
      if (s == "to") return Token(to_f);
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
	while (ist>>ch)
		if (ch==c) return;
}

int Symbol_table::get(string s)
{
	for (int i = 0; i<m_var_table.size(); ++i)
		if (m_var_table[i].name == s) return m_var_table[i].value;
	error("get: undefined name ",s);
}

void Symbol_table::declare(string s, int d, bool ic)
{
	if (is_declared(s))
		error(s, " declared twice");
  m_var_table.push_back(Variable(s, d, ic));
}

void Symbol_table::declare(string s, int d)
{
    declare(s, d, false);
}

int Symbol_table::set(string s, int d)
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

int expression();

int primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	int d = expression();
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

int term()
{
	int left = primary();
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
            int l1 = left;
            int l2 = primary();
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

int expression()
{
	int left = term();
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

int declaration()
{
	Token t = ts.get();
  bool isconst = false;
  if (t.kind == c_const) isconst = true;
  t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	int d = expression();
  st.declare(name, d, isconst);
	return d;
}

int statement()
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

const string prompt = ">>> ";
const string result = "";

void showUsage()
{
  cout << "//////////////////////////////////////////////////\n";
  cout << "Usage: <number> 'operator' <number>';'\n";
  cout << "Operators: + - / * and mod (percentage symbol)\n";
  cout << "e.g: 2 * (54 - 23) / 2; 2 * 3 * (200 - 180);\n";
  cout << "output:\n= 31\n= 120\n";
  cout << "PPPUCPP Calculator (c) 2018\n";
  cout << "Type 'quit' to quit.\n\n";
}

void calculate()
{
	while(true) try {
		cout << prompt;

    if (ifs) {
      ist = ifs;
    } else {
      ist = cin;
    }

		Token t = ts.get();
		while (t.kind == print) t=ts.get();
    if (t.kind == help) {
      showUsage();
      continue;
    }
		if (t.kind == quit) return;

    if (t.kind == from_f) {
      if (ifs) ifs.close();
      Token t2 = ts.get();
      if (t2.kind != 'a') error("file name expected!");
      ifs.open(t2.name);
      continue;
    }

    if (t.kind == to_f) {
      if (ofs) ofs.close();
      Token t2 = ts.get();
      if (t2.kind != 'a') error("file name expected!");
      ofs.open(t2.name);
      continue;
    }

		ts.unget(t);
    int stmt = statement();
		cout << result << stmt << endl;
    if (ofs) {
      ofs << result << stmt << endl;
    }
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

	try {
    st.declare("pi", 3, true);
    st.declare("e", 2, true);
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (ist >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (ist>>c && c!=';');
		return 2;
	}
