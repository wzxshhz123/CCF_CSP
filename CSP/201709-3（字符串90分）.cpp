#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#include <memory>
#include <typeinfo>
using namespace std;
struct Node {
	unordered_map<string, shared_ptr<Node>> mp;
	string value;
	
	Node() = default;
	Node(string v) : value(v) {
		
	}
};
unordered_map<string, shared_ptr<Node>> total;
vector<shared_ptr<Node>> vec;
int main() {
	int n = 0;
	int m = 0;
	cin >> n >> m;
	cin.ignore();
	string temp;
	string str;
	while(n--) {
		getline(cin, temp);
		str += temp;
	}
	str = regex_replace(str, regex(" "), "");
 	str = regex_replace(str, regex("\\\\\""), "\"");
  str = regex_replace(str, regex("\\\\\\\\"), "\\");
//  cout << str << "\n";
  string t("(\"+(.*?)\"+:(\\{))|(\"+[^,]*?\"+)|(\\},)");
 	regex imp(t);
  string fath;
  string pre_father;
  string pre;
  int flag = 0;
  int j = 0;
  auto temp_m = total;
  for (sregex_iterator it(str.begin(), str.end(), imp), end_it; it != end_it;++it) {
//  	cout << it->str() << "\n";		
  	if (it->str(3) == "{") {
  		pre_father = fath;
  		fath = it->str(2);
  		++flag;
		}
		else if (it->str(5) == "},") {
			--flag;
			j = 0;
			if (vec.back()->mp.size() == 0)
				vec.back()->mp[""] = shared_ptr<Node>(new Node());
			fath = pre_father;
			vec.pop_back();
			continue;
		}
		if (!flag && it->str(5).length() == 0) {
			if (j == 1) {
				auto now = it->str(4);
				if (now.back() == '"')
					now.pop_back();
				if (now[0] == '"')
					now.erase(now.begin());
				total[pre] = shared_ptr<Node>(new Node(now));
			}
			else {
				pre = it->str(4);
				if (pre.back() == '"')
					pre.pop_back();
				if (pre[0] == '"')
					pre.erase(pre.begin());
			}
			++j;
			j %= 2;
		}
		else if (flag && it->str(3).length() == 0) {
			if (j == 1) {
				auto now = it->str(4);
				if (now.back() == '"')
					now.pop_back();
				if (now[0] == '"')
					now.erase(now.begin());
				vec.back()->mp[pre] = shared_ptr<Node>(new Node(now));
			}
			else {
				pre = it->str(4);
				if (pre.back() == '"')
					pre.pop_back();
				if (pre[0] == '"')
					pre.erase(pre.begin());
			}
			++j;
			j %= 2;	
		}
		else if (flag == 1 && it->str(3).length() != 0) {
			vec.clear();
			total[fath] = shared_ptr<Node>(new Node());
			vec.push_back(total[fath]);
		} 
		else if (flag >= 2 && it->str(3).length() != 0) {
			vec.back()->mp[fath] = shared_ptr<Node>(new Node());
			vec.push_back(vec.back()->mp[fath]);
		}
	}
	for (int i = 0;i < m;++i) {
		string str;
		getline(cin, str);
		if (str.find('.') == string::npos) {
			if (total.count(str) && total[str]->mp.size() == 0) {
				cout << "STRING" << " " << total[str]->value << "\n";
			}
			else if (total.count(str) && total[str]->mp.size() != 0) {
				cout << "OBJECT" << "\n";
			}
			else if (!total.count(str)) {
				cout << "NOTEXIST" << "\n";
			}
		}
		else {
			int pre = 0;
			int pos = str.find('.', pre);
			auto m = total;
			int f = 1;
			while(pos != -1) {
				auto s1 = str.substr(pre, pos - pre);
				if (m.count(s1) == 0) {
					cout << "NOTEXIST" << "\n";
					f = 0;
					break;
				}
				pre = pos + 1;
				m = m[s1]->mp;
				pos = str.find('.', pre);
			}
			if (!f) {

			}
			else {
				auto s2 = str.substr(pre, str.length() - pre);
				if (m.count(s2) && m[s2]->mp.size() == 0) {
					cout << "STRING" << " " << m[s2]->value << "\n";
				}
				else if (m.count(s2) && m[s2]->mp.size() != 0) {
					cout << "OBJECT" << "\n";
				}
				else if (!m.count(s2)) {
					cout << "NOTEXIST" << "\n";
				}
			}
		}
	}
	return 0;
} 
