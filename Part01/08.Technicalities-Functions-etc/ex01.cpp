/*
  Modify the calculator program from Chapter 7 to make the input stream an
  explicit parameter (as shown in §8.5.8), rather than simply using cin. Also
  give the Token_stream constructor (§7.8.2) an istream& parameter so that when
  we figure out how to make our own istreams (e.g., attached to files), we can
  use the calculator for those. Hint: Don't try to copy an istream.
*/
#include "../std_lib_facilities.h"

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
public:
	Token_stream() : full(0), buffer(0), is(nullptr) {}
  Token_stream(istream& i) : full(0), buffer(0), is(&i) {}

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
private:
  bool full;
  Token buffer;
  istream* is;
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

const char let = 'L';
const char c_const = 'C';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char help = 'H';

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
		int val;
		cin >> val;
		return Token(number,val);
	}
	case '\\':
	{
		char n;
		cin >> n;
		if (n != 'n') error("n expected");
		return Token(print);
	}
	default:
		if (isspace(ch)) return Token(print);
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s+=ch;
			cin.unget();
      if (s == "help") return Token(help);
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
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

Symbol_table st;

int expression(Token_stream& ts);

int primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	int d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
        return d;
	}
	case '-':
		return - primary(ts);
    case '+':
        return + primary(ts);
	case number:
		return t.value;
	case name:
    {
        Token t2 = ts.get();
        if (t2.kind == '=') {
            return st.set(t.name, expression(ts));
        }
        ts.unget(t2);
		return st.get(t.name);
    }
	default:
		error("primary expected");
	}
}

int term(Token_stream& ts)
{
	int left = primary(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
        case '%':
        {
            int l1 = left;
            int l2 = primary(ts);
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

int expression(Token_stream& ts)
{
	int left = term(ts);
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

int declaration(Token_stream& ts)
{
	Token t = ts.get();
  bool isconst = false;
  if (t.kind == c_const) isconst = true;
  t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	int d = expression(ts);
  st.declare(name, d, isconst);
	return d;
}

int statement(Token_stream& ts)
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
    case c_const:
        ts.unget(t);
        return declaration(ts);
	default:
		ts.unget(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream& ts)
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

void calculate(Token_stream& ts)
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
    if (t.kind == help) {
      showUsage();
      continue;
    }
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement(ts) << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main()

	try {
    Token_stream ts;
    st.declare("pi", 3, true);
    st.declare("e", 2, true);
		calculate(ts);
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
