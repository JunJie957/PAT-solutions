#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
	string registration_number;
	int total_score;
	int final_rank;
	int location_number;
	int local_rank;
};

bool cmp(stu a, stu b)
{
	if (a.total_score == b.total_score)
	{
		return a.registration_number < b.registration_number;
	}
	else
	{
		return a.total_score > b.total_score;
	}
}

void PATRank()
{
	int n; // test location
	scanf("%d", &n);

	int k; // testes
	stu s;	// temp stu object
	vector<stu> final;	// for final rank
	vector<stu> local;	// for local rank
	for (int i = 0; i < n; ++i)
	{
		local.clear();
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			cin >> s.registration_number;
			scanf("%d", &s.total_score);
			s.location_number = i + 1;
			local.push_back(s);
		}

		// local rank
		sort(local.begin(), local.end(), cmp);
		if (k)
		{
			local[0].local_rank = 1;
			final.push_back(local[0]);
		}

		for (int i = 1; i < k; ++i)
		{
			if (local[i].total_score == local[i - 1].total_score)
			{
				local[i].local_rank = local[i - 1].local_rank;
			}
			else
			{
				local[i].local_rank = i + 1;
			}
			final.push_back(local[i]);
		}
	}

	// final rank
	int total_number = final.size();
	sort(final.begin(), final.end(), cmp);
	if (total_number)
	{
		final[0].final_rank = 1;
	}

	for (int i = 1; i < total_number; ++i)
	{
		if (final[i].total_score == final[i - 1].total_score)
		{
			final[i].final_rank = final[i - 1].final_rank;
		}
		else
		{
			final[i].final_rank = i + 1;
		}
	}

	// display
	printf("%d\n", total_number);
	for (int i = 0; i < total_number; ++i)
	{
		printf("%s %d %d %d\n", final[i].registration_number.c_str(), final[i].final_rank, final[i].location_number, final[i].local_rank);
	}
}

int main()
{
	PATRank();
	return 0;
}