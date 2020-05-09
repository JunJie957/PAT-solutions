#include <iostream>
using namespace std;

int main()
{
	int n;
	int score;
	int max_score = -1;
	int min_score = 101;
	string name, number;
	string max_name, max_number, min_name, min_number;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> number >> score;

		if (score > max_score)
		{
			max_score = score;
			max_name = name;
			max_number = number;
		}

		if (score < min_score)
		{
			min_score = score;
			min_name = name;
			min_number = number;
		}
	}
	cout << max_name << " " << max_number << endl;
	cout << min_name << " " << min_number;
	
	return 0;
}
