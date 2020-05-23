#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	string res = to_string(a * b);
	reverse(res.begin(),res.end());
	printf("%d", atoi(res.c_str()));
	return 0;
}
