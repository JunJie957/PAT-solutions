#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	// ����λ
	if (s[0] == '-') cout << "-";
	
	string integer;	// ��������
	string index;	// ָ������
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] != 'E')
			integer += s[i];
		else
		{
			index = s.substr(i + 1);
			break;
		}
	}
	
	int index_i = atof(index.c_str());
	if (index_i > 0)
	{
		int loc = integer.size() - 2;		// С��������һλ��֮��ľ���
		integer.erase(integer.begin() + 1); // ɾ��С����

		if (loc > index_i)
		{
			// ��С������� index_i λ
			integer.insert(integer.begin() + index_i + 1, '.');
		}
		else if(loc < index_i)
		{
			// ������ĩβ��Ӷ�Ӧ��������
			for (int i = 0; i < index_i - loc; ++i)
				integer += '0';
		}
	}
	else if(index_i < 0)
	{
		integer.erase(integer.begin() + 1); // ɾ��С����
	
		// ����������ǰ������
		for (int i = 0; i < abs(index_i) - 1; ++i)
			integer.insert(integer.begin(), '0');
		
		// ����������ֺ�С����
		integer.insert(integer.begin(), '.');
		integer.insert(integer.begin(), '0');
	}

	cout << integer << endl;
	return 0;
}
