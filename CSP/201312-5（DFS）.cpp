#include <iostream>
using namespace std;
constexpr int max_n = 55;
char table[max_n][max_n] = {'\0'}; 
int x_dir[] = {0, 0, 1, -1};
int y_dir[] = {1, -1, 0, 0};
int r = 0;
int c = 0;
bool vis[max_n][max_n] = {0};
int target_x = -1;
int target_y = -1;
bool Judge(const int &x, const int &y) {
	if (x < 0 || x >= r || y < 0 || y >= c) {
		return false;
	}
	if (vis[x][y] || table[x][y] == '#') {
		return false;
	}
	return true;
}
int f = 0;
int flag = 0;
int se = -1;
void Clear() {
	for (int i = 0;i < max_n;++i)
		fill(vis[i], vis[i] + max_n, false);
}
void DFS(const int &x, const int &y) {
	if (x == target_x && y == target_y && se == 1) {
		flag = 1;
		return ;
	}
	vis[x][y] = true;
	switch(table[x][y]) {
		case '+': {
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '-': {
			for (int i = 0;i < 2;++i) {
				int new_x = x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '|': {
			for (int i = 2;i < 4;++i) {
				int new_x = x + x_dir[i];
				int new_y = y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '.': {
			int new_x = x + 1;
			int new_y = y;
			if (Judge(new_x, new_y)) {
				DFS(new_x, new_y);
			}
			break;
		}
		case 'S': {
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case 'T': {
			f = 1;
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
	}
}
void DFS2 (const int &x, const int &y) {
	vis[x][y] = true;
	switch(table[x][y]) {
		case '+': {
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '-': {
			for (int i = 0;i < 2;++i) {
				int new_x = x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '|': {
			for (int i = 2;i < 4;++i) {
				int new_x = x + x_dir[i];
				int new_y = y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case '.': {
			int new_x = x + 1;
			int new_y = y;
			if (Judge(new_x, new_y)) {
				DFS(new_x, new_y);
			}
			break;
		}
		case 'S': {
			f = 1;
			return ;
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
		case 'T': {
			f = 1;
			return ;
			for (int i = 0;i < 4;++i) {
				int new_x = x_dir[i] + x;
				int new_y = y_dir[i] + y;
				if (Judge(new_x, new_y)) {
					DFS(new_x, new_y);
				}
			}
			break;
		}
	}
}
int main() {
	cin >> r >> c;
	int st_x = -1;
	int st_y = -1;
	for (int i = 0;i < r;++i) {
		for (int j = 0;j < c;++j) {
			char ch = '\0';
			cin >> ch;
			if (ch == 'S') {
				st_x = i;
				st_y = j;
			}
			table[i][j] = ch;
		}
	}
	DFS(st_x, st_y);
	if (!f) {
		cout << "I'm stuck!";
		return 0;
	}
	f = 0;
	int count = 0;
	for (int i = 0;i < r;++i) {
		for (int j = 0;j < c;++j) {
			Clear();
			f = 0;
			DFS2(i, j);
			if (!f) {
				Clear();
				target_x = i;
				target_y = j;
				se = 1;
				flag = 0;
				DFS(st_x, st_y);
				if (flag) {
					++count;
				}
			}
		}
	}
	cout << count;
	return 0;
}
