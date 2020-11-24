#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> first { {"tret",0} , {"jan",1}, {"feb",2},{"mar",3} , {"apr",4}, {"may",5},{"jun",6} , {"jly",7}, {"aug",8},{"sep",9} , {"oct",10}, {"nov",11},{"dec", 12} };
unordered_map<int, string> first2{ {0,"tret"} , {1,"jan"}, {2,"feb"},{3,"mar"} , {4,"apr"}, {5,"may"},{6,"jun"} , {7,"jly"}, {8,"aug"},{9,"sep"} , {10,"oct"}, {11,"nov"},{12, "dec"} };
unordered_map<string, int> second { {"tam",1},  {"hel",2},  {"maa",3} ,{"huh",4},  {"tou",5},  {"kes",6} ,{"hei",7},  {"elo",8}, {"syy",9} , {"lok",10}, {"mer",11}, {"jou", 12} };
unordered_map<int, string> second2{ {1,"tam"},  {2,"hel",}, {3,"maa"} ,{4,"huh"},  {5,"tou",}, {6,"kes"} ,{7,"hei"},  {8,"elo",}, {9,"syy"} ,{10,"lok"}, {11,"mer"}, {12, "jou"} };
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	string num;
	for (int i = 0; i < n; ++i) {
		getline(cin, num);
		if (isalpha(num[0])) {
			if (num.length() == 3) {
				printf("%d\n", first[num] != 0 ? first[num] : second[num] * 13);
			} else {
				printf("%d\n", second[num.substr(0, 3)] * 13 + first[num.substr(4)]);
			}
		} else {
			int s = stoi(num);
			printf("%s", s >= 13 ? second2[s / 13].c_str() : first2[s].c_str());
			if (s >= 13 && s % 13 != 0) printf(" %s", first2[s % 13].c_str());
			printf("\n");
		}
	}
	return 0;
}
