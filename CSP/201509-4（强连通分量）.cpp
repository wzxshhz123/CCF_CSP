#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int mx = 10005;
vector<int>G[mx];
stack<int>s;
int pre[mx],low[mx],dfn,cnt,sccno[mx];
int n;
int m;
int in_deg[mx],out_deg[mx];
void init() {
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(sccno,0,sizeof(sccno));
	memset(in_deg,0,sizeof(in_deg));
	memset(out_deg,0,sizeof(out_deg));
	dfn = cnt = 0;
	for(int i = 1; i <= n; i++) {
		G[i].clear();
	}
}
long long ans = 0;;
void dfs(int u) {
	pre[u] = low[u] = ++dfn;
	s.push(u);
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!pre[v]) {
			dfs(v);
			low[u] = min(low[u],low[v]);
		} else if(!sccno[v])
			low[u] = min(low[u],pre[v]);
	}
	if(pre[u] == low[u]) {
		++cnt;
		int sum = 0;
		while(1) {
			int x = s.top();
			s.pop();
			++sum;
			sccno[x] = cnt;
			if(x == u) break;
		}
		ans += (sum * (sum - 1)) / 2;
	}
}
void solve() {
	for(int i = 1; i <= n; i++)
		if(!pre[i])
			dfs(i);
}
int main() {
	cin >> n >> m;
	init();
	for(int i = 1; i <= m; ++i) {
		int x = -1;
		int y = -1;
		cin >> x >> y;
		G[x].push_back(y);
	}
	solve();
	cout << ans;
	return 0;
}

