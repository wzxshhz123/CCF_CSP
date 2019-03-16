#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
	string target;
	cin >> target;
	int flag = 0;
	cin >> flag;
	regex *r;
	if (!flag) {
		r = new regex(target, regex::icase);
	}
	else {
		r = new regex(target);
	}
	int n = 0;
	cin >> n;
	
	for (int i = 0;i < n;++i) {
		string test;
		cin >> test;
		if (regex_search(test, *r)) {
			cout << test << endl;
		}
	}
	return 0;
}
