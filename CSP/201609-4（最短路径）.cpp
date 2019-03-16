#include <iostream>
#include <vector>
#include <climits>
using namespace std;
constexpr int max_n = 10005;
struct Node {
	int v = -1;
	int w = -1;
	Node(int a, int b) : v(a), w(b) {
		
	}
};
vector<Node> adj[max_n];
int d[max_n] = {0};
int cost[max_n] = {0};
bool vis[max_n] = {0};
int n = 0;
int m = 0;
long long res = 0;
void Dis(int s) {
	fill(d, d + max_n, INT_MAX);
	d[s] = 0;
	for (int i = 0;i < n;++i) {
		int u = -1;
		int min = INT_MAX; 
		for (int j = 1;j <= n;++j) {
			if (!vis[j] && d[j] < min) {
				u = j;
				min = d[j]; 
			}
		}
		if (u == -1)
			return ;
		vis[u] = true;
		res += cost[u];
		for (int j = 0;j < adj[u].size();++j) {
			int v = adj[u][j].v;
			if (!vis[v]) {
				if (d[v] > d[u] + adj[u][j].w) {
					d[v] = d[u] + adj[u][j].w;
					cost[v] = adj[u][j].w;
				}
				else if (d[v] == d[u] + adj[u][j].w && cost[v] > adj[u][j].w) {
					d[v] = d[u] + adj[u][j].w;
					cost[v] = adj[u][j].w;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < m;++i) {
		int x = 0;
		int y = 0;
		int w = 0;
		cin >> x >> y >> w;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}
	Dis(1);
	cout << res;
	return 0;
} 
