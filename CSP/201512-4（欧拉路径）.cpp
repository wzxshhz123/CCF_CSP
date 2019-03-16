#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int max_n = 10005;
vector<int> adj[max_n];
bool vis[max_n][max_n] = {0};
int n = 0;
int m = 0;
void Init() {
	for (int i = 1;i <= n;++i) {
		sort(adj[i].begin(), adj[i].end());
	}
}
vector<int> path;
void DFS() {
	Init();
	stack<int> s;
	s.push(1);
	while (!s.empty()) {
		int top = s.top();
		int i = 0;
		for (;i < adj[top].size();++i) {
			int v = adj[top][i];
			if (!vis[top][v]) {
				vis[top][v] = true;
				vis[v][top] = true;
				s.push(v);
				break;
			}
		}
		if (i == adj[top].size()) {
			path.push_back(top);
			s.pop();
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0;i < m;++i) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS();
	auto Judge = [](const vector<int> &rhs) {
		return rhs.size() % 2 == 1; 
	};
	int k = count_if(adj + 1, adj + 1 + max_n, Judge);
	if (path.size() == m + 1 && (k == 0 || k == 2)) {
		for (auto rit = path.rbegin();rit != path.rend();++rit) {
			cout << *rit << " ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}
