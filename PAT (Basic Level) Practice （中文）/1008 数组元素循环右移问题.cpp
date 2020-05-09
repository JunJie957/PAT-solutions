#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int n, m;
	int arr[101] = { 0 };

	cin >> n >> m;
	m %= n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	for (int i = n - m; i < n; ++i)
		if (n - m == 0 && i == n - 1) cout << arr[i];
		else cout << arr[i] << " ";

	for (int i = 0; i < n - m; ++i)
		if (i == n - m - 1) cout << arr[i];
		else cout << arr[i] << " ";
			
	return 0;
}
