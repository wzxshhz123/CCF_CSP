#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, int> mp;
	auto Cmp = [](int a, int b) {
		return a > b;
	};
	map<int, int, decltype(Cmp)> m(Cmp);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		++mp[e];
		if (m.count(mp[e])) {
			if (m[mp[e]] > e) {
				m[mp[e]] = e;
			}
		}
		else 
			m[mp[e]] = e;
	}
	cout << m.begin()->second;
}
