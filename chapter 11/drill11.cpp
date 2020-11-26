#include "../std_lib_facilities.h"

struct Info
{
	string first_name, last_name;
	string phone_number;
	string email_address;
};

ostream& operator<<(ostream& os, Info info)
{
	ostringstream full_name;
	full_name << info.first_name << ' ' << info.last_name;
	return os << left
			  << setw(20) << full_name.str()
			  << setw(15) << info.phone_number
			  << setw(27) << info.email_address;
}

ostream& operator<<(ostream& os, vector<Info> info_vec)
{
	for (Info info : info_vec) os << info << '\n';
	return os;
}

void cout_int_forms(int& value, bool show_base = false)
{
	if (show_base) cout << showbase;
	cout << left << setfill(' ')
		 << setw(5) << "dec" << value << '\n'
		 << setw(5) << "hex" << hex << value << '\n'
		 << setw(5) << "oct" << oct << value << '\n'
		 << dec;
	if (show_base) cout << noshowbase;
}

void cout_float_forms(float& value)
{
	cout << left << setfill(' ')
		 << setw(12) << "default" << defaultfloat << value << '\n'
		 << setw(12) << "fixed" << fixed << value << '\n'
		 << setw(12) << "scientific" << scientific << value << '\n'
		 << defaultfloat;
}

int main()
{
	int birth_year = 1999;

	cout << "Birth year:\n";
	cout_int_forms(birth_year);

	cout << "\nMy age: " << dec << (2020 - birth_year) << '\n';

	cout << "\nBirth year (with base):\n";
	cout_int_forms(birth_year, true);

	int a, b, c, d;
	cout << "\nInput four numbers:\n";
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << '\n' << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	float given_float = 1234567.89;

	cout << "\nFloat forms:\n";
	cout_float_forms(given_float);

	vector<Info> info_tests {
		{"Pistai", "Gergo", "06708445176", "myemail@gmail.com"},
		{"Kovacs", "Balazs", "06704584166", "kovacsbalazs@freemail.hu"},
		{"Nagy", "Ferenc", "06704658456", "feri.nagy@gmail.com"},
		{"Nagy", "Bence", "06305469877", "bence-nagy@gmail.com"},
		{"Zakarias", "Kristof", "06309552144", "z.kris@citromail.hu"},
		{"Molnar", "Kristof", "06704112399", "molkri@gmail.com"}
	};
	cout << '\n' << left
		 << setw(20) << "Full name"
		 << setw(15) << "Phone number"
		 << setw(27) << "E-mail address"
		 << '\n' << info_tests << '\n';

	keep_window_open();
	return 0;
}