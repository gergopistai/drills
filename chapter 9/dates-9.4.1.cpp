#include "../std_lib_facilities.h"

const bool test_mode = false;
/*
bool get_input_date(Date& date)
{
	int y, m, d;
	cin >> y;
	cin >> m;
	cin >> d;
	if (cin.fail()) return false;

	init_date(date, y, m, d);
	return true;
} */

void throw_incorrect_error();

struct Date
{
	int y, m, d;
	bool is_longer_month()
	{
		switch (m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				return true;
				break;
			default:
				return false;
		}
	}
	bool is_leap_year()
	{
		if ((y % 100 == 0) &&
			(y % 400 == 0) &&
			(y % 4 == 0)) return true;
		else if (y % 4) return true;
		return false;
	}
};

void init_date(Date& dd, int y, int m, int d)
{
	if (m <= 0 || m > 12) throw_incorrect_error();
	if (d <= 0 || d > 31) throw_incorrect_error();

	if (!dd.is_longer_month() && dd.d == 30) throw_incorrect_error();
	if (dd.m == 2)
	{
		if (dd.is_leap_year())
		{
			if (dd.d >= 29) throw_incorrect_error();
		}
		else
		{
			if (dd.d >= 28) throw_incorrect_error();
		}
	}

	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void throw_incorrect_error()
{
	if (test_mode) cerr << "Incorrect date." << '\n';
	else error("Incorrect date.");
}

void add_day(Date& dd, int n)
{
	bool check_month = false;

	if (dd.is_longer_month() && dd.d == 31)
	{
		dd.m++;
		dd.d = 1;
		check_month = true;
	}
	else if (!dd.is_longer_month() && dd.d == 30)
	{
		dd.m++;
		dd.d = 1;
		check_month = true;
	}
	else if (dd.m == 2)
	{
		if (dd.is_leap_year())
		{
			if (dd.d == 29)
			{
				dd.m++;
				dd.d = 1;
				check_month = true;
			}
		}
		else
		{
			if (dd.d == 28) 
			{
				dd.m++;
				dd.d = 1;
				check_month = true;
			}
		}
	}
	else
		dd.d += n;

	if (check_month && dd.m == 13)
	{
		dd.m = 1;
		dd.y++;
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y
			  << ',' << d.m
			  << ',' << d.d << ')';
}

int main()
{
	Date today;
	init_date(today, 1978, 6, 25);

	Date tomorrow = today;
	add_day(tomorrow, 1);

	cout << tomorrow << '\n';
	
	return 0;
}