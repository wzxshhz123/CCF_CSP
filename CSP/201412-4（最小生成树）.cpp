#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n = 0;
int m = 0;
constexpr int max_n = 2005;
int d[max_n] = {0};
struct Node {
	int v = -1;
	int w = -1;
	Node (int a, int b) : v(a), w(b) {
		
	}
	bool operator < (const Node &rhs) const {
		return this->w > rhs.w;
	} 
};
vector<Node> adj[max_n];
bool vis[max_n] = {0};
long long ans = 0;
void Prim() {
	for (int i = 1;i <= n;++i) {
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
		ans += d[u];
		for (int j = 0; j < adj[u].size();++j) {
			int v = adj[u][j].v;
			if (!vis[v] && adj[u][j].w < d[v]) {
				d[v] = adj[u][j].w;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;++i) {
		int a = -1;
		int b = -1;
		int c = -1;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		if (i == 1) {
			fill(d, d + max_n, INT_MAX);
			d[a] = 0;
		}
		adj[b].emplace_back(a, c);
	}
	Prim();
	cout << ans;
	return 0;
}
