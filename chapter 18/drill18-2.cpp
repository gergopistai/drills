#include "../std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> vec)
{
	vector<int> lv(sizeof(vec));
	lv = gv;

	cout << "lv:\n";
	for (int i : lv) cout << i << '\n';

	vector<int> lv2 = vec;

	cout << "vec:\n";
	for (int i : vec) cout << i << '\n';
}

int main()
{
	f(gv);
	vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(vv);

	return 0;
}
