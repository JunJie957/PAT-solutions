#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	int student_number;
	int morality_score;
	int talent_score;
};

bool student_cmp(student& a, student& b)
{
	if ((a.morality_score + a.talent_score) != (b.morality_score + b.talent_score))
		return (a.morality_score + a.talent_score) > (b.morality_score + b.talent_score);
	else if (a.morality_score != b.morality_score)
		return  a.morality_score > b.morality_score;
	else 
		return a.student_number < b.student_number;
}


int main()
{
	student s;
	int n, low, high;
	vector<student> v[4];
	
	cin >> n >> low >> high;
	int sum = n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &s.student_number, &s.morality_score, &s.talent_score);
	
		if (s.morality_score < low || s.talent_score < low)
			--sum;
		else if (s.morality_score >= high && s.talent_score >= high)
			v[0].push_back(s);			// 才德全尽
		else if (s.talent_score < high && s.morality_score >= high)
			v[1].push_back(s);			//  德胜才
		else if (s.talent_score < high && s.morality_score < high && s.morality_score >= s.talent_score)
			v[2].push_back(s);			//  才德兼亡 但 德胜才
		else
			v[3].push_back(s);		    //  其他到达最低线的考生
	}

	// 排序
	sort(v[0].begin(), v[0].end(), student_cmp);
	sort(v[1].begin(), v[1].end(), student_cmp);
	sort(v[2].begin(), v[2].end(), student_cmp);
	sort(v[3].begin(), v[3].end(), student_cmp);

	// 输出
	printf("%d\n", sum);
	for (int i = 0; i < v[0].size(); ++i)
		printf("%d %d %d\n", v[0][i].student_number, v[0][i].morality_score, v[0][i].talent_score);
	
	for (int i = 0; i < v[1].size(); ++i)
		printf("%d %d %d\n", v[1][i].student_number, v[1][i].morality_score, v[1][i].talent_score);
	
	for (int i = 0; i < v[2].size(); ++i)
		printf("%d %d %d\n", v[2][i].student_number, v[2][i].morality_score, v[2][i].talent_score);
	
	for (int i = 0; i < v[3].size(); ++i)
		printf("%d %d %d\n", v[3][i].student_number, v[3][i].morality_score, v[3][i].talent_score);

	return 0;
} 
