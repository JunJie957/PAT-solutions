#include <iostream>
using namespace std;

struct judge
{
	bool is_num;
	bool is_not_key;
};

int main()
{
	int k;
	cin >> k;

	judge arr[101];
	for (int i = 0; i <= 100; ++i)
	{
		arr[i].is_num = false;
		arr[i].is_not_key = false;
	}

	int num;
	for (int i = 0; i < k; ++i)
	{
		cin >> num;
		arr[num].is_num = true;
	}

	int tmp;
	for (int i = 2; i < 101; ++i)
	{
		tmp = i;
		if (arr[tmp].is_num == true && arr[tmp].is_not_key == false)
		{
			while (tmp != 1)
			{
				if (tmp % 2 == 0) tmp /= 2;
				else if (tmp % 2 != 0) tmp = (tmp * 3 + 1) / 2;
				if(arr[tmp].is_num == true && tmp <= 100) arr[tmp].is_not_key = true;
			}
		}
	}
	
	bool first = false;
	for (int i = 100; i > 1; --i)
	{
		if (arr[i].is_num == true && arr[i].is_not_key == false)
		{
			if (first == false)
			{
				first = true;
				cout << i;
			}
			else
			{
				cout << " " << i;
			} 
		}
	}
	return 0;
}
