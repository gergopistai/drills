#include "../std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; i++) os << a[i] << '\n';
	return os;
}

ostream& print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++) os << a[i] << '\n';
	return os;
}

ostream& print_vector(ostream& os, vector<int> v)
{
	for (int i : v) os << i << '\n';
	return os;
}

int main()
{
	// Part I.
	int* ten = new int[10];
	for (int i = 0; i < 10; i++) cout << ten[i] << '\n';
	delete[] ten;

	cout << '\n';
	int* ten5 = new int[10] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	print_array10(cout, ten5);
	delete[] ten5;

	cout << '\n';
	int* eleven = new int[11] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	for (int i = 0; i < 11; i++) cout << eleven[i] << '\n';
	delete[] eleven;

	cout << '\n';
	int* twenty = new int[20];
	for (int i = 0; i < 20; i++) twenty[i] = (100 + i);
	print_array(cout, twenty, 20);
	delete[] twenty;
	
	cout << '\n';
	vector<int> ten_v = vector<int>(10);
	for (int i = 0; i < 10; i++) ten_v[i] = (100 + i);
	print_vector(cout, ten_v);

	cout << '\n';
	vector<int> eleven_v = vector<int>(11);
	for (int i = 0; i < 11; i++) eleven_v[i] = (100 + i);
	print_vector(cout, eleven_v);

	cout << '\n';
	vector<int> twenty_v = vector<int>(20);
	for (int i = 0; i < 20; i++) twenty_v[i] = (100 + i);
	print_vector(cout, twenty_v);
	cout << '\n';

	// Part II.
	int* p1 = new int{7};
	cout << left
	 	 << setw(14) << "p1:" << p1 << '\n'
		 << setw(14) << "p1's value:" << *p1 << "\n\n";

	int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};
	cout << left << setw(14) << "p2:" <<  p2 << '\n'
		 << "p2's values:\n";
	for (int i = 0; i < 7; i++) cout << p2[i] << '\n';

	int* p3 = p2;

	p2 = p1;
	p2 = p3;
	cout << left << '\n'
	 	 << setw(14) << "p1:" << p1 << '\n'
		 << setw(14) << "p1's value:" << *p1 << "\n\n";
	cout << left << setw(14) << "p2:" <<  p2 << '\n'
		 << "p2's values:\n";
	for (int i = 0; i < 7; i++) cout << p2[i] << '\n';

	delete[] p1;
	delete[] p2;

	p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	p2 = new int[10];

	for (int i = 0; i < 10; i++) p2[i] = p1[i];

	delete[] p1;
	delete[] p2;

	vector<int> p1_v {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	vector<int> p2_v = vector<int>(10);

	for (int i = 0; i < 10; i++) p2_v[i] = p1_v[i];

	keep_window_open();
	return 0;
}