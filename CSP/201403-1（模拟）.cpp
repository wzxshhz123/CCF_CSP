#include <iostream>
#include <cmath>
#include <unordered_map> 
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, int>mp;
	int count = 0;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		e = abs(e);
		if (mp.count(e) != 0)
			++count;
		else
			++mp[e];
	}
	cout << count;
}
