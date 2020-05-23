#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string ToLowerAlp(string s)
{
	for (int i = 0; i < s.size(); ++i)
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	return s;
}
struct StuInfo
{
	string number;
	int score;
	string school;
};

struct SchoolInfo
{
	int sum;
	string name;
	int stu_number;

	bool operator<(const SchoolInfo& s)const
	{
		if (this->sum != s.sum)
			return this->sum > s.sum;
		else if (this->stu_number != s.stu_number)
			return this->stu_number < s.stu_number;
		else 
			return this->name < s.name;
	}
};

int main()
{
	int n;
	cin >> n;
	
	map<string, vector<StuInfo>> m;
	StuInfo tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp.number >> tmp.score >> tmp.school;
		tmp.school = ToLowerAlp(tmp.school);
		auto iter = m.find(tmp.school);
		if (iter != m.end())
		{
			iter->second.push_back(tmp);
		}
		else
		{
			vector<StuInfo> v;
			v.push_back(tmp);
			m.insert(pair<string, vector<StuInfo>>(tmp.school, v));
		}
	}
	printf("%d\n", m.size());// 学校个数

	set<SchoolInfo> s; // 计算每个学校的成绩
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		SchoolInfo tmp;
		int b_score = 0, a_score = 0, t_score = 0;
		for (int i = 0; i < iter->second.size(); ++i)
		{
			if (iter->second[i].number[0] == 'B')
				b_score += iter->second[i].score; // 乙级
			else if (iter->second[i].number[0] == 'A')
				a_score += iter->second[i].score; // 甲级
			else if (iter->second[i].number[0] == 'T')
				t_score += iter->second[i].score; // 顶级
		}
		//乙级总分/1.5 + 甲级总分 + 顶级总分*1.5
		tmp.name = iter->first;
		tmp.stu_number = iter->second.size();
		tmp.sum = b_score / 1.5 + a_score + t_score * 1.5;
		s.insert(tmp);
	}

	int count = 1;
	int old_rank = count;
	int old_sum = s.begin()->sum;
	for (auto iter = s.begin(); iter != s.end(); ++iter)
	{
		if (iter->sum == old_sum) printf("%d ", old_rank);
		else if (iter->sum != old_sum)
		{
			printf("%d ", count);

			old_rank = count;
			old_sum = iter->sum;
		}
		printf("%s %d %d", iter->name.c_str(), iter->sum, iter->stu_number);

		++count;
		if (iter != --s.end()) printf("\n");
	}
	return 0;
}
