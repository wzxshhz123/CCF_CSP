#include <iostream>
#include <string>
#include <vector> 
//#define DE
using namespace std;
void Split(const string &lhs, vector<string> &vec) {
	int j = 0;
	int i = 0;
	while (true) {
		j = lhs.find('/', i);
		if (j == string::npos || j == lhs.length() - 1)
			break;
		if (j != lhs.size() - 1) {
			vec.push_back(lhs.substr(i, j - i));
			i = j + 1;
		}
	}
	if (lhs.substr(i, lhs.length() - i) != "/")
		vec.push_back(lhs.substr(i, lhs.length() - i));
}
int main() {
	int p = 0;
	string str;
	cin >> p >> str;
	vector<string> vec;
	Split(str, vec);
	cin.ignore();
	while (p--) {
		string cur;
		vector<string> temp;
		vector<string> res;
		getline(cin, cur);
		if (cur[cur.length() - 1] == '/')
			cur.pop_back();
		Split(cur, temp);
		if ((cur.length() != 0 && *cur.begin() != '/') || cur.length() == 0) {
			res = vec;
		}
		for (auto it = temp.begin(); it != temp.end(); ++it) {
			if (*it == "..") {
				if (res.size() != 0)
					res.pop_back();
			}
			else if (*it == "" || *it == ".") {

			}
			else {
				res.push_back(*it);
			}
		}
		int flag = 0;
		for (auto it = res.begin(); it != res.end(); ++it) {
			if (*it != "" && *it != "/") {
				flag = 1;
				cout << '/' << *it;
			}
		}
		if (!flag)
			cout << "/";
		cout << "\n";
#ifdef DE
		cout << "\n";
#endif
	}
	return 0;
}
