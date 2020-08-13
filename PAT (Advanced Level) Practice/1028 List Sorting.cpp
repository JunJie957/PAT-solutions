#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct stu {
	char id[7];		// a 6-digit number
	char name[9];	// a string with no more than 8 characters without space
	int grade;		// an integer between 0 and 100, inclusive
};

bool cmp(const stu& s1, const stu& s2) {
	if (strcmp(s1.id, s2.id) <= 0) return true;
	else return false;
}

bool cmp2(const stu& s1, const stu& s2) {
	if (strcmp(s1.name, s2.name) < 0) return true;
	else if(strcmp(s1.name, s2.name) > 0) return false;
	else if (strcmp(s1.id, s2.id) <= 0) return true;
	else return false;
}

bool cmp3(const stu& s1, const stu& s2) {
	if (s1.grade != s2.grade) return s1.grade < s2.grade;
	else if (strcmp(s1.id, s2.id) <= 0)  return true;
	else return false;
}

int main()
{
	int n, c;
	stu tmp;
	vector<stu> v;
	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; ++i) {
		scanf("%s %s %d", tmp.id, tmp.name, &tmp.grade);
		v.push_back(tmp);
	}

	if (c == 1) sort(v.begin(), v.end(), cmp);
	else if (c == 2) sort(v.begin(), v.end(), cmp2);
	else sort(v.begin(), v.end(), cmp3);

	for (const auto i : v) {
		printf("%s %s %d\n", i.id, i.name, i.grade);
	}

	return 0;
}

