#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int u = 0;
	int v = 0;
	int dis = 0;
	Edge(int a, int b, int c) : u(a), v(b), dis(c) {
		
	}
	bool operator < (const Edge &rhs) const {
		return this->dis > rhs.dis;
	}
};
constexpr int max_n = 50005;
int father[max_n] = {0};
int n = 0;
int m = 0;
void Init() {
	for (int i = 1;i <= n;++i) {
		father[i] = i;
	}
}
int FindFather(int x) {
	auto a = x;
	while (x != father[x]) {
		x = father[x];
	}
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
priority_queue<Edge> q;
int ans = 0;
int Kruskal(int n, int m) {
	Init();
	while (!q.empty()) {
		Edge e = q.top();
		q.pop();
		int u = FindFather(e.u);
		int v = FindFather(e.v);
		if (u != v) {
			father[u] = v;
			ans = max(ans, e.dis);
		}
	}
}
int main() {
	int root = 0; 
	cin >> n >> m >> root;
	for (int i = 0;i < m;++i) {
		int x = 0;
		int y = 0;
		int d = 0;
		cin >> x >> y >> d;
		q.emplace(x, y, d);		
	}
	Kruskal(1, n);
	cout << ans;
} 
