#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<string, int> type_one;

bool cmp(const type_one& v1, const type_one& v2) {
    return v1.second == v2.second ? v1.first < v2.first : v1.second > v2.second;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int score;
    string number;
    unordered_map<string, int> um(n);
    for (int i = 0; i < n; ++i) {
        cin >> number >> score;
        um[number] = score;
    }

    int type;
    string order;
    for (int i = 1; i <= m; ++i) {
        cin >> type >> order;
        printf("Case %d: %d %s\n", i, type, order.c_str());
        switch (type) {
        case 1:
            {
                vector<type_one> vec;
                for (auto& iter : um) {
                    if (iter.first[0] == order[0]) // �ҵ���Ӧ�ļ���
                        vec.emplace_back(make_pair(iter.first, iter.second));
                }

                if (vec.empty()) {
                    printf("NA\n");  // ���Ϊ��
                } else {
                    sort(vec.begin(), vec.end(), cmp); // ����
                    for (auto& iter : vec)  // ���
                        printf("%s %d\n", iter.first.c_str(), iter.second);
                }
            }
            break;
        case 2:
            {
                int count = 0, sum = 0;
                for (auto& iter : um) {
                    if (iter.first.substr(1, 3).compare(order) == 0) {
                        ++count;    // �ҵ���Ӧ�Ŀ���
                        sum += iter.second;
                    }
                }

                if (count != 0) {   
                    printf("%d %d\n", count, sum);  // ���
                } else {
                    printf("NA\n");  // Ϊ��
                }
            }
            break;
        case 3:
            {
                unordered_map<string, int> count;
                for (auto& iter : um) {  // �ҵ���Ӧ������
                    if (iter.first.substr(4, 6).compare(order) == 0)
                        ++count[iter.first.substr(1, 3)];
                }

                vector<type_one> vec;
                for (auto& iter : count) vec.emplace_back(iter);

                if (vec.empty()) {
                    printf("NA\n"); // Ϊ��
                } else {
                    sort(vec.begin(), vec.end(), cmp); // �������
                    for (auto& iter : vec)  
                        printf("%s %d\n", iter.first.c_str(), iter.second);
                }
            }
            break;
        }
    }
    return 0;
}
