#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	int e = 0;
	scanf("%d", &e);
	int pre = 0;
	int now = e;
	for (int i = 1;i < n;++i) {
		int post = 0;
		scanf("%d", &post);
		int new_price = 0;
		if (i == 1) 
			new_price = (pre + now + post) / 2;
		else
			new_price = (pre + now + post) / 3;
		vec.push_back(new_price);
		pre = now;
		now = post;
	}
	vec.push_back((now + pre) / 2);
	for (int i = 0;i < n;++i) {
		printf("%d", vec[i]);
		if (i != n - 1)
			printf(" ");
	}
	return 0;
}
