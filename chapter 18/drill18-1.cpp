#include "../std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int arr[], int len)
{
	int la[10];
	for (int i = 0; i < 10; i++) la[i] = ga[i];

	cout << "la:\n";
	for (int i = 0; i < 10; i++) cout << la[i] << '\n';

	int* p = new int[len];
	for (int i = 0; i < len; i++)
	{
		*p = arr[i];
		p++;
	}
	p -= len;

	cout << "heap:\n";
	for (int i = 0; i < len; i++)
	{
		cout << *p << '\n';
		p++;
	}
	p -= len;

	delete[] p;
}

int main()
{
	f(ga, 10);
	int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(aa, 10);

	return 0;
}
