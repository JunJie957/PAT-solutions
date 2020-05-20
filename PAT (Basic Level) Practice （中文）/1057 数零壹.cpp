#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int sum = 0;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			sum += (str[i] - 'a' + 1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			sum += (str[i] - 'A' + 1);
	}

	int count_one = 0, count_zero = 0;
	while (sum != 0)
	{
		if (sum % 2 == 0) count_zero++;
		else count_one++;
		sum /= 2;
	}

	cout << count_zero << " " << count_one;

	return 0;
}

