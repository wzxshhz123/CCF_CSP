#include <iostream>
using namespace std;
int main() {
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int num = 0;
	int now = 0;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		now += e;
		if (now >= k) {
			++num;
			now = 0;
		}
	}
	if (now != 0)
		++num;
	cout << num;
	return 0;
} 
