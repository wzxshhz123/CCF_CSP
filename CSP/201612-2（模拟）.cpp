#include <bits/stdc++.h>
using namespace std;
constexpr double rate[] = {0, 0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
constexpr int node[] = {0, 3500, 5000, 8000, 12500, 38500, 58500, 83500, INT_MAX};
int res[15] = {0};
int main() {
	int n = 0;
	cin >> n;
	for (int i = 1;i < 9;++i) {
		res[i] = res[i - 1] + (node[i] - node[i - 1]) * (1 - rate[i]);
	}
	for (int i = 1;i < 9;++i) {
		if (res[i] >= n) {
			int S = (n - res[i - 1]) / (1 - rate[i]) + node[i - 1];
			cout << S;
			break;
		}
	}
	return 0;
}
