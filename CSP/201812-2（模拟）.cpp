#include <bits/stdc++.h>
using namespace std;
int main() {
	long long r = 0;
	long long y = 0;
	long long g = 0;
	cin >> r >> y >> g;
	long long total_time = r + y + g;
	int n = 0;
	cin >> n;
	long long pass = 0;
	for (int i = 0;i < n;++i) {
		int type = 0;
		long long time = 0;
		cin >> type >> time;
		if (type == 0) {
			pass += time;
		}
		else if (type == 1) {
			long long temp = ((r - time) + pass) % total_time;
			if (temp < r) {
				pass += r - temp;
			}
			else if (temp < r + g) {
				
			}
			else if (temp < r + g + y) {
				pass += r + g + y - temp + r;
			}
		}
		else if (type == 2) {
			long long temp = ((y - time) + r + g + pass) % total_time;
			if (temp < r) {
				pass += r - temp;
			}
			else if (temp < r + g) {
				
			}
			else if (temp < r + g + y) {
				pass += r + g + y - temp + r;
			}
		}
		else if (type == 3) {
			long long temp = ((g - time) + r + pass) % total_time;
			if (temp < r) {
				pass += r - temp;
			}
			else if (temp < r + g) {
				
			}
			else if (temp < r + g + y) {
				pass += r + g + y - temp + r;
			}
		}
	}
	cout << pass;
	return 0;
} 
