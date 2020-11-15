#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> um;     // ��¼ȫ��λ����Ϣ
    unordered_map<int, int> miss;   // ��¼��λ��Ϣ, ����¼��λ���ϵģ���Ϊ�ᵥ���ж�
    int n, num, loc = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        um[num] = i;
        if (num == 0) loc = i;
        if (i != num && num != 0) miss[num] = i;
    }
    while (1) {
        if (loc == 0) { // ��� 0 ���� λ��0 ��
            if (miss.empty()) { // ��λ��ϢΪ�գ�˵���������
                cout << cnt;
                return 0;
            }
            ++cnt; // ����һ�ν�������
            loc = miss.begin()->second;
            um[miss.begin()->first] = 0;
            miss.begin()->second = 0;
        }
        ++cnt;
        miss.erase(loc);
        loc = um[loc];
    }
    return 0;
}
