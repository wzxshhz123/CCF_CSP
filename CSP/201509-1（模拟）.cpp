#include <iostream>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int e = 0;
	int count = 1;
	scanf("%d", &e);
	for (int i = 1;i < n;++i) {
		int d = 0;
		scanf("%d", &d);
		if (e != d) {
			++count;
			e = d;
		}
	}
	cout << count;
	return 0;
}
