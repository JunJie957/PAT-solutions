#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
using namespace std;

// 0-9 --> 10
// A-Z --> 11-36
// a-z --> 37-62
vector<int> v(63, 0);

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	// 将所有珠子计入数组中
	for (int i = 0; i < s1.size(); ++i)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z') v[s1[i] - 'A' + 10]++;
		else if (s1[i] >= 'a' && s1[i] <= 'z') v[s1[i] - 'a' + 36]++;
		else v[s1[i] - '0']++;
	}

	// 珠子总数减去需要的珠子数量，如果珠子不存在，则会被减为负数
	for (int i = 0; i < s2.size(); ++i)
	{
		if (s2[i] >= 'A' && s2[i] <= 'Z') v[s2[i] - 'A' + 10]--;
		else if (s2[i] >= 'a' && s2[i] <= 'z') v[s2[i] - 'a' + 36]--;
		else v[s2[i] - '0']--;
	}

	int surplus = 0;	
	int not_found = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] < 0) not_found += abs(v[i]);
		else if (v[i] > 0) surplus += v[i];
	}

	if (not_found) cout << "No " << not_found;
	else cout << "Yes " << surplus;
	
	return 0;
}
