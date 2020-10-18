#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
    string name;
    int gp, gm, gf, final;
};

unordered_map<string, int> um; // 辅助变量，存储数据在数组中的位置

bool cmp(const node*  n1, const node* n2) {
    return (*n1).final == (*n2).final ? (*n1).name < (*n2).name : (*n1).final >(*n2).final;
}

int main() {
    int p, m, n, score, loc = -1;
    scanf("%d%d%d", &p, &m, &n);

    string name;
    vector<node> v;
    for (int i = 0; i < p; ++i) {
        cin >> name >> score;
        if (score >= 200) {
            v.emplace_back(node{ name,score,-1,-1,0 });
            um[name] = ++loc;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> name >> score;
        if (um.find(name) != um.end()) {
            v[um[name]].gm = score;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        if (um.find(name) != um.end()) {
            v[um[name]].gf = score;
            if (v[um[name]].gm > score) {
                score = v[um[name]].gm * 0.4 + score * 0.6 + 0.5; // 四舍五入
            }
            v[um[name]].final = score; // 最终成绩
        }
    }

    vector<node*> res;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].final >= 60) res.emplace_back(&v[i]);
    }

    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); ++i) {
        printf("%s %d %d %d %d\n", ((*(res[i])).name).c_str(), (*(res[i])).gp, (*(res[i])).gm, (*(res[i])).gf, (*(res[i])).final);
    }
    return 0;
}
