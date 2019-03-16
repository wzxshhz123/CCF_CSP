#include <iostream>
#include <regex>
#include <unordered_map>
#include <map>
using namespace std;
unordered_map<char, int> mp;
int main() {
	string format;
	cin >> format;
	for (auto iter = format.begin();iter != format.end();++iter) {
		if (isalpha(*iter) && (iter + 1) != format.end()) {
			if (*(iter + 1) != ':') {
				mp[*iter] = 1;
			}
			else if (*(iter + 1) == ':') {
				mp[*iter] = 2;
			}	
		}
		else if (isalpha(*iter) && iter == format.end() - 1) {
			mp[*iter] = 1;
		}
	}
	int n = 0;
	cin >> n;
	getchar();
	for (int i  = 1;i <= n;++i) {
		map<char, string> res;
		string target;
		getline(cin, target);
		stringstream ss(target);
		ss >> target;
		string temp;
		while (ss >> target) {
			if (target.size() == 2 && target[0] == '-' && mp[target[1]] == 1) {
				res[target[1]] = string("-") + target[1]; 
			}
			else if (target.size() == 2 && target[0] == '-' && mp[target[1]] == 2 && ss >> temp) {
				res[target[1]] = string("-") + target[1] + string(" ") + temp;
			}
			else
				break;
		}
		cout << "Case " << i << ":";
		for (auto iter = res.begin();iter != res.end();++iter) {
			cout << " " << iter->second;
		}
		cout << endl;
	}
	return 0;
} 
