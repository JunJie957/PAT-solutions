 #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string choopingString(string s, int& e, int n)
{
	string res = "0.";	

	// ȥ��ǰ���㣬���� 000000.001
	while (s.length() > 0 && s[0] == '0')
		s.erase(s.begin());

	// ����С����󣬼�������ȥ����Ĳ���
	if (s.length() > 0 && s[0] == '.')
	{
		s.erase(s.begin()); // ȥ��С����
		while (s.length() > 0 && s[0] == '0')
		{
			s.erase(s.begin()); // ȥ��С��������� ���� 0.000001
			--e;
		}

		// ���ȥ��С�������㣬�ַ�������Ϊ�㣬�������ַ���Ϊ�� ���� 0.0000000
		if (s.length() == 0) e = 0;
	}
	else 
	{// ���ȥ��ǰ�����û������С���㣬��ͳ��ָ��
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] == '.')
			{
				s.erase(s.begin() + i);	// ����С���㣬ֹͣͳ�ƣ���ɾ��С����
				break;
			}
			else ++e;
		}
	}

	int num = 0, loc = 0, len = s.length();
	while (num++ < n)
	{
		if (loc < len)  res += s[loc++];
		else  res += '0';	// ����
	}
	return res;
}

int main()
{
	// ����
	int n;
	string a, b;
	cin >> n >> a >> b;

	// ָ��
	int e1 = 0, e2 = 0; 
	
	// ����ָ�����������ַ���
	string r1 = choopingString(a, e1, n);
	string r2 = choopingString(b, e2, n);
	
	// ��ӡ����
	if (r1.compare(r2) == 0 && e1 == e1)
		printf("YES %s*10^%d", r1.c_str(), e1);
	else
		printf("NO %s*10^%d %s*10^%d", r1.c_str(), e1, r2.c_str(), e2);
	
	return 0;
}
