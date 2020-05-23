#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();

	string password;
	for (int i = 0; i < n; ++i)
	{
		bool letter = false;
		bool digit = false;
		bool other_error = false;
		getline(cin, password);
		for (int j = 0; j < password.size(); ++j)
		{
			if (password.size() < 6)
			{
				other_error = true;
				cout << "Your password is tai duan le." << endl;
				break;
			}
			
			if (isalpha(password[j])) letter = true;
			else if (isdigit(password[j])) digit = true;
 			else if (password[j] != '.')
			{
				other_error = true;
				cout << "Your password is tai luan le." << endl;
				break;
			}
		}

		if (!other_error)
		{
			if (!digit && letter) cout << "Your password needs shu zi." << endl;
			else if (!letter && digit) cout << "Your password needs zi mu." << endl;
			else  cout << "Your password is wan mei." << endl;
		}
	}
	return 0;
}
