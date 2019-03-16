#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	queue<int> q;
	for (int i = 1;i <= n;++i) {
		q.push(i);
	} 
	int i = 1;
	while (q.size() != 1) {
		auto top = q.front();
		q.pop();
		if (i % k == 0 || (i % 10 == k)) {
			
		}
		else {
			q.push(top);
		}
		++i;
	}
	cout << q.front();
	return 0;
}
