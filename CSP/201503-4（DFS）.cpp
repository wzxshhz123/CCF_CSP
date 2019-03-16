#include <iostream>
#include <vector>
using namespace std;
int n = 0;
int m = 0;
constexpr int max_n = 20005;
vector<int> vec[max_n];
bool vis[max_n] = {0};
int max_level = -1;
int ans = -1;
int res = 0;
void Clear() {
	fill(vis, vis + max_n, false);
}
void DFS(int v, int level) {
	vis[v] = true;
	if (level > max_level) {
		max_level = level;
		ans = v;
	}
	for (int i = 0;i < vec[v].size();++i) {
		if (!vis[vec[v][i]]) {
			DFS(vec[v][i], level + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 2;i <= n + m;++i) {
		int e = 0;
		cin >> e;
		vec[e].push_back(i);
		vec[i].push_back(e);
	}
	DFS(1, 1);
	Clear();
	max_level = -1;
	DFS(ans, 0);
	cout << max_level;
	return 0;
}
