#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<float> v(2001, 0);
int main()
{
	float b;
	int k, a;
	scanf("%d", &k);
	
	unordered_map<int, float> um;
	for (int i = 0; i < k; ++i) {	/* 输入 */
		scanf("%d%f", &a, &b);
		um[a] = b;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {	/* 乘法计算 */
		scanf("%d%f", &a, &b);
		for (auto& iter : um) 
			v[iter.first + a] += iter.second * b;
	}

	int count = 0;
	for (int i = 0; i <= 2000; ++i) /* 统计非零项的个数 */
		if (v[i] != 0) ++count;

	printf("%d", count);
	for (int i = 2000; i >= 0; --i) /* 按格式输出 */
		if (v[i] != 0) printf(" %d %.1f", i, v[i]);
	
	return 0;
}
