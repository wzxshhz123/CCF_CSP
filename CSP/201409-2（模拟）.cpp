#include <iostream>
using namespace std;
constexpr int max_v = 105;
int table[max_v][max_v] = {0};
int main() {
	int n = 0;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0;i < n;++i) {
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = x1;j < x2;++j) {
			for (int k = y1;k < y2;++k) {
				if (table[j][k] == 0) {
					++count;
					table[j][k] = 1;
				}
			}
		}
	}
	cout << count;
	return 0;
}
