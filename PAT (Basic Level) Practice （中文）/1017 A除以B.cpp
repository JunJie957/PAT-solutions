#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int b;
	cin >> s >> b;
	
	int q = (s[0] - '0') / b;	// ษฬ
	int r = (s[0] - '0') % b;	// ำเสý

	if ((q != 0 && s.size() > 1) || s.size() == 1) cout << q;

	for (int i = 1; i < s.size(); ++i)
	{
		r = r * 10;

		q = ((s[i] - '0') + r) / b;
		r  = ((s[i] - '0') + r) % b;

		cout << q;
	}
	cout << " " << r;

	return 0;
}
