#include "../std_lib_facilities.h"

// key identifiers
// const string let_key = "#";
const string quit_key  = "exit";
const string sqrt_key = "sqrt";
const string pow_key = "pow";
// Output constans
const string prompt = "> ";
const string result = "= ";
// Token type ids
const char number_id = '8';
const char name_id = 'a';
const char sqrt_id = 'R';
const char pow_id = 'P';

const char let = 'L';
const char quit = 'Q';
const char print = ';';

// Grammatic structure
double primary();
double term();
double expression();
double declaration();
double statement();

struct Token {
	char kind; // type id
	double value; // value if number
	string name; // name if variable
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { } // number constructor
	// Fixed bug: Missing constructor
	Token(char ch, string s) :kind(ch), name(s) { } // variable constructor
};

class Token_stream {
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
private:
	bool full;
	Token buffer;
} ts;


// Token_stream members
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch)
	{
		// Fixed bug: Missing cases
		// operators
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
		case ',':
		case quit:
			return Token(ch);
		// numbers
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
			{	
				cin.unget();
				double val;
				cin >> val;
				return Token(number_id, val);
			}
		// char keywords
		case '#':
			return Token(let);
		// keywords and names
		default:
			if (isalpha(ch))
			{
				string s;
				s += ch;
				// Fixed bug: Wrong operator
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.unget();
				// if (s == let_key) return Token(let);
				// Fixed bug: Wrong variable
				if (s == quit_key) return Token(quit);
				if (s == sqrt_key) return Token(sqrt_id);
				if (s == pow_key) return Token(pow_id);
				return Token(name_id, s);
			}
			error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

// Token stream helpers
void clean_up_mess()
{ 
	ts.ignore(print);
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

// Used to store user-defined variables
vector<Variable> names;

// Variable helpers
double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{ 
	names.push_back(Variable(s, d));
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

// Grammar helpers
double square_root()
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected");

	double d = expression();
	if (d < 0) error("negative square root value");

	t = ts.get();
	if (t.kind != ')') error("')' expected");

	return sqrt(d);
}

double power()
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected");
	double left = expression();

	t = ts.get();
	if (t.kind != ',') error("',' exprected");
	double right = expression();

	t = ts.get();
	if (t.kind != ')') error("')' expected");

	return pow(left, right);
}
// Grammar
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
			{	
				double d = expression();
				t = ts.get();
				if (t.kind != ')') error("')' expected");
				// Bug: Missing return statement
				return d;
			}
		case sqrt_id:
			return square_root();
		case pow_id:
			return power();
		case '-':
			return -primary();
		case number_id:
			return t.value;
		case name_id:
			return get_value(t.name);
		default:
			error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
			case '*':
				left *= primary();
				break;
			case '/':
				{
					double d = primary();
					if (d == 0) error("divide by zero");
					left /= d;
					break;
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
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
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
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	set_value(name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

// Main and helpers
void calculate()
{
	// wait for input until user exits
	while (true) try
	{
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try
{
	// predefined variables
	set_value("k", 1000);

	calculate();
	return 0;
}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...)
{
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}