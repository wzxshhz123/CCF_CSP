#include <iostream>
#include <unordered_map>
using namespace std;
struct Pri {
	string id;
	int pr = -1;
	Pri() = default;
	Pri(const string &s, int p) : id(s), pr(p) {
		
	}
};
struct Player {
	unordered_map<string, Pri> mp;
};
unordered_map<string, Player> str_to_pl;
struct User {
	unordered_map<string, Pri> mp;
};
unordered_map<string, User> str_to_us;
int main() {
	int p = -1;
	cin >> p;
	for (int i = 0;i < p;++i) {
		string s;
		cin >> s;
	}
	int r = -1;
	cin >> r;
	for (int i = 0;i < r;++i) {
		Player now;
		string s;
		int size = -1;
		cin >> s >> size;
		for (int j = 0;j < size;++j) {
			string temp;
			cin >> temp;
			int p = -1;
			if (temp.find(':') != string::npos) {
				int pos = temp.find(':');
				p = stoi(temp.substr(pos + 1, temp.length() - pos - 1));
				temp = temp.substr(0, pos);
			}
			if (now.mp.count(temp) == 0) {
				now.mp[temp] = move(Pri(s, p));
			}
			else {
				now.mp[temp].pr = max(now.mp[temp].pr, p);
			}
		}
		str_to_pl[s] = now;
	}
	int u = -1;
	cin >> u;
	for (int i = 0;i < u;++i) {
		string name;
		int size = -1;
		cin >> name >> size;
		User us;
		for (int j = 0;j < size;++j) {
			string pl;
			cin >> pl;
			auto t = str_to_pl[pl].mp;
			for (auto it = t.begin();it != t.end();++it) {
				if (us.mp.count(it->first) == 0) {
					us.mp[it->first] = it->second;
				}
				else {
					us.mp[it->first].pr = max(us.mp[it->first].pr, it->second.pr);
				}
			}
		}
		str_to_us[name] = us;
	}
	int q = -1;
	cin >> q;
	for (int i = 0;i < q;++i) {
		string target;
		string test;
		cin >> target >> test;
		int p = -1;
		if (test.find(':') != string::npos) {
			int pos = test.find(':');
			p = stoi(test.substr(pos + 1, test.length() - pos - 1));
			test = test.substr(0, pos);
		}
		auto us = str_to_us[target];
		if (us.mp.count(test) != 0) {
			if (p == -1) {
				if (us.mp[test].pr != -1) {
				cout << us.mp[test].pr << "\n";
				}
				else {
					cout << "true" << "\n";
				}
			}
			else {
				if (us.mp[test].pr >= p) {
					cout << "true" << "\n";
				}
				else {
					cout << "false" << "\n";
				}
			}
		}
		else {
			cout << "false" << "\n";
		}
	}
	return 0;
}
