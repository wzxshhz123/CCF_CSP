#include <iostream>
using namespace std;
int main() {
	int r = 0;
	int y = 0;
	int g = 0;
	scanf("%d %d %d", &r, &y, &g);
	int n = 0;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0;i < n;++i) {
		int k = 0;
		int t = 0;
		scanf("%d %d", &k, &t);
		if (!k)
			sum += t;
		else if (k == 1) {
			sum += t;
		}
		else if (k == 2) {
			sum += t;
			sum += r;
		}
	}
	cout << sum;
	return 0;
}
