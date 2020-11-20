#include "../std_lib_facilities.h"

struct Info
{
	string first_name, last_name;
	string phone_number;
	string email_address;
};

ostream& operator<<(ostream& os, Info info)
{
	return os << left
			  << setw(15) << info.first_name << '\t'
			  << setw(15) << info.last_name << '\t'
			  << setw(11) << info.phone_number << '\t'
			  << setw(22) << info.email_address;
}

void cout_int_forms(int& value, bool show_base = false)
{
	if (show_base) cout << showbase;
	cout << setw(3) << "dec\t" << value << '\n'
		 << setw(3) << "hex\t" << hex << value << '\n'
		 << setw(3) << "oct\t" << oct << value << '\n' << dec;
	if (show_base) cout << noshowbase;
}

void cout_float_forms(float& value)
{
	cout << "default\t" << value << '\n'
		 << "fixed\t" << fixed << value << '\n'
		 << "scientific\t" << scientific << value << '\n';
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
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << '\n' << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	float given_float = 1234567.89;

	cout << "\nFloat forms:\n";
	cout_float_forms(given_float);

	Info test{"Pistai", "Gergő", "06708445176", "gergopistai@gmail.com"};
	cout << '\n' << test << '\n';

	keep_window_open();
	return 0;
}