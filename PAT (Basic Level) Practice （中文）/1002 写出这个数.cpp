#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string spell[10] = {
		"ling","yi", "er", "san",
		"si","wu","liu","qi","ba",
		"jiu"
};

int main()
{
	string number;
	cin >> number;

	int sum = 0;
	for (unsigned int i = 0; i < number.size(); ++i)
		sum += (number[i] - '0');

	string tmp = to_string(sum);
	for (unsigned int i = 0; i < tmp.size() - 1; ++i)
		cout << spell[tmp[i] - '0'] << " ";

	cout << spell[tmp[tmp.size() - 1] - '0'];

	return EXIT_SUCCESS;
}
