#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0;i < str.length();++i) {
		int num = str[i] - '0';
		sum += num;
	}
	cout << sum;
} 
