#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
constexpr int max_n = 205;
vector<pair<long long, long long>> vec;
vector<long long> adj[max_n + max_n];
int n = 0;
int k = 0;
int m = 0;
long long r = 0;
int d[max_n][max_n];
struct Node {
	int p = -1;  // 编号 
	int d = -1;  // 距离 
	int k = -1;  // 经过新增路由器数量 
	Node(int a,int b,int c) : p(a), d(b), k(c) {
		
	}
	bool operator < (const Node &u) const	{
		return d > u.d;
	}
};
void Init() {
	for (int i = 0;i < max_n;++i) {
		fill(d[i], d[i] + max_n, INT_MAX);
	}
}
void Djs() {
  priority_queue<Node> q; 
  Init();
	fill(d[0], d[0] + max_n, 0);
	q.push(Node(0, 0, 0));
	while(!q.empty())	{
		auto u = q.top();
		q.pop();
		for(int i = 0;i < adj[u.p].size();++i)	{
			int v = adj[u.p][i];
			int vd = u.d + 1;
			int vk = u.k;
			if(v >= n) {
				++vk;
			} 
			if(vk > k)  continue; 
			if(d[v][vk] > vd) {
				d[v][vk] = vd;
				q.push(Node(v, vd, vk));
			}
		}
	}
}
int main() {
  cin >> n >> m >> k >> r;
  for (int i = 0;i < n;++i) {
    long long x = -1;
    long long y = -1;
    cin >> x >> y;
    vec.emplace_back(x, y);
  }
  for (int i = 0;i < m;++i) {
    long long x = -1;
    long long y = -1;
    cin >> x >> y;
    vec.emplace_back(x, y);
  }
  for (int i = 0;i < n + m;++i) {
    for (int j = i + 1;j < n + m;++j) {
      if (sqrt(pow(vec[j].first - vec[i].first, 2) + pow(vec[j].second - vec[i].second, 2)) <= r) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  Djs();
  auto res = min_element(d[1], d[1] + max_n);
  cout << *res - 1;
  return 0;
}
