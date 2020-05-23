#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int key, value;
	unordered_map<int, vector<int>> um;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &key, &value);
		auto iter = um.find(key);
		if (iter != um.end())
		{
			iter->second.push_back(value);
		}
		else
		{
			vector<int> v;
			v.push_back(value);
			um.insert(pair<int, vector<int>>(key, v));
		}

		iter = um.find(value);
		if (iter != um.end())
		{
			iter->second.push_back(key);
		}
		else
		{
			vector<int> v;
			v.push_back(key);
			um.insert(pair<int, vector<int>>(value, v));
		}
	}

	int k;
	unordered_set<int> s;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &key);
			s.insert(key);
		}

		bool flag = true;
		for (auto iter = s.begin(); iter != s.end(); ++iter)
		{
			auto iter2 = um.find(*iter);
			if (iter2 != um.end())
			{
				for (int t = 0; t < iter2->second.size(); ++t)
				{
					auto iter3 = s.find(iter2->second[t]);
					if (iter3 != s.end())
					{
						flag = false;
						printf("No\n");
						break;
					}
				}
			}
			if (!flag) break;
		}
		if (flag) printf("Yes\n");
		s.clear();
	}
	return 0;
}
