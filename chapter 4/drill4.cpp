#include "../std_lib_facilities.h"

bool vector_contains(vector<string> vec, string str);

int main()
{
	string unit = "";
	double min = 0.0, max = 0.0;
	double value = 0.0;
	double value_sum = 0.0;
	int value_amount = 0;
	vector<string> legal_units = {
		"cm", "m", "in", "ft"
	};
	vector<double> entered_values;

	while (cin >> value >> unit)
	{
		if (vector_contains(legal_units, unit) && unit != "")
		{
			min = (value > min ? min : value);
			max = (value < max ? max : value);
			value_amount++;

			double converted = 0.0;
			if (unit == "cm")
				converted += value * 0.01;
			else if (unit == "in")
				converted += value * 0.0254;
			else if (unit == "ft")
				converted += value * 0.3048;
			else
				converted += value;

			value_sum += converted;
			entered_values.push_back(converted);

			cout << "entered value: "
				 << value
				 << "\n";

			if (value == min)
				cout << "the smallest so far.\n";
			else if (value == max)
				cout << "the largest so far.\n";

			cout << "smallest: "
				 << min
				 << "\nlargest: "
				 << max
				 << "\nnumber of values: "
				 << value_amount
				 << "\nsum of values (in meters): "
				 << value_sum
				 << "\n";

		}
		else
			cout << "illegal unit!\n";
		
		cout << "|----------------------\n";
	}

	sort(entered_values);
	cout << "Every value entered (in ascending order):\n";
	for (double value : entered_values)
		cout << value << " m, ";
	if (entered_values.size() >= 2)
	{
		int ev_last = entered_values.size() - 1;
		cout << "\nSmallest value: " << entered_values[0] << " m"
		     << "\nLargest value: " << entered_values[ev_last] << " m\n";
	}

	cout << "\n";
	keep_window_open();
	return 0;
}

bool vector_contains(vector<string> vec, string str)
{
	for (string vec_str : vec)
		if (vec_str == str)
			return true;

	return false;
}
