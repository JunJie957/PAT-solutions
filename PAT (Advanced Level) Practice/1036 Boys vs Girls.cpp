#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct stu {
	string name;
	string sex;
	string ID;
	int grade;
	stu() :grade(-1) {};
};

int main()
{
	int n;
	scanf("%d", &n);

	int female_max_grade = -1, male_lowst_grade = 101;
	stu tmp, boy, girl;
	for (int i = 0; i < n; ++i) {
		cin >> tmp.name >> tmp.sex >> tmp.ID >> tmp.grade;
		if (tmp.sex.compare("F") == 0 && female_max_grade < tmp.grade) {
			girl = tmp;
			female_max_grade = tmp.grade;
		}
		else if (tmp.sex.compare("M") == 0 && male_lowst_grade > tmp.grade) {
			boy = tmp;
			male_lowst_grade = tmp.grade;
		}
	}

	if (girl.grade == -1) {
		printf("Absent\n");
	}
	else {
		printf("%s %s\n", girl.name.c_str(), girl.ID.c_str());
	}
	
	if (boy.grade == -1) {
		printf("Absent\n");
	}
	else {
		printf("%s %s\n", boy.name.c_str(), boy.ID.c_str());
	}

	if (boy.grade == -1 || girl.grade == -1) {
		printf("NA");
	}
	else {
		printf("%d", abs(boy.grade - girl.grade));
	}

	return 0;
}

