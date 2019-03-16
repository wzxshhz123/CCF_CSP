#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0;
int m = 0;
constexpr int max_n = 1005;
vector<int> adj[max_n];
bool vis[max_n] = {0};
int sum = 0;
bool know[max_n][max_n] = {0};
void DFS(int v, int st) {
	vis[v] = true;
	know[st][v] = true;
	know[v][st] = true;
	for (int i = 0;i < adj[v].size();++i) {
		if (!vis[adj[v][i]])
			DFS(adj[v][i], st);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < m;++i) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1;i <= n;++i) {
		fill(vis + 1, vis + 1 + max_n, false);
		DFS(i, i);
	}
	for (int i = 1;i <= n;++i) {
		if (count(know[i] + 1, know[i] + 1 + n, true) == n)
			++sum;
	}
	cout << sum;
	return 0;
}
