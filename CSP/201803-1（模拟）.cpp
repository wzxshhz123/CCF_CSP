#include <iostream>
using namespace std;
int main() {
	int n = -1;
	scanf("%d", &n);
	int sum = 0;
	int pre = n;
	int pre_n = -1;
	if (n == 2) {
		pre_n = 2;
		sum += 2;
	}
	else if (n == 1){
		pre_n = 1;
		++sum;
	}
	else
		return 0;
	while (~scanf("%d", &n)) {
		if (n == 0)
			break;
		if (n == 1) {
			++sum;
			pre = n;
			pre_n = 1;
		}
		else if (n == 2) {
			if (pre_n == 1) {
				sum += 2;
				pre = n;
				pre_n = 2;
			}
			else {
				pre_n += 2;
				sum += pre_n;
				pre = n;
			}
		}
	}
	cout << sum;
	return 0;
} 
