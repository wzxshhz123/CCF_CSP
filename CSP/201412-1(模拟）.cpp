#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, int> mp;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		++mp[e];
		cout << mp[e] << " ";
	}
}
