 #include "../std_lib_facilities.h"

struct Date
{
	Date(int y, int m, int d);
	void add_day(int n);
	int year() { return y; }
	int month() { return m; }
	int day() { return d; }
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

Date::Date(int yy, int mm, int dd)
	 :y{yy}, m{mm}, d{dd}
{
	if (m <= 0 || m > 12) error("Incorrect date.");
	if (d <= 0 || d > 31) error("Incorrect date.");

	if (!is_longer_month() && d == 30) error("Incorrect date.");
	if (m == 2)
	{
		if (is_leap_year())
		{
			if (d >= 29) error("Incorrect date.");
		}
		else
		{
			if (d >= 28) error("Incorrect date.");
		}
	}
}

void Date::add_day(int n)
{
	bool check_month = false;

	if (is_longer_month() && d == 31)
	{
		m++;
		d = 1;
		check_month = true;
	}
	else if (!is_longer_month() && d == 30)
	{
		m++;
		d = 1;
		check_month = true;
	}
	else if (m == 2)
	{
		if (is_leap_year())
		{
			if (d == 29)
			{
				m++;
				d = 1;
				check_month = true;
			}
		}
		else
		{
			if (d == 28) 
			{
				m++;
				d = 1;
				check_month = true;
			}
		}
	}
	else
		d += n;

	if (check_month && m == 13)
	{
		m = 1;
		y++;
	}
}

ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.y
			  << ',' << d.m
			  << ',' << d.d << ')';
}

int main()
{
	Date today = Date(1978, 6, 25);

	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << tomorrow << '\n';

	return 0;
}