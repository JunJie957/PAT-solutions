#include <iostream>
using namespace std;

int main()
{
	string a, da, b, db;
	int count_a = 0, count_b = 0, sum = 0;
	
	cin >> a >> da >> b >> db;

	for (int i = 0; i < a.size(); ++i)
		if (a[i] == da[0]) count_a++;
			
	for (int i = 0; i < b.size(); ++i)
		if (b[i] == db[0]) count_b++;

	for (int i = 0; i < count_a - 1; ++i) da += da[0];
	for (int i = 0; i < count_b - 1; ++i) db += db[0];

	if (count_a != 0) sum += atoi(da.c_str());
	if (count_b != 0) sum += atoi(db.c_str());

	cout << sum;

	return 0;
}
