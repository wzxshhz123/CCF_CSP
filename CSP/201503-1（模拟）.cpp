#include <iostream>
using namespace std;
constexpr int max_m = 1005;
int g[max_m][max_m] = {0};
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			int e = 0;
			scanf("%d", &e);
			g[i][j] = e;
		}
	}
	for (int j = m - 1;j > -1;--j) {
		for (int i = 0;i < n;++i) {
			printf("%d", g[i][j]);
			if (j != -1)
				printf(" ");
		}
		printf("\n");
	}
} 
