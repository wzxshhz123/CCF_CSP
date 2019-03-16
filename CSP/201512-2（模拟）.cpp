#include <iostream>
#include <utility> 
using namespace std;
constexpr int max_n = 35;
int table[max_n][max_n] = {0};
int record[max_n][max_n] = {0};
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			int e = 0;
			scanf("%d", &e);
			table[i][j] = e;
		}
	}
	for (int i = 0;i < n;++i) {
		int num = 1;
		int st = -1;
		int ed = -1;
		int pre = table[i][0];
		for (int j = 1;j < m;++j) {
			if (table[i][j] == pre) {
				if (st == -1)
					st = j - 1;
				++num;
			}
			if (table[i][j] != pre || j == m - 1) {
				if (j == m - 1 && table[i][j] == pre)
					ed = j;
				else
					ed = j - 1;
				if (num >= 3) {
					for (int k = st;k <= ed;++k) {
						record[i][k] = 1;
					}
				}
				num = 1;
				st = -1;
				pre = table[i][j];
			}
		}
	}
	for (int j = 0;j < m;++j) {
		int num = 1;
		int st = -1;
		int ed = -1;
		int pre = table[0][j];
		for (int i = 1;i < n;++i) {
			if (table[i][j] == pre) {
				if (st == -1)
					st = i - 1;
				++num;
			}
			if (table[i][j] != pre || i == n - 1) {
				if (i == n - 1 && table[i][j] == pre)
					ed = i;
				else
					ed = i - 1;
				if (num >= 3) {
					for (int k = st;k <= ed;++k) {
						record[k][j] = 1;
					}
				}
				num = 1;
				st = -1;
				pre = table[i][j];
			}
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			if (record[i][j] != 0) {
				printf("0");
			}
			else
				printf("%d", table[i][j]);
			if (j != m - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
