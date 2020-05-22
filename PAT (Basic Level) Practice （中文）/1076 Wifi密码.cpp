#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	getchar();

	int loc;
	string tmp;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, tmp);
		loc = tmp.find("T");
		switch (tmp[loc - 2])
		{
		case 'A':
			printf("1"); break;
		case 'B':
			printf("2"); break;
		case 'C':
			printf("3"); break;
		case 'D':
			printf("4"); break;
		}
	}
	return 0;
}
