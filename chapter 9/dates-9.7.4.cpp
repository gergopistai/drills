 #include "../std_lib_facilities.h"

enum class Month{
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
};

Month operator++(Month& m)
{
	m = static_cast<Month>(static_cast<int>(m) + 1);
	return m;
}

class Date
{
public:
	Date(int y, Month m, int d);
	void add_day(int n);
	int year() const { return y; }
	Month month() const { return m; }
	int day() const { return d; }
private:
	int y, d;
	Month m;
	bool is_longer_month()
	{
		switch (m)
		{
			case Month::Jan:
			case Month::Mar:
			case Month::May:
			case Month::Jul:
			case Month::Aug:
			case Month::Oct:
			case Month::Dec:
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

Date::Date(int yy, Month mm, int dd)
	 :y{yy}, m{mm}, d{dd}
{
	if (d <= 0 || d > 31) error("Incorrect date.");

	if (!is_longer_month() && d == 30) error("Incorrect date.");
	if (m == Month::Feb)
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
	if (is_longer_month() && d == 31)
	{
		++m;
		d = 1;
		if (month() == Month::Dec)
		{
			y++;
			m = Month::Jan;
		}
	}
	else if (!is_longer_month() && d == 30)
	{
		++m;
		d = 1;
		if (month() == Month::Dec)
		{
			y++;
			m = Month::Jan;
		}
	}
	else if (m == Month::Feb)
	{
		if (is_leap_year())
		{
			if (d == 29)
			{
				++m;
				d = 1;
				if (month() == Month::Dec)
				{
					y++;
					m = Month::Jan;
				}
			}
		}
		else
		{
			if (d == 28) 
			{
				++m;
				d = 1;
				if (month() == Month::Dec)
				{
					y++;
					m = Month::Jan;
				}
			}
		}
	}
	else d += n;
}

ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.year()
			  << ',' << static_cast<int>(d.month())
			  << ',' << d.day() << ')';
}

int main()
{
	Date today = Date(1978, Month::Jun, 25);

	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << tomorrow << '\n';

	return 0;
}