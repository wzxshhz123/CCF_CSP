#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
constexpr int max_n = 1000005;
int table[max_n] = {0};
int main() {
	auto Cmp = [](const pair<int, int>&lhs, const pair<int, int>&rhs) {
		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;
	};
	set<pair<int, int>, decltype(Cmp)> s(Cmp);
	int n = 0;
	cin >> n;
	int max = -1;
	int sum = 0;
	for (int i = 0;i < 2 * n; ++i) {
		int st = -1;
		int ed = -1;
		cin >> st >> ed;
		if (ed > max)
			max = ed;
		while (st != ed) {
			++table[st];
			++st;
		}
	}
	for (int i = 1;i <= max;++i) {
		if (table[i] == 2)
			++sum;
	}
	cout << sum;
	return 0;	
}

