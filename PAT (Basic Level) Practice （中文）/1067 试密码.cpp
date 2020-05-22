#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, count = 1;
	string right_password;
	string try_password;

	cin >> right_password >> n;
	getchar();

	while (1)
	{
		getline(cin, try_password);

		if (try_password.compare(right_password) == 0)
		{
			printf("Welcome in");
			break;
		}
		else if (try_password.compare("#") == 0)
		{
			break;
		}
		else
		{
			printf("Wrong password: %s\n", try_password.c_str());
			++count;
		}

		if (count > n)
		{
			printf("Account locked");
			break;
		}
	}
	return 0;
}
