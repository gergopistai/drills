#include "../std_lib_facilities.h"

int main()
{
	string first_name = "", friend_name = "";
	char friend_sex = '0';
	int recipient_age = 0;

	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;
	cout << "Dear "
		 << first_name
		 << ",\n\tHow are you? I am fine. I miss you."
		 << "I'm hoping you are having a good time.\n";

	cout << "Enter the name of another friend: ";
	cin >> friend_name;
	cout << "\tHave you seen "
		 << friend_name
		 << " lately?\n";

	cout << "Enter the sex of "
		 << friend_name
		 << " (m/f): ";
	cin >> friend_sex;
	cout << "\tIf you see "
		 << friend_name
		 << " please ask "
		 << (friend_sex == 'm' ? "him" : "her")
		 << " to call me.\n";

	cout << "Enter the recipient's age: ";
	cin >> recipient_age;

	if (recipient_age <= 0 || recipient_age >= 110)
		simple_error("you're kidding!");

	cout << "\tI heard you had a birthday and you are "
		 << recipient_age
		 << " years old.\n";

	if (recipient_age < 12)
		cout << "\tNext year you will be "
			 << ++recipient_age
			 << ".\n";
	else if (recipient_age == 17)
		cout << "\tNext year you will be able to vote.\n";
	else if (recipient_age > 70)
		cout << "\tI hope you are enjoying retirement.\n";

	cout << "Yours sincerely,\n\n"
		 << "gergopistai\n";

	keep_window_open();
	return 0;
}
