#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct student
{
	int id;
	int a;
	int c;
	int m;
	int e;

	int rank_a;
	int rank_c;
	int rank_m;
	int rank_e;

	int best_rank;
	char best_project;

};

struct myCmp
{
	bool operator()(student v1, student v2)
	{//A > C > M > E.
		return v1.a > v2.a;
	}
};

struct myCmp2
{
	bool operator()(student v1, student v2)
	{//A > C > M > E.
		return v1.c > v2.c;
	}
};

struct myCmp3
{
	bool operator()(student v1, student v2)
	{//A > C > M > E.
		return v1.m > v2.m;
	}
};

struct myCmp4
{
	bool operator()(student v1, student v2)
	{//A > C > M > E.
		return v1.e > v2.e;
	}
};

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	// 输入 n 个学生的信息
	struct student s;
	vector<student> um;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d", &s.id, &s.c, &s.m, &s.e);
		s.a = (s.c + s.m + s.e) / 3 + 0.5;
		s.best_rank = -1;
		um.push_back(s);
	}

	// 对每一科进行排序，并找到最好的一科和其排名
	sort(um.begin(), um.end(), myCmp()); // a
	um[0].rank_a = 1;
	for (int i = 1; i < n; ++i)
	{ // 成绩相同，排名是并列的
		if (um[i].a == um[i - 1].a) um[i].rank_a = um[i - 1].rank_a;
		else um[i].rank_a = i + 1;
	}

	sort(um.begin(), um.end(), myCmp2()); // c
	um[0].rank_c = 1;
	for (int i = 1; i < n; ++i)
	{// 成绩相同，排名是并列的
		if (um[i].c == um[i - 1].c)	um[i].rank_c = um[i - 1].rank_c;
		else um[i].rank_c = i + 1;
	}

	sort(um.begin(), um.end(), myCmp3()); // m
	um[0].rank_m = 1;
	for (int i = 1; i < n; ++i)
	{ // 成绩相同，排名是并列的
		if (um[i].m == um[i - 1].m) um[i].rank_m = um[i - 1].rank_m;
		else um[i].rank_m = i + 1;
	}


	sort(um.begin(), um.end(), myCmp4()); // e
	um[0].rank_e = 1;
	for (int i = 1; i < n; ++i)
	{ // 成绩相同，排名是并列的
		if (um[i].e == um[i - 1].e) um[i].rank_e = um[i - 1].rank_e;
		else um[i].rank_e = i + 1;
	}

	// best
	unordered_map<int, student> um2;
	for (int i = 0; i < n; ++i)
	{
		//A > C > M > E.
		if (um[i].rank_a <= um[i].rank_c && um[i].rank_a <= um[i].rank_m && um[i].rank_a <= um[i].rank_e)
		{
			um[i].best_rank = um[i].rank_a;
			um[i].best_project = 'A';
		}
		else if (um[i].rank_c <= um[i].rank_m && um[i].rank_c <= um[i].rank_e)
		{
			um[i].best_rank = um[i].rank_c;
			um[i].best_project = 'C';
		}
		else if (um[i].rank_m <= um[i].rank_e)
		{
			um[i].best_rank = um[i].rank_m;
			um[i].best_project = 'M';
		}
		else
		{
			um[i].best_rank = um[i].rank_e;
			um[i].best_project = 'E';
		}

		um2.insert(make_pair(um[i].id, um[i]));
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &s.id);
		auto iter = um2.find(s.id);
		if (iter != um2.end())
		{
			if (i != m - 1) printf("%d %c\n", iter->second.best_rank, iter->second.best_project);
			else printf("%d %c", iter->second.best_rank, iter->second.best_project);
		}
		else
		{
			if (i != m - 1) printf("N/A\n");
			else printf("N/A");
		}
	}
	return 0;
}
