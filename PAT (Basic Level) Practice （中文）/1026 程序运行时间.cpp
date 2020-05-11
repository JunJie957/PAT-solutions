#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long c1;
	long long c2;
	
	cin >> c1 >> c2;
	double res = (c2 - c1) * 0.01;

	int hour = res / 3600;
	int minute = ((int)res % 3600) / 60;
	int second = round(res - (int)(res / 60) * 60);	// ËÄÉáÎåÈë

	if (hour == 0) cout << "00:";
	else if (hour > 10) cout << hour << ":";
	else cout << "0" << hour << ":";
		
	if (minute == 0) 	cout << "00:";
	else if (minute > 10) cout << minute << ":";
	else cout << "0" << minute << ":";
		
	if (second == 0) cout << "00";
	else if (second > 10) cout << second;
	else cout << "0" << second;
	
	return 0;
}
