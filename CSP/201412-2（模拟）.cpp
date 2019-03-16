#include <iostream>
#include <vector> 
using namespace std;
constexpr int max_n = 505;
vector<int> res; 
int table[max_n][max_n] = {0};
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			int e = 0;
			scanf("%d", &e);
			table[i][j] = e;
		}
	}
	int i = 0;
	int j = 0;
	int i_crash = 1;
	int xia = 0;
	int shang = 0;
	int j_crash = 0;
	while (i != n - 1 || j != n - 1) {
		cout << table[i][j] << " ";
		res.push_back(table[i][j]);
		if (i_crash) {
			if (j == n - 1) {
				++i;
			}
			else {
				++j;
			}
			xia = 1;
			i_crash = 0;
		}
		else if (j_crash) {
			if (i == n - 1) {
				++j;
			}
			else {
				++i;
			}
			shang = 1;
			j_crash = 0;
		}
		else if (xia) {
			++i;
			--j;
			if (j == 0 || i == n - 1) {
				j_crash = 1;
				xia = 0;
			}
		}
		else if (shang) {
			--i;
			++j;
			if (i == 0 || j == n - 1) {
				i_crash = 1;
				shang = 0;
			}
		}
	}
	cout << table[i][j]; 
	return 0;
} 
