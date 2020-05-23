#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int dif;
	map<int, int, greater<int>> m;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &dif);
		dif = abs(i - dif);

		auto iter = m.find(dif);
		if (iter != m.end()) iter->second++;
		else m.insert(pair<int, int>(dif, 1));
	}
	
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		if (iter->second != 1)
			printf("%d %d\n", iter->first, iter->second);
	}
	return 0;
}
