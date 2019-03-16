#include <iostream>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int num = 0;
	while (n >= 50) {
		num += 7;
		n -= 50;
	}
	while (n >= 30) {
		num += 4;
		n -= 30;
	} 
	while (n >= 10) {
		++num;
		n -= 10; 
	}
	cout << num;
	return 0;
} 
