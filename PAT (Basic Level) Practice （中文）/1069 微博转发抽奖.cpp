#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	int m, n, s;
	scanf("%d %d %d", &m, &n, &s);

	string tmp;
	int count = 0;
	bool next = false;
	unordered_set<string> us;
	for (int i = 1; i <= m; ++i)
	{
		cin >> tmp;
		
		if (us.find(tmp) != us.end())
		{
			s++;
			continue;
		}
		else if (i == s && us.find(tmp) == us.end())
		{
			printf("%s\n", tmp.c_str());
			us.insert(tmp);
			s += n;
			count++;
		}
	}
	if (count == 0) printf("Keep going...");
	return 0;
}
