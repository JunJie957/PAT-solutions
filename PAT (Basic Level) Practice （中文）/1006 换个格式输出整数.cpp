#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int num_B = n / 100;
	int num_S = n % 100 / 10;
	int num_N = n % 10;

	for (int i = 0; i < num_B; ++i)
		cout << "B";

	for (int i = 0; i < num_S; ++i)
		cout << "S";

	for (int i = 0; i < num_N; ++i)
		cout << i + 1;

	return 0;
}
