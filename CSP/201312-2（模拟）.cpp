#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sum = 0;
	int i = 1;
	for (auto iter = str.begin();iter != str.end() - 2;++iter) {
		if (isdigit(*iter)) {
			sum += ((*iter) - '0') * i;
			++i;
		}
	}
	sum %= 11;
	int flag = 0;
	if (sum == 10 && str.back() == 'X') {
		flag = 1;
	}
	else if (sum == (str.back() - '0')) {
		flag = 1;
	}
	if (flag)
		cout << "Right";
	else {
		for (auto iter = str.begin();iter != str.end() - 1;++iter)
			cout << *iter;
		if (sum != 10) 
			cout << sum;
		else
			cout << 'X';
	}
	return 0;
}
