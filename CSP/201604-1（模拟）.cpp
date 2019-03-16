#include <iostream>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int st = -1;
	int se = -1;
	scanf("%d %d", &st, &se);
	int pre = st;
	int now = se;
	int num = 0;
	for (int i = 2;i < n;++i) {
		int post = 0;
		scanf("%d", &post);
		if ((now > pre && post < now) || (now < pre && post > now)) {
			++num;
		}
		pre = now;
		now = post; 
	}
	cout << num;
} 
