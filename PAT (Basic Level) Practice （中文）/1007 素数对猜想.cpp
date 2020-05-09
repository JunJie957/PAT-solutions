#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int val)
{
	for (int i = 2; i * i <= val; ++i)
		if (val % i == 0) return false;
	return true;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 5; i <= n; ++i)
		if (isPrime(i - 2) && isPrime(i)) ++count;
	
	cout << count;
	return 0;
}
