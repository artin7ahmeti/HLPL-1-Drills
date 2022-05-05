#include "std_lib_facilities.h" //Include usual header
// Some symbolic constants for clarity
constexpr char number = '8';
constexpr char quit = 'q';
const string declexit = "exit"; // for closing the program
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char result = '=';
constexpr char func = 'f'; // sqrt and pow functions
constexpr char* declkey = "#";

//function declarations
double expression();
double primary();
double term();
double declaration();
double statement();
double funct();

// Variable ///////////////////////
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s)
{
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable ", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}
// Variable end ///////////////////////

// Token ///////////////////////
class Token {
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};
// Token end ///////////////////////

// Token_stream ///////////////////////
class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
    Token t;
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case print:
		case quit:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
        case ',': //case necessary for pow() function.
            return Token(ch);
            break;
		case '%':
		case '=':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default:
    		if(isalpha(ch) || (strlen(declkey) == 1)){ //if the entered value is character OR length of it is 1, which would mean '#'.
    			string s;
    			s += ch;
    			if(ch != declkey[0]){
                    while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                    cin.putback(ch);
    			}
    			if (s == declkey){
                    return Token(let);
    			}
    			else if(ch == '('){
                    return Token(func, s);
               }
               else if(s == declexit){
                    return Token(quit);
               }
    			else if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		else {error("Bad token");
    	}

	}

    return t;
}


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}
// Token_stream end ///////////////////////
Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

// Logically separate calculate() from the usual "boiler plate" of main
void calculate()
{
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try {

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
    define_name("k", 1000);

	calculate();

	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

//Functions mapping grammar rules //////////////////////////
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
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		default:
			error("primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
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
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
				/* //or you can use narrow cast check
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2 == 0) error ("%: Zero oszto");
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}
// Power and Square Root function
double funct(string s)
{
	Token t = ts.get();
	double d{};
	vector<double> func_args;
	if(t.kind != '('){
		error("'('expected, unknown function");
	} else{
		do{
			t = ts.get();
			if(t.kind == func){
				t.kind = number;
				//recursive function
				t.value = funct(t.name);
				ts.putback(t);
			}
			// check if there are empty arguments
			if(t.kind == ')'){
				break;
			} else{
				ts.putback(t);
			}
			func_args.push_back(expression());
			t = ts.get();
			if(t.kind == ')') break;
			if(t.kind != ',') error("',' expected");
		} while(t.kind == ',');
	}

	if(s == "sqrt"){
		if(func_args.size() != 1) error("sqrt() expects 1 argument");
		if(func_args[0] < 0) error("sqrt() expects positive base value");
		d = sqrt(func_args[0]);
	} else if(s == "pow"){
		if(func_args.size() != 2) error("pow() expects 2 arguments");
		d = func_args[0];
		auto x = func_args[0]; //base argument
		int p = narrow_cast<int>(func_args[1]); //power argument
		for(; p > 1; --p){ // decrease power argument by 1 and multiply base argument by itself each time for loop is true.
			d *= x;
		}
	} else{
        error("unknown function");
	}
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case let:
			return declaration();
        case func:
			return funct(t.name);
		default:
			ts.putback(t);
			return expression();
	}
}
