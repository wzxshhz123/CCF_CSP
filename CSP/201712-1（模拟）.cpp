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
	int min = INT_MAX;
	for (int i = 0;i < n;++i) {
		int v = vec[i];
		for (int j = i + 1;j < n;++j) {
			if (abs(vec[j] - v) < min) {
				min = abs(vec[j] - v);
			}
		} 
	}
	cout << min;
	return 0;
}
