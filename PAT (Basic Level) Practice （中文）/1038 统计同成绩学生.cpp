#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 将scanf()和printf()替换为cin和cout，会发现有超时错误
// 因此，在算法题目中尽量使用scanf()和printf()，尤其是需要多次输入输出的时候

int arr[10000] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);

	int score;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &score);
		arr[score]++;
	}

	int look;
	scanf("%d", &look);
	for (int i = 0; i < look; ++i)
	{
		//cin >> score;  // 使用cin时，提交答案会出现超时错误，可以打开试一下
		scanf("%d", &score);
		if (i != look - 1) printf("%d ", arr[score]);
		else  printf("%d", arr[score]);
	}

	return 0;
}
