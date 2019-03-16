#include <iostream>
#include <queue>
using namespace std;
int x_dir[] = {-1, 0, 1, 0};
int y_dir[] = {0, 1, 0, -1};
constexpr int max_n = 1005;
int n = 0;
int m = 0;
int k = 0;
int d = 0;
struct Node {
	int x = 0;
	int y = 0;
	long long cost = 0;
	Node(int a, int b, long long c = 0) : x(a), y(b), cost(c) {
		
	}
}; 
queue<Node> q;
bool vis[max_n][max_n] = {0};
int table[max_n][max_n] = {0};
bool Judge(const int &x, const int &y) {
	if (x <= 0 || x > n || y <= 0 || y > n) {
		return false;
	}
	if (vis[x][y] || table[x][y] < 0) {
		return false;
	}
	return true;
}
long long ans = 0;
void BFS() {
	while(!q.empty()) {
		auto top = q.front();
		q.pop(); 
		if (table[top.x][top.y] > 0) {
			ans += top.cost * table[top.x][top.y];
		}
		for (int i = 0;i < 4;++i) {
			int new_x = top.x + x_dir[i];
			int new_y = top.y + y_dir[i];
			if (Judge(new_x, new_y)) {
				q.emplace(new_x, new_y, top.cost + 1);
				vis[new_x][new_y] = true;
			}
		}
	}	
}
int main() {
	cin >> n >> m >> k >> d;
	for (int i = 0;i < m;++i) {
		int x = -1;
		int y = -1;
		cin >> x >> y;
		q.emplace(x, y);
		vis[x][y] = true;
	}
	for (int i = 0;i < k;++i) {
		int x = -1;
		int y = -1;
		int c = -1;
		cin >> x >> y >> c;
		table[x][y] += c;
	}
	for (int i = 0;i < d;++i) {
		int x = -1;
		int y = -1;
		cin >> x >> y;
		table[x][y] = -1;
	}
	BFS(); 
	cout << ans;
	return 0;
}
