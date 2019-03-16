#include <stack>
#include <iostream>
using namespace std;
constexpr int max_n = 10005;
int height[max_n] = {0};
int main() {
	int n = 0;
	cin >> n;
	for (int i = 0;i < n;++i) {
		int e = 0;
		cin >> e;
		height[i] = e;
	}
	stack<int> s;
	long long max_area = -1;
	for (int i = 0;i <= n;++i) {
		if (s.empty() || height[i] > height[s.top()]) {
			s.push(i);
		}
		else {
			int local_max = height[s.top()];
			s.pop();
			long long local_are = 0;
			if (s.empty()) {
				local_are = local_max * i;
			}
			else {
				local_are = local_max * (i - s.top() - 1);
			}
			if (local_are > max_area)
				max_area = local_are;
			--i;
		}
	}
	cout << max_area;
	return 0;
} 
