#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<char, string> um {
	{0,"ling"}, {1,"yi"},  {2,"er"}, {3,"san"}, {4,"si"}, 
	{5,"wu"},   {6,"liu"}, {7,"qi"}, {8,"ba"},  {9,"jiu"}
};
int main() {
	string str;
	cin >> str;
	int sum = 0;
	for (auto& iter : str) sum += iter - '0';
	str = to_string(sum);
	for (auto& iter : str) {
		if(iter != *str.begin()) printf(" ");
		printf("%s", um[iter - '0'].c_str());
	}
	return 0;
}
