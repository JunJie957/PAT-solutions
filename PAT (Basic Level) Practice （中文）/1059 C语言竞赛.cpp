#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0) return false;
	return true;
}


int main()
{
	int n;
	cin >> n;

	char id[5];
	string prize;
	unordered_map<string, string> p;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", id);
		if (i == 0)
			prize = "Mystery Award";
		else if (isPrime(i + 1))
			prize = "Minion";
		else
			prize = "Chocolate";

		p.insert(pair<string,string>(id, prize));
	}
	
	int k;
	cin >> k;

	unordered_map<string, string>::iterator iter;
	unordered_map<string, bool> check;
	for (int i = 0; i < k; ++i)
	{
		scanf("%s", id);
		iter = p.find(id);

		if (check.find(id) != check.end() && iter != p.end())
		{
			printf("%s: Checked\n", id);
			continue;
		}
		else
		{
			check.insert(pair<string, bool>(id, true));
		}
		
		if (iter != p.end())
			printf("%s: %s\n", id, iter->second.c_str());
		else
			printf("%s: Are you kidding?\n", id);
	}

	return 0;
}

