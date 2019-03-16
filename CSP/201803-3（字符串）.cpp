#include <iostream>
#include <regex>
#include <vector>
#include <utility>
#include <unordered_map>
#include <vector>
using namespace std;
vector<pair<regex, string>> trans {
	{regex("<int>"), string("([0-9]+)")},
	{regex("<str>"), string("([^/]+)")},
	{regex("<path>"), string("(.+)")}
};
vector<pair<string, regex>> rules;
int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		string ru;
		string name;
		cin >> ru >> name;
		for (int i = 0;i < trans.size();++i) {
			ru = regex_replace(ru, trans[i].first, trans[i].second);
		}
		rules.emplace_back(name, regex(ru));
	}
	smatch res;
	for (int i = 0;i < m;++i) {
		string target;
		cin >> target;
		int f = 0;
		for (int i = 0;i < rules.size();++i) {
			auto it = rules[i];
			if (regex_match(target, res, it.second)) {
				cout << it.first;
				for (int i = 1;i <= res.size();++i) {
					auto p = res.str(i);
					while (p[0] == '0')
						p.erase(0, 1);
					cout << " " << p;
				}
				f = 1;
				if (i != m - 1)
					cout << "\n";
				break;
			}
		}
		if (!f) {
			cout << "404";
			if (i != m - 1) {
				cout << "\n";
			}
		}
	}
	return 0;
}
