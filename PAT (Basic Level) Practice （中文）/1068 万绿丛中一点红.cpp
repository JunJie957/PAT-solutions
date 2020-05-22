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
			// ����ÿһ�����ص㣬���в���
			int count = 0;
			bool flag = true;
			while (count < 8)
			{
				switch (count)
				{
				case 0: // ���Ͻ�
					if (i - 1 >= 0 && j - 1 >= 0 && abs(v[i][j] - v[i - 1][j - 1]) <= tol)
						flag = false;
					break;
				case 1: // ���
					if (j - 1 >= 0 && abs(v[i][j] - v[i][j - 1]) <= tol)
						flag = false;
					break;
				case 2: // ���½�
					if (i + 1 < n && j - 1 >= 0 && abs(v[i][j] - v[i + 1][j - 1]) <= tol)
						flag = false;
					break;
				case 3: // �ϱ�
					if (i - 1 >= 0 && abs(v[i][j] - v[i - 1][j]) <= tol)
						flag = false;
					break;
				case 4: // �±�
					if (i + 1 < n && abs(v[i][j] - v[i + 1][j]) <= tol)
						flag = false;
					break;
				case 5: // ���Ͻ�
					if (i - 1 >= 0 && j + 1 < m && abs(v[i][j] - v[i - 1][j + 1]) <= tol)
						flag = false;
					break;
				case 6: // �ұ�
					if (j + 1 < m && abs(v[i][j] - v[i][j + 1]) <= tol)
						flag = false;
					break;
				case 7: // ���½�
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
						// ����ͳ�Ƶ�����������Ͳ��ü���ͳ���ˣ�ֱ����� Not Unique
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

