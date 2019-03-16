#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int m = 0;
int n = 0;
int main() {
	cin >> m >> n;
	cin.ignore();
	vector<string> vec;
	for (int i = 0;i < m;++i) {
		string str;
		getline(cin, str);
		vec.push_back(str);
	}
	unordered_map<string, string> mp;
	for (int i = 0;i < n;++i) {
		string var;
		string value;
		cin >> var;
		var.insert(0, " ");
		var.insert(0, "{");
		var.insert(0, "{");	
		var.push_back(' ');
		var.push_back('}');
		var.push_back('}');
		getchar();
		getline(cin, value);
		value.erase(value.begin());
		value.erase(value.end() - 1);
		mp[var] = value;
	}
//	for (auto it = mp.begin();it != mp.end();++it) {
//		cout << it->first << " " << it->second << "\n";
//	}
	string temp("\\{\\{\\s\\w*\\s\\}\\}");
	regex rege(temp);
	smatch res;
	for (int i = 0;i < vec.size();++i) {
		int flag = 0;
		for (sregex_iterator it(vec[i].begin(), vec[i].end(), rege), end_it; it != end_it;++it) {
			flag = 1;
			cout << it->prefix();
			if (mp.count(it->str()) != 0) {
				cout << mp[it->str()];
			}
			auto temp = it;
			++temp;
			if (temp == end_it) {
				cout << it->suffix() << "\n";
			}
		}
		if (!flag)
			cout << vec[i] << "\n";
	}
	return 0;
} 
