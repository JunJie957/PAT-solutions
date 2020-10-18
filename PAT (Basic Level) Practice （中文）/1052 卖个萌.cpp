#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3, tmp;
    vector<string> head, eye, mouth;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    // head
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == '[') {
            tmp.clear();
            while (++i < s1.size() && s1[i] != ']') tmp += s1[i];
            head.emplace_back(tmp);
        }
    }

    // eye
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] == '[') {
            tmp.clear();
            while (++i < s2.size() && s2[i] != ']') tmp += s2[i];
            eye.emplace_back(tmp);
        }
    }

    // mouth
    for (int i = 0; i < s3.size(); ++i) {
        if (s3[i] == '[') {
            tmp.clear();
            while (++i < s3.size() && s3[i] != ']') tmp += s3[i];
            mouth.emplace_back(tmp);
        }
    }

    int k, loc, j = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i, j = 0) {
        tmp.clear();
        for (; j < 5; ++j) {
            scanf("%d", &loc);

            if (loc < 1) break;
            if (j == 1) tmp += "(";
            if (j == 4) tmp += ")";

            if (j == 0 || j == 4) {
                if (loc > head.size()) break;
                tmp += head[loc - 1];
            } else if (j == 2) {
                if (loc > mouth.size()) break;
                tmp += mouth[loc - 1];
            } else if (j == 1 || j == 3) {
                if (loc > eye.size()) break;
                tmp += eye[loc - 1];
            }
        }
        if (j == 5) cout << tmp << endl;
        else cout << "Are you kidding me? @\\/@" << endl;
    }
    return 0;
}
