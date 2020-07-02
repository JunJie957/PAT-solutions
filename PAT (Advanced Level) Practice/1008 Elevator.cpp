#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// up - 6s  stay - 5s down - 4s
int main()
{
	int n;
	scanf("%d", &n);
	
	int now = 0;
	int old = 0;
	int sum = 0; 
	for (int i = 0; i < n; ++i)	//¶ÁÈ¡Ä¿±êÂ¥²ã 
	{
		scanf("%d", &now);
		if (now >= old) 
			sum += (now - old) * 6 + 5;
		else 
			sum += (old - now) * 4 + 5;
		old = now;
	}
	printf("%d", sum);
	return 0;
}
