#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MultipleChoice
{
	int value;
	int choose_num;
	int right_choose_num;
	char right_choose[5];
};

int main()
{
	int n, m;
	cin >> n >> m;

	MultipleChoice temp;
	vector<MultipleChoice> v;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp.value >> temp.choose_num >> temp.right_choose_num;
		for (int j = 0; j < temp.right_choose_num; ++j)
			cin >> temp.right_choose[j];

		getchar(); // Ïû³ý¶àÓà»»ÐÐ·û

		v.push_back(temp);
	}
	
	vector<int> res(n,0);
	vector<int> error_num(m, 0);
	string str;
	for (int i = 0; i < n; ++i)
	{
		int number = -1;
		int error_flag = false;
		int choose_num = 0;
		int score = 0;
		
		getline(cin, str);
		
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')continue;
			else if (str[i] == '(')
			{
				number++;
			}
			else if (str[i] >= '0' && str[i] <= '5')
			{
				if (str[i] - '0' != v[number].right_choose_num)
				{
					error_flag = true;
					error_num[number]++;
				}
			}
			else if ((str[i] >= 'a' && str[i] <= 'e') && !error_flag)
			{
				if (str[i] != v[number].right_choose[choose_num])
				{
					error_flag = true;
					error_num[number]++;
				}
				choose_num++;
			}
			else if (str[i] == ')')
			{
				if (!error_flag)
				{
					score += v[number].value;
				}
				choose_num = 0;
				error_flag = false;
			}
		}
		res[i] = score;
	}

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	int max = 0;
	int loc = -1;
	for (int i = 0; i < error_num.size(); ++i)
	{
		if (error_num[i] > max)
		{
			max = error_num[i];
			loc = i;
		}
	}

	if (max == 0) cout << "Too simple";
	else
	{
		cout << max;
		for (int i = 0; i < error_num.size(); ++i)
		{
			if (error_num[i] == max) cout << " " << i + 1;
		}
	}
	return 0;
}

