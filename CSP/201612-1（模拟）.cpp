#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	int res = -1;
	for (int i = 0;i < n;++i) {
		int max = 0;
		int min = 0;
		int v = vec[i];
		for (int j = 0;j < n;++j) {
			if (vec[j] > v)
				++max;
			else if (vec[j] < v)
				++min;
		}
		if (min == max)
			res = v;
	}
	cout << res;
	return 0;
}
