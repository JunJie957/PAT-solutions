#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	double win, tie, lose;
	vector<pair<double, int>> best;
	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf%lf", &win, &tie, &lose);
		if (win >= tie && win >= lose) best.push_back(make_pair(win, 0));
		else if (tie >= win && tie >= lose) best.push_back(make_pair(tie, 1)); 
		else if (lose >= win && lose >= tie) best.push_back(make_pair(lose, 2));
	}

	for (int i = 0; i < best.size(); ++i)
		best[i].second == 0 ? printf("W ") : best[i].second == 1 ? printf("T ") : printf("L ");

	printf("%.2f", (best[0].first * best[1].first * best[2].first * 0.65 - 1) * 2);
	return 0;
}
