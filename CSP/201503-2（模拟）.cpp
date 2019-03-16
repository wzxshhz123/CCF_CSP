#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, int> mp;
	auto Cmp = [](const pair<int, int>&lhs, const pair<int, int> &rhs) {
		if (lhs.second != rhs.second)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
	};
	set<pair<int,int>, decltype(Cmp)> s(Cmp);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		if (mp.count(e) == 0) {
			++mp[e];
			s.emplace(e, mp[e]);
		}
		else {
			int v = mp[e];
			auto iter = s.find(make_pair(e, v));
			s.erase(iter);
			++mp[e];
			s.emplace(e, mp[e]);
		}
	}
	int flag = 0;
	for (auto iter = s.begin();iter != s.end();++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}
	return 0; 
}
