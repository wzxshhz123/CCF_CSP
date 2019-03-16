#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int pre = -1;
	scanf("%d", &pre);
	int max = -1; 
	for (int i = 1;i < n;++i) {
		int ins = -1;
		scanf("%d", &ins);
		if (abs(ins - pre) > max) {
			max = abs(ins - pre);
		}
		pre = ins;
	}
	cout << max;
	return 0;
}
