#include <iostream>
#include <climits>
#include <queue>
using namespace std;
constexpr int max_n = 500;
int n = 0;
int m = 0;
int t = 0;
bool vis[max_n][max_n][max_n] = {0};
int x_dir[] = {1, -1, 0, 0};
int y_dir[] = {0, 0, 1, -1};
int min_dis = INT_MAX;
struct Node {
	int x = -1;
	int y = -1;
	int dis = -1;
	Node(int a, int b, int c) : x(a), y(b), dis(c) {
		
	}
};
bool Judge(const int &x, const int &y, const int &dis) {
	if (x < 1 || x > n || y < 1 || y > m) {
		return false;
	}
	if (vis[x][y][dis]) {
		return false;
	}
	return true;
}
void BFS(const int &x, const int &y, const int &dis) {
	queue<Node> q;
	q.emplace(x, y, dis);
	vis[x][y][dis] = true;
	while (!q.empty()) {
		auto top = q.front();
		q.pop();
		if (top.x == n && top.y == m) {
			if (top.dis < min_dis) {
				min_dis = top.dis;
				return ;
			}
		}
		for (int i = 0;i < 4;++i) {
			int new_x = top.x + x_dir[i]; 
			int new_y = top.y + y_dir[i];
			if (Judge(new_x, new_y, top.dis + 1)) {
				vis[new_x][new_y][top.dis + 1] = true;
				q.emplace(new_x, new_y, top.dis + 1);
			}
		}
	}
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0;i < t;++i) {
		int x = 0;
		int y = 0;
		int a = 0;
		int b = 0;
		cin >> x >> y >> a >> b;
		for (int j = a;j <= b;++j) {
			vis[x][y][j] = true;
		}
	}
	BFS(1, 1, 0);
	cout << min_dis;
	return 0;
}
