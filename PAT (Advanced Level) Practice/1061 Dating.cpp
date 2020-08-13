#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const char* week[] = {
	"MON", 
	"TUE", 
	"WED", 
	"THU", 
	"FRI", 
	"SAT",
	"SUN"
};

int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;

	bool first = false;
	int size_1 = a.size(), size_2 = b.size();
	for (int i = 0; i < size_1 && i < size_2; ++i)
	{
		if (a[i] == b[i])
		{
			if (!first) { // ���صģ����ڵķ�Χ�� 0-7 ֮�䣬��˴�д��ĸƥ��ķ�Χ��A-G֮��
				if (a[i] >= 'A' && a[i] <= 'G') {	
					printf("%s ", week[a[i] - 'A']);
					first = true; 
				}
			}
			else {	// ������ĸ�����֣������ַ���Ҫ���˵�
				if (a[i] >= '0' && a[i] <= '9') { 
					printf("%02d:", a[i] - '0');
					break;
				}
				else if (a[i] >= 'A' && a[i] <= 'N') {
					printf("%02d:", a[i] - 'A' + 10);
					break;
				}
			}
		}
	}

	size_1 = c.size();
	size_2 = d.size();
	for (int j = 0; j < size_1 && j < size_2; ++j) { // ���������ַ�������Ҫ��ͬ��Ӣ���ַ������Ҫ���������ַ�
		if (((c[j] >= 'a' && c[j] <= 'z') || (c[j] >='A' &&c[j]<='Z')) && c[j] == d[j]) {
			printf("%02d", j);
		}
	}
	return 0;
}

