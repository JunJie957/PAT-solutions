#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int m, n, tol;
	cin >> m >> n >> tol;

	unordered_map<int, int> value;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &v[i][j]);
			value[v[i][j]]++;
		}
	}

	int x, y, val, res_count = 0;
	for (int i = 0; i < n; ++i)
	{
		bool b = false;
		for (int j = 0; j < m; ++j)
		{
			// 对于每一个像素点，进行测试
			int count = 0;
			bool flag = true;
			while (count < 8)
			{
				switch (count)
				{
				case 0: // 左上角
					if (i - 1 >= 0 && j - 1 >= 0 && abs(v[i][j] - v[i - 1][j - 1]) <= tol)
						flag = false;
					break;
				case 1: // 左边
					if (j - 1 >= 0 && abs(v[i][j] - v[i][j - 1]) <= tol)
						flag = false;
					break;
				case 2: // 左下角
					if (i + 1 < n && j - 1 >= 0 && abs(v[i][j] - v[i + 1][j - 1]) <= tol)
						flag = false;
					break;
				case 3: // 上边
					if (i - 1 >= 0 && abs(v[i][j] - v[i - 1][j]) <= tol)
						flag = false;
					break;
				case 4: // 下边
					if (i + 1 < n && abs(v[i][j] - v[i + 1][j]) <= tol)
						flag = false;
					break;
				case 5: // 右上角
					if (i - 1 >= 0 && j + 1 < m && abs(v[i][j] - v[i - 1][j + 1]) <= tol)
						flag = false;
					break;
				case 6: // 右边
					if (j + 1 < m && abs(v[i][j] - v[i][j + 1]) <= tol)
						flag = false;
					break;
				case 7: // 右下角
					if (i + 1 < n && j + 1 < m && abs(v[i][j] - v[i + 1][j + 1]) <= tol)
						flag = false;
					break;
				default:
					break;
				}
				if (flag == false) break;
				++count;
			}

			if (flag)
			{
				auto iter = value.find(v[i][j]);
				if (iter != value.end() && iter->second == 1)
				{
					res_count++;
					if (res_count > 1)
					{
						// 若能统计到两个结果，就不用继续统计了，直接输出 Not Unique
						b = true; 
						break;
					}

					x = j + 1;
					y = i + 1;
					val = v[i][j];
				}
			}
		}
		if (b) break;
	}

	if (res_count == 1)
		printf("(%d, %d): %d", x, y, val);
	else if (res_count > 1)
		printf("Not Unique");
	else
		printf("Not Exist");

	return 0;
}

