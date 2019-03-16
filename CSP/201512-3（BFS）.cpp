#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;
constexpr int max_n = 105;
char table[max_n][max_n] = {'.'}; 
bool vis[max_n][max_n] = {0}; 
bool v[max_n][max_n] = {0};
int m = 0;
int n = 0;
int q = 0;
int mov_x[] = {0, 0, 1, -1};
int mov_y[] = {1, -1, 0, 0};
struct Point {
	int x = -1;
	int y = -1;
	Point(int x_, int y_) : x(x_), y(y_) {
		
	}
};
bool IsOk(const int &x, const int &y) {
	if (x < 0 || x >= m || y < 0 || y >= n)
		return false;
	if (vis[x][y] == true || v[x][y] == true)
		return false;
	return true;
}
void Clear() {
	for (int i = 0;i < max_n;++i) {
		fill(v[i], v[i] + max_n, false);
	}	
}
void Draw(const int &x, const int &y, char ch) {
	Clear();
	queue<Point> q;
	q.emplace(x, y);
	table[x][y] = ch;
	v[x][y] = true;
	while (!q.empty()) {
		auto top = q.front();
		q.pop();
		for (int i = 0;i < 4;++i) {
			int new_x = top.x + mov_x[i];
			int new_y = top.y + mov_y[i];
			if (IsOk(new_x, new_y)) {
				q.emplace(new_x, new_y);
				v[new_x][new_y] = true;
				table[new_x][new_y] = ch;
			}
		}
	}
}
void Line(const int &x1, const int &y1, const int &x2, const int &y2) {
	char ch = '\0';
	if (x1 == x2) {
		ch = '-';
		int st = min(y1, y2);
		int ed = max(y1, y2);
		for (int i = st;i <= ed;++i) {
			if (!vis[x1][i]) {
				table[x1][i] = ch;
				vis[x1][i] = true;
			}
			else {
				if (table[x1][i] == '|') {
					table[x1][i] = '+';
				}
			}
		}
	}
	else {
		ch = '|';
		int st = min(x1, x2);
		int ed = max(x1, x2);
		for (int i = st;i <= ed;++i) {
			if (!vis[i][y1]) {
				table[i][y1] = ch;
				vis[i][y1] = true;
			}
			else {
				if (table[i][y1] == '-') {
					table[i][y1] = '+';
				}
			}
		}	
	}
}
int main() {
	for (int i = 0;i < max_n;++i) {
		fill(table[i], table[i] + max_n, '.');
	}
	cin >> n >> m >> q;
	for (int i = 0;i < q;++i) {
		int flag = -1;
		cin >> flag;
		if (flag) {
			int x = 0;
			int y = 0;
			char ch = '\0';
			cin >> x >> y >> ch;
			swap(x, y);
			x = m - 1 - x;
			Draw(x, y, ch);
		}
		else {
			int x1 = 0;
			int y1 = 0;
			int x2 = 0;
			int y2 = 0;
			cin >> x1 >> y1 >> x2 >> y2;
			swap(x1, y1);
			swap(x2, y2); 
			x1 = m - 1 - x1;
			x2 = m - 1 - x2;
			Line(x1, y1, x2, y2);
		}
	} 
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			cout << table[i][j];
		}
		cout << "\n";
	}
	return 0;
}
